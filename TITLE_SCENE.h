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

		//‰Šú‰»
		void Initialize() override;

		//XV
		void Update() override;

		//•`‰æ
		void Draw() override;

		//ŠJ•ú
		void Release() override;

	
};

