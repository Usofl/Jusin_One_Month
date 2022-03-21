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

	void Print_Player_Info();

	void Set_Nick_Name(char* _cNickName);
	void Set_Class(char* _cClass);
	void Set_Attack_Point(int _AttackPoint);
	void Set_Max_HP(int _HP);
	void Set_Lest_HP(int _HP);
	
	const char* Get_Class();
	const char* Get_Nick_Name();
	const int Get_Attack_Point();
	const int Get_Max_HP();
	const int Get_Lest_HP();
};