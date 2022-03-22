#pragma once
#include "stdafx.h"

class CPlayer
{
private:
	char m_cNick_Name[20];
	char m_cClass[10];

	Status m_Status;

public:
	CPlayer() = delete;

	CPlayer(int _iChoice);
	~CPlayer();

	void Rander();

	void Set_Attack_Point(const int _iAttack_Point);
	void Set_Lest_HP(const int _iHP);
	void Set_Max_HP(const int _iHP);

	const int Get_Attack_Point();
	const int Get_Lest_HP();
	const int Get_Max_HP();
};