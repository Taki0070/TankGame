#include "Enemy.h"
#include"Engine/Model.h"
#include "Engine/Collider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent , "Enemy"),hModel_(-1)
{

}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model\\kinoko.fbx");
	assert(hModel_ >= 0);

	Model::SetAnimFrame(1, 10, 5, 1.0);
	SphereCollider* collision = new SphereCollider({ 0, 0, 0 }, 1.0f);
	AddCollider(collision);
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet") {
		this->KillMe();
		pTarget->KillMe();
	}
}
