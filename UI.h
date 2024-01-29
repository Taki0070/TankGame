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
	int hUI_; //‰æ‘œ
	int hNumbers_; //”š
	Transform tHud_;
	std::vector<Transform> tNumbers_;


	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

};

