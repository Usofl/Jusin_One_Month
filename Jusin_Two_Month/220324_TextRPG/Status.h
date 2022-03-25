#pragma once

class CStatus
{
public:
	CStatus();
	~CStatus();

	void Init_Stat(const char* _cName, const int& _iAttack_Point, const int& _iHP);
	void Damage_Process(const int& _iDamage);
	void Set_Lest_HP(const int& _iHP);
	void Render() const;

	const int& Get_Attack_Point();
	const int& Get_Max_HP();
	const int& Get_Lest_HP();

private:
	char m_cName[20];

	int m_iAttack_Point;
	int m_iMax_HP;
	int m_iLest_HP;
};