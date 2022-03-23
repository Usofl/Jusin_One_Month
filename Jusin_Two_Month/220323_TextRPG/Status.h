#pragma once

class CStat
{
public:
	CStat();
	~CStat();

	void Set_Status(char* _cName, int _iAttack_Point, int _iMax_HP);
	void Set_Damage(int _iAttack_Point);
	void Rander();

	const int Get_Attack_Point();
	void Set_Lest_Max_HP();
	const int Get_Lest_HP();

private:
	char m_Name[20];
	int m_iAttack_Point;
	int m_iMax_HP;
	int m_iLest_HP;
};