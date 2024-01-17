#include "Tank.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Debug.h"
#include"Ground.h"
#include"TankHead.h"

Tank::Tank(GameObject* parent)
	:GameObject(parent), hModel_(-1)
{

}

void Tank::Initialize()
{
	hModel_ = Model::Load("Model\\tankbody.fbx");
	assert(hModel_ >= 0);
	speed_ = 0.05;
	front_ = XMVECTOR({ 0,0,1,0 }); //�ړ����ς��y �J���} ,
	Instantiate<TankHead>(this); //�e�q�֌W���ł���
}

void Tank::Update()
{
	
	if (Input::IsKey(DIK_W))
	{
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		XMVECTOR rotVec = XMVector3TransformCoord(front_, rotY);

		XMVECTOR move;
		move = speed_ * rotVec;  //speed_ * front_;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos + move;
		XMStoreFloat3(&(transform_.position_), pos);

	}
	if (Input::IsKey(DIK_S))
	{
		XMMATRIX rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		XMVECTOR rotVec = XMVector3TransformCoord(front_, rotY);

		XMVECTOR move;
		move = speed_ * rotVec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos - move;
		XMStoreFloat3(&(transform_.position_), pos);

	}
	if (Input::IsKey(DIK_A))
	{
		this->transform_.rotate_.y -= 2;
	}
	if (Input::IsKey(DIK_D))
	{
		this->transform_.rotate_.y += 2;
	}
	

	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle(); //�����̃��f������n�ʂ܂ł̋�����������

	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);// �����̃f�[�^�Ƃ��A���ł���

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist;// 0�̈ʒu���烌�C���Ƃ΂��@�i�}�b�v��0��艺������
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
