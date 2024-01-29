#pragma once
#include"Engine/GameObject.h"
class TankHead :
    public GameObject
{
	//ok
public:
	int hModel_;
	XMVECTOR front_;
	float speed_;

public:

	TankHead(GameObject* parent);
	~TankHead();

	void Initialize() override;


	void Update() override;


	void Draw() override;


	void Release() override;
	/// <summary> 要約
	/// モデル番号を返す関数
	/// </summary>
	/// <returns>モデル番号</returns>
	int GetModelHandle() { return hModel_; }//　モデル番号を返す



};

