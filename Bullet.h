#pragma once
#include"Engine/GameObject.h"
class PlayScene;

class Bullet
	: public GameObject
{

private:
	int hModel_;
	float bulletSpeed; // ’eŠÛ‚Ì‘¬‚³
	XMFLOAT3 moveDir_; // Œü‚«
	// PlayScene playerScene;
public:
	Bullet(GameObject* parent);
	~Bullet();

	void Onllision(GameObject* pTarget);
	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
	void SetMoveDir(XMFLOAT3 _move) { moveDir_ = _move; }
	void SetSpeed(float _speed) { bulletSpeed = _speed; }
	


};


