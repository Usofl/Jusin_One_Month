#pragma once

class CStatus
{
public:
	CStatus();
	~CStatus();

	void Render();
	void Damage(const int& _iAttack);
	void Init_Stat(const char * _cName, const int& _iAttack, const int& _iHP, const int& _iExp, const int& _iMoney);

	void Set_Lest_HP(const int& _HP);
	void Set_Max_HP(const int& _HP);
	void Set_Attack_Point(const int& _Attack);
	void Set_Money(const int& _iMoney);
	void Set_Exp(const int& _iExp);

	void Plus_Exp(const int& _iExp);

	const char* Get_Name();
	const int& Get_Attack_Point();
	const int& Get_Lest_HP();
	const int& Get_Max_HP();
	const int& Get_Exp();
	const int& Get_Money();

private:
	char m_cName[20];
	int m_iAttack_Point;
	int m_iMax_HP;
	int m_iLest_HP;
	int m_iExp;
	int m_iMoney;
};