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

		//初期化
		void Initialize() override;

		//更新
		void Update() override;

		//描画
		void Draw() override;

		//開放
		void Release() override;

	
};

