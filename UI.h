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
	int hUI_; //�摜
	int hNumbers_; //����
	Transform tHud_;
	std::vector<Transform> tNumbers_;


	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

};

