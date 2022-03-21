#pragma once

class CMonster
{
private:
	char m_MonsterName[20];

	int m_Attack_Point;
	int m_Max_HP;
	int m_Lest_HP;
public:
	void Init_Monster(int _Level);
	void Print_Monster_Info();

	void Set_Monster_Name(char* _cMonsterName);
	void Set_Attack_Point(int _AttackPoint);
	void Set_Max_HP(int _HP);
	void Set_Lest_HP(int _HP);

	const char* Get_Monster_Name();
	const int Get_Attack_Point();
	const int Get_Max_HP();
	const int Get_Lest_HP();
};