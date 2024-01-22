#include "PLAY_SCENE.h"
#include "Engine/Image.h"
#include "Engine/Model.h"
#include"Tank.h"
#include"TankHead.h"
#include"Ground.h"
#include"Enemy.h"
#include"Engine/Camera.h"

int enemyNum{ 20 };

PLAY_SCENE::PLAY_SCENE(GameObject* parent)
	:GameObject(parent,"PLAY_SCENE")
{


}

void PLAY_SCENE::Initialize()
{
	Instantiate<Ground>(this);
	//Instantiate<Tank>(this);
	player = Instantiate<Tank>(this);
	
	
	//Instantiate<TankHead>(this);
	for(int i=0;i<enemyNum;i++)
	Instantiate<Enemy>(this);

	
	
}

void PLAY_SCENE::Update()
{
	//ここエラー
	/*Camera::SetTarget(player->GetPosition());
	XMFLOAT3 camPos = player->GetPosition();
	camPos.y += 8;
	camPos.z -= 15;
	Camera::SetPosition(camPos);*/
}

void PLAY_SCENE::Draw()
{
	
	//pText->Draw(30, 30, "naaa");

}

void PLAY_SCENE::Release()
{
}
