#pragma once
#include"Engine/GameObject.h"

class PLAY_SCENE
	:public GameObject
{
private:
	int hModel_;
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