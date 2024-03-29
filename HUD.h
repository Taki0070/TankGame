#pragma once
#include "Engine/GameObject.h"
#include <vector>
#include <string>

using std::string;

class HUD :
	public GameObject
{
	string ConstructEnemyNumberString();
public:
	
	HUD(GameObject* parent);
	int hHUD_;//
	int hNumbers_;//数字
	Transform tHud_;
	
	std::vector<Transform> tNumbers_;
	//Transform tNumbers[3];
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;


};
