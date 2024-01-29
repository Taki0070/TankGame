#include "Bullet.h"
#include"Engine/Model.h"
#include"PLAY_SCENE.h"
#include"Enemy.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent,"Bullet"),hModel_(-1)
{

}

Bullet::~Bullet()
{
}

void Bullet::Onllision(GameObject* pTarget)
{
	
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Model\\Bullet.fbx");
	assert(hModel_ >= 0);

	SphereCollider* collision = new SphereCollider({ 0,0,0 }, 0.5f);
	AddCollider(collision);

}

void Bullet::Update()
{
	transform_.position_.x = transform_.position_.x + moveDir_.x * bulletSpeed;
	transform_.position_.y = transform_.position_.y + moveDir_.y * bulletSpeed;
	transform_.position_.z = transform_.position_.z + moveDir_.z * bulletSpeed;
	transform_.position_.z += 0.1;

	

	moveDir_ = { moveDir_.x,moveDir_.y - 0.017f,moveDir_.z };

	if (transform_.position_.z <-10) {
		KillMe();
	}

}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
