#pragma once
#include"Engine/GameObject.h"

class Tank
	:public GameObject
{
private:
	int hModel_;
	XMVECTOR front_; // 前ベクトル z方向の大きさ
	float speed_; //0.05,0,05*60 m/s

	XMFLOAT3 f;	//何か入ってるとして
	XMVECTOR v = XMLoadFloat3(&f);
	
public:
	Tank(GameObject* parent);


	void Initialize() override;

	
	void Update() override;

	
	void Draw() override;


	void Release() override;
	void OnCollision(GameObject* eTarget);
};

