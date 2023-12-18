#include "Tank.h"
#include"Engine/Model.h"
#include"Engine/Input.h"

Tank::Tank(GameObject* parent)
	:GameObject(parent),hModel_(-1)
{

}

void Tank::Initialize()
{
	hModel_ = Model::Load("Model\\tankbody.fbx");
	assert(hModel_ >= 0);
}

void Tank::Update()
{
	if (Input::IsKey(DIK_A))
	{
		this->transform_.rotate_.y -= 2;
	}
	if (Input::IsKey(DIK_D))
	{
		this->transform_.rotate_.y += 2;
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
