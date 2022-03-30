#pragma once

class CStatus abstract
{
public:
	CStatus();
	virtual ~CStatus();

	virtual void Initialize(const int& _iChoice) = 0;

	virtual void Render() = 0;

	void Set_Name(const char* _szName);
	void Set_Attack(const int& _iAttack);
	void Set_Max_HP(const int& _iMaxHP);
	void Set_Lest_HP(const int& _iLestHP);
	void Set_Money(const int& _iMoney);
	void Set_Exp(const int& _iExp);

	const char* Get_Name();
	const int& Get_Attack();
	const int& Get_Max_HP();
	const int& Get_Lest_HP();
	const int& Get_Money();
	const int& Get_Exp();

private:
	char m_szName[20];
	int m_iAttack_Point;
	int m_iMax_HP;
	int m_iLest_HP;
	int m_iMoney;
	int m_iExp;
};