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
	/// <summary> �v��
	/// ���f���ԍ���Ԃ��֐�
	/// </summary>
	/// <returns>���f���ԍ�</returns>
	int GetModelHandle() { return hModel_; }//�@���f���ԍ���Ԃ�



};

