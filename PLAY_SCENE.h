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

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

};