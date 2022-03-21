#pragma once

class CPlayer
{
private:
	char m_Class[10];
	char m_NickName[20];
	
	int m_Attack_Point;
	int m_Max_HP;
	int m_Lest_HP;
public:
	bool Init_Player();

	void Set_Attack_Point(int _AttackPoint);
	void Set_Max_HP(int _HP);
	void Set_Lest_HP(int _HP);

	const int Get_Attack_Point();
	const int Get_Max_HP();
	const int Get_Lest_HP();
};