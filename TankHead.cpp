#include "TankHead.h"
#include"Engine/Model.h"
#include"Engine/Input.h"

TankHead::TankHead(GameObject* parent)
	:GameObject(parent, "TankHead"), hModel_(-1)
{

}

TankHead::~TankHead()
{
}

void TankHead::Initialize()
{
	hModel_ = Model::Load("Model\\tankhed2.fbx");
	assert(hModel_>= 0);
}

void TankHead::Update()
{
	if (Input::IsKey(DIK_P))
	{
		this->transform_.rotate_.y -= 2;
	}
	if (Input::IsKey(DIK_O))
	{
		this->transform_.rotate_.y += 2;
	}
#if 0
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
#endif


}
void TankHead::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);//ªƒZƒbƒg‚µ‚½‚çDraw‚ğ‚©‚­

}

void TankHead::Release()
{
	
}
