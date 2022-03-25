#pragma once

class CStatus
{
public:
	CStatus();
	~CStatus();

	void Init_Stat(const char* _cName, const int& _iAttack, const int& _iHP);

	void Render() const;

	int Get_Lest_HP() const;
	int Get_Max_HP() const;
	int Get_Attack_Point() const;

	void Set_Lest_HP(const int& _iHP);
	void Set_Max_HP(const int& _iHP);
	void Set_Attack_Point(const int& _Attack_Point);

private:
	char m_cName[20];
	int m_iAttack_Point;
	int m_iLest_HP;
	int m_iMax_HP;
};