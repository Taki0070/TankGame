#include "PLAY_SCENE.h"
#include "Engine/Image.h"
#include "Engine/Model.h"
#include"Tank.h"
#include"TankHead.h"
#include"Ground.h"


PLAY_SCENE::PLAY_SCENE(GameObject* parent)
	:GameObject(parent,"PLAY_SCENE"), hModel_(-1)
{


}

void PLAY_SCENE::Initialize()
{
	Instantiate<Ground>(this);
	Instantiate<Tank>(this);
	//Instantiate<TankHead>(this);
}

void PLAY_SCENE::Update()
{
}

void PLAY_SCENE::Draw()
{
	


}

void PLAY_SCENE::Release()
{
}
