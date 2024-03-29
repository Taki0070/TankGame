#pragma once
#include"Engine/GameObject.h"
#include<vector>
#include<string>

using std::string;

class UI
	:public GameObject
{
	string ConstructEnemyNumberString();
public:
	UI(GameObject* parent);
	int hUI_; //画像
	int hNumbers_; //数字
	Transform tHud_;
	std::vector<Transform> tNumbers_;


	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

};

