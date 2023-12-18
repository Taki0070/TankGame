#include "Ground.h"
#include"Engine/Model.h"

Ground::Ground(GameObject* parent)
	:GameObject(parent),hModel_(-1)
{
}

void Ground::Initialize()
{
	hModel_ = Model::Load("Model\\Groond2.fbx");
	assert(hModel_ >= 0);
}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model ::SetTransform(hModel_, transform_);
	Model ::Draw(hModel_);
}

void Ground::Release()
{
}
