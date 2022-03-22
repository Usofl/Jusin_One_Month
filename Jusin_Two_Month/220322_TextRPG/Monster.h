#pragma once
#include "stdafx.h"

class CMonster
{
private:
	char m_cName[20];

	Status m_Status;

public:
	CMonster() = delete;

	CMonster(int _iLevel);
	~CMonster();

	void Rander();

	void Set_Attack_Point(const int _iAttack_Point);
	void Set_Lest_HP(const int _iHP);
	void Set_Max_HP(const int _iHP);

	const int Get_Attack_Point();
	const int Get_Lest_HP();
	const int Get_Max_HP();
};