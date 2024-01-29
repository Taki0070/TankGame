#include "Enemy.h"
#include"Engine/Model.h"
#include "Engine/Collider.h"
#include"Ground.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent , "Enemy"),hModel_(-1)
{

}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model\\enemy2.fbx");
	assert(hModel_ >= 0);
	SphereCollider* collision = new SphereCollider({ 0, 0, 0 }, 1.0f);
	AddCollider(collision);

	Model::SetAnimFrame(hModel_, 0, 60, 1);
	float x = (float)rand() / RAND_MAX;
	
	x = 2.0 - x;
	transform_.position_.x = 25.0 * (x - 1.0);
	float z = (float)rand() / RAND_MAX;
	z = 2.0 * z;
	transform_.position_.z = 10.0 * (z * 1.0); // 元25.0
	transform_.position_.y = 0;

	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();
	RayCastData data;
	data.start = transform_.position_;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist;// 0の位置からレイをとばす　（マップは0より下だから
	}



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
	this->KillMe();
}
