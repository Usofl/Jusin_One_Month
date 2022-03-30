#include "stdafx.h"
#include "Status.h"

CStatus::CStatus()
	: m_iAttack_Point(0)
	, m_iMax_HP(0)
	, m_iLest_HP(0)
{
	memset(m_szName, 0, sizeof(m_szName));
}
CStatus::~CStatus()
{

}

void CStatus::Render()
{

}

void CStatus::Init_Stat(const int& _iChoice)
{
	cout << "이름 : " << m_szName << endl;
	cout << "공격력 : " << m_iAttack_Point << endl;
	cout << "체력 : <" << m_iLest_HP << " / " << m_iMax_HP << ">" << endl;
	cout << "=================================================" << endl;
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