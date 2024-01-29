#include "HUD.h"
#include "Engine/Image.h"
#include "PLAY_SCENE.h"


HUD::HUD(GameObject* parent)
	:GameObject(parent, "HUD"), hHUD_(-1), hNumbers_(-1)
{
}

void HUD::Initialize()
{
	hHUD_ = Image::Load("Image\\cou.png");
	assert(hHUD_ >= 0);
	hNumbers_ = Image::Load("Image\\number2.png");
	assert(hHUD_ >= 0);

	//
	//for (int i = 0; i < 3; i++)
	//{
	//	Transform t;
	//	t.position_ = { -0.51f + 0.05f*(float)i, 0.85f, 0.0f };
	//	tNumbers_.push_back(t);
	//}
}


string HUD::ConstructEnemyNumberString()
{
	int enemies = ((PLAY_SCENE*)GetParent())->GetEnemyNum();
	string enemyNumStr = std::to_string(enemies);
	return enemyNumStr;
}


void HUD::Update()
{
	tHud_.scale_ = { 1, 0.5, 1.0 };
	tHud_.position_ = { -0.8, 0.85, 0 };
	
}




void HUD::Draw()
{
	Image::SetTransform(hHUD_, tHud_);
	Image::Draw(hHUD_);

	Transform trans;
	trans.scale_ = { 1, 0.5, 1.0 };
	trans.position_ = { -0.65, 0.887, 0 };

	Image::SetRect(hNumbers_, 50.8 * 5, 0, 50.8, 99);
	Image::SetTransform(hNumbers_, trans);
	Image::Draw(hNumbers_);


	//string estr = ConstructEnemyNumberString();
	//if (estr.size() < 3)
	//	estr = std::string(3 - estr.size(), '0') + estr;
	//for(int i = 0; i < 3; i++) {
	//	int n = estr[i] - '0';
	//	Image::SetRect(hNumbers_, 51.2 *(float)n, 0, 51.2, 60);
	//	Image::SetTransform(hNumbers_, tNumbers_[i]);
	//	Image::Draw(hNumbers_);
	//}
	//Image::SetTransform(hKinoko_, tKinoko_);
	//Image::Draw(hKinoko_);
}


void HUD::Release()
{
}