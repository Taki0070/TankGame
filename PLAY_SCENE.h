#pragma once
#include"Engine/GameObject.h"
class Text;
class Tank;

class PLAY_SCENE
	:public GameObject
{
	Tank* player;
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