#pragma once
#include"Engine/GameObject.h"

class TITLE_SCENE
	:public GameObject
{	
	private:
		int hPict_;
		int hModel_;

	public:
		TITLE_SCENE(GameObject* parent);

		//������
		void Initialize() override;

		//�X�V
		void Update() override;

		//�`��
		void Draw() override;

		//�J��
		void Release() override;

	
};

