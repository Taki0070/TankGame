#include "PLAY_SCENE.h"
#include "Engine/Image.h"
#include "Engine/Model.h"
#include "Engine/Text.h"
#include"Tank.h"
#include"TankHead.h"
#include"Ground.h"
#include"Enemy.h"
#include"UI.h"
#include"HUD.h"
#include"Engine/Camera.h"


int enemyNum{ 20 };
PLAY_SCENE::PLAY_SCENE(GameObject* parent)
	:GameObject(parent,"PLAY_SCENE"),hPict_(-1), pText(nullptr)
{


}

void PLAY_SCENE::Initialize()
{
	Instantiate<Ground>(this);
	player = Instantiate<Tank>(this);
	//Instantiate<TankHead>(this);


	for (int i = 0; i < enemyNum; i++) {
		Instantiate<Enemy>(this);
	}
	


	Instantiate<HUD>(this);
	/*pText = new Text;
	pText->Initialize();*/
}

void PLAY_SCENE::Update()
{
}

void PLAY_SCENE::Draw()
{
	Image::Draw(hPict_);
	//pText->Draw(30, 30, "GAME STATE");

}

void PLAY_SCENE::Release()
{
}

void PLAY_SCENE::DescEnemy()
{
	enemyNum--;
}

bool PLAY_SCENE::IsEnemyLeft()
{
	return enemyNum > 0;
}

int PLAY_SCENE::GetEnemyNum()
{
	return enemyNum;
}
