#pragma once
#include"Engine/GameObject.h"
class PlayScene;

class Bullet
	: public GameObject
{

private:
	int hModel_;
	float bulletSpeed; // �e�ۂ̑���
	XMFLOAT3 moveDir_; // ����
	// PlayScene playerScene;
public:
	Bullet(GameObject* parent);
	~Bullet();

	void Onllision(GameObject* pTarget);
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
	void SetMoveDir(XMFLOAT3 _move) { moveDir_ = _move; }
	void SetSpeed(float _speed) { bulletSpeed = _speed; }
	


};


