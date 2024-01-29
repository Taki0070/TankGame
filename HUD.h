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
	int hNumbers_;//”š
	Transform tHud_;
	
	std::vector<Transform> tNumbers_;
	//Transform tNumbers[3];
	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;


};
