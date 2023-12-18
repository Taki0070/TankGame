#pragma once
#include"Engine/GameObject.h"

class Tank
	:public GameObject
{
private:
	int hModel_;
public:
	Tank(GameObject* parent);

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;

};


