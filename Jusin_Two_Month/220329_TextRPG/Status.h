#pragma once

class CStatus
{
public:
	CStatus();
	~CStatus();

	virtual void Render();
	
	virtual void Init_Stat(const int& _iChoice);

	void Set_Name(const char* _szName);
	void Set_Attack(const int& _iAttack);
	void Set_Max_HP(const int& _iMaxHP);
	void Set_Lest_HP(const int& _iLestHP);

	const char* Get_Name();
	const int& Get_Attack();
	const int& Get_Max_HP();
	const int& Get_Lest_HP();
private:
	char m_szName[20];
	int m_iAttack_Point;
	int m_iMax_HP;
	int m_iLest_HP;
};