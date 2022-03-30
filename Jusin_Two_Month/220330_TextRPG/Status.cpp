#include "stdafx.h"
#include "Status.h"

CStatus::CStatus()
	: m_iAttack_Point(0)
	, m_iMax_HP(0)
	, m_iLest_HP(0)
	, m_iMoney(0)
	, m_iExp(0)
{
	memset(m_szName, 0, sizeof(m_szName));
}

CStatus::~CStatus()
{

}

void CStatus::Set_Name(const char* _szName)
{
	strcpy_s(m_szName, sizeof(m_szName), _szName);
}

void CStatus::Set_Attack(const int& _iAttack)
{
	m_iAttack_Point = _iAttack;
}

void CStatus::Set_Max_HP(const int& _iMaxHP)
{
	m_iMax_HP = _iMaxHP;
}

void CStatus::Set_Lest_HP(const int& _iLestHP)
{
	m_iLest_HP = _iLestHP;
}

void CStatus::Set_Money(const int& _iMoney)
{
	m_iMoney = _iMoney;
}

void CStatus::Set_Exp(const int& _iExp)
{
	m_iExp = _iExp;
}

const char* CStatus::Get_Name()
{
	return m_szName;
}

const int& CStatus::Get_Attack()
{
	return m_iAttack_Point;
}

const int& CStatus::Get_Max_HP()
{
	return m_iMax_HP;
}

const int& CStatus::Get_Lest_HP()
{
	return m_iLest_HP;
}

const int& CStatus::Get_Money()
{
	return m_iMoney;
}

const int& CStatus::Get_Exp()
{
	return m_iExp;
}