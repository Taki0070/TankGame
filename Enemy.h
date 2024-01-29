#pragma once
#include"Engine/GameObject.h"


class Enemy
	: public GameObject
{

private:
	int hModel_;

public:
	Enemy(GameObject* parent);
	~Enemy();

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
	void OnCollision(GameObject* pTarget);

};