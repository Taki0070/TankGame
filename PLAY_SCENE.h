#pragma once
#include"Engine/GameObject.h"

class PLAY_SCENE
	:public GameObject
{
private:
	int hModel_;
public:
	PLAY_SCENE(GameObject* parent);

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;

};