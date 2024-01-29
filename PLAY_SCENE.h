#pragma once
#include"Engine/GameObject.h"
#include"Enemy.h"
class Text;
class Tank;


class PLAY_SCENE
	:public GameObject
{
	Tank* player;
	int hPict_;
	Text* pText;
public:
	PLAY_SCENE(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	//　インライン定義
	void DescEnemy();// { enemyNum--; }
	bool IsEnemyLeft();// { return enemyNum > 0; }
	int GetEnemyNum();// { return enemyNum; }

};