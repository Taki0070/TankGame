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

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
	//�@�C�����C����`
	void DescEnemy();// { enemyNum--; }
	bool IsEnemyLeft();// { return enemyNum > 0; }
	int GetEnemyNum();// { return enemyNum; }

};