#pragma once
#include"Engine/GameObject.h"
class PlayScene;

class Bullet
	: public GameObject
{

private:
	int hModel_;
	float bulletSpeed; // 弾丸の速さ
	XMFLOAT3 moveDir_; // 向き
	// PlayScene playerScene;
public:
	Bullet(GameObject* parent);
	~Bullet();

	void Onllision(GameObject* pTarget);
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	void SetMoveDir(XMFLOAT3 _move) { moveDir_ = _move; }
	void SetSpeed(float _speed) { bulletSpeed = _speed; }
	


};


