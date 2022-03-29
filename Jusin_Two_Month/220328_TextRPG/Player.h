#pragma once
#include "Status.h"
#include "Inventory.h"

class CPlayer : public CStatus
{
public:
	CPlayer();
	~CPlayer();

	void Init_Player(int _iChoice);
	void Render_Player();
	void Level_Up_Cheak();

	CInventory* Get_Inventory();
	void Cheak_Wearing();
	void Use_Consum(CConsum* _consum);

private:
	int m_iLevel;
	int m_iMax_Exp;
	int m_iPlus_HP;
	int m_iPlus_Attack;

	CInventory m_Inventory;
};