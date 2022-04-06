#pragma once
#include "Status.h"

class CPlayer : public CStatus
{
public:
	CPlayer();
	~CPlayer();

	virtual void Render();
	virtual void Init_Stat(const int& _iChoice);

private:
	int m_iLevel;
	int m_iMax_Exp;
	int m_iPlus_HP;
	int m_iPlus_Attack;

	CInventory m_Inventory;
};