#include "Tank.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Debug.h"
#include"Ground.h"
#include"TankHead.h"
#include"Engine/Camera.h"

enum CAM_TYPE {
	FIXED_TYPE,
	TPS_NOROT_TYPE,
	TPS_TYPE,
	FPS_TYPE,
	MAX_TYPE,
};

Tank::Tank(GameObject* parent)
	:GameObject(parent, "Tank"), hModel_(-1), speed_(0.05), front_({0.0,1.0}),camState_(CAM_TYPE::FIXED_TYPE)
{

}

void Tank::Initialize()
{
	hModel_ = Model::Load("Model\\tankbody.fbx");
	assert(hModel_ >= 0);
	speed_ = 0.05;
	front_ = XMVECTOR({ 0,0,1,0 }); //移動が変わるy カンマ ,
	Instantiate<TankHead>(this); //親子関係ができる
}

void Tank::Update()
{
	XMMATRIX rotY = XMMatrixIdentity();// 行列の1
	XMVECTOR move{ 0,0,0,0 };
	XMVECTOR rotVec{ 0,0,0,0 };
	float dir = 0;
	if (Input::IsKey(DIK_W))
	{
		//rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	 //   rotVec = XMVector3TransformCoord(front_, rotY);
		//move = speed_ * rotVec;  //speed_ * front_;
		//XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		//pos = pos + move;
		//XMStoreFloat3(&(transform_.position_), pos);
		dir = 1.0;


	}
	if (Input::IsKey(DIK_S))
	{
		/* rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		 rotVec = XMVector3TransformCoord(front_, rotY);*/
		/* move;
		move = speed_ * rotVec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos - move;
		XMStoreFloat3(&(transform_.position_), pos);*/
		dir = -1.0;
	}
	if (Input::IsKey(DIK_A))
	{
		this->transform_.rotate_.y -= 2;
	}
	if (Input::IsKey(DIK_D))
	{
		this->transform_.rotate_.y += 2;
	}

	rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	rotVec = XMVector3TransformCoord(front_, rotY);

	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	pos = pos + dir* move;
	XMStoreFloat3(&(transform_.position_), pos);

	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle(); //自分のモデルから地面までの距離が分かる

	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);// 距離のデータとか、飛んでいく

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist;// 0の位置からレイをとばす　（マップは0より下だから
	}


	if (Input::IsKeyDown(DIK_Z))
	{
		camState_++;
		if (camState_ == CAM_TYPE::MAX_TYPE)
			camState_ = CAM_TYPE::FIXED_TYPE;
	}

	switch (camState_)
	{
	case CAM_TYPE::FIXED_TYPE:
	{
		Camera::SetPosition(XMFLOAT3(0, 20, -20));
		Camera::SetTarget(XMFLOAT3(0, 0, 0));
		break;
	}
	case CAM_TYPE::TPS_NOROT_TYPE:
	{
		XMFLOAT3 camPos = transform_.position_;
		camPos.y += transform_.position_.y + 20.0f;
		camPos.z -= transform_.position_.z - 10.0f;
		Camera::SetPosition(camPos);
		Camera::SetTarget(transform_.position_);
		break;
	}

	case CAM_TYPE::TPS_TYPE:
	{
		Camera::SetTarget(transform_.position_);
		XMVECTOR vEye{ 0,5,-10,0 };
		vEye = XMVector3TransformCoord(vEye, rotY);
		XMFLOAT3 camPos;
		XMStoreFloat3(&camPos, pos + vEye);
		Camera::SetPosition(camPos);
		break;
	}
	case CAM_TYPE::FPS_TYPE:
	{

		/*Camera::SetPosition(transform_.position_);
		XMVECTOR camTarget;
		XMVECTOR vMove  = XMLoadFloat3(&camTarget,pos + dir *move)
		XMStoreFloat3(&camTarget, pos + dir * move);
		Camera::SetTarget(camTarget);*/
		break;
	}
	default:
		break;
	
	}

}

void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Tank::Release()
{
}

void Tank::OnCollision(GameObject* eTarget)
{
	if (eTarget->GetObjectName() == "Enemy")
	{
		this->KillMe();
		eTarget->KillMe();
	}
}
