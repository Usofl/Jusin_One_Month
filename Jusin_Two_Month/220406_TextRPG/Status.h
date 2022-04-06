#pragma once

#include "stdafx.h"

class CStatus abstract
{
public:
	CStatus()
		: m_szName("")
		, m_iAttack_Point(0)
		, m_iMax_HP(0)
		, m_iLest_HP(0)
		, m_iExp(0)
		, m_iMoney(0)
	{

	}
	virtual ~CStatus() {};

	virtual void Render() = 0;
	virtual void Init_Stat(const int& _iChoice) = 0;

	inline void Set_Name(const char* _szName) { strcpy_s(m_szName, sizeof(m_szName), _szName); }
	inline void Set_Attack(const int& _iAttack) { m_iAttack_Point = _iAttack; }
	inline void Set_Max_HP(const int& _iMaxHP) { m_iMax_HP = _iMaxHP; }
	inline void Set_Lest_HP(const int& _iLestHP) { m_iLest_HP = _iLestHP; }
	inline void Set_Exp(const int& _iExp) { m_iExp = _iExp; }
	inline void Set_Money(const int& _iMoney) { m_iMoney = _iMoney; }

	inline const char* Get_Name() { return m_szName; }
	inline const int& Get_Attack() { return m_iAttack_Point; }
	inline const int& Get_Max_HP() { return m_iMax_HP; }
	inline const int& Get_Lest_HP() { return m_iLest_HP; }
	inline const int& Get_Exp() { return m_iExp; }
	inline const int& Get_Money() { return m_iMoney; }

private:
	char m_szName[20];
	int m_iAttack_Point;
	int m_iMax_HP;
	int m_iLest_HP;
	int m_iExp;
	int m_iMoney;
};