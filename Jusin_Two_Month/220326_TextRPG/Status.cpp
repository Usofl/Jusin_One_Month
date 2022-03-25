#include "stdafx.h"
#include "Status.h"

CStatus::CStatus()
	: m_cName()
	, m_iAttack_Point(0)
	, m_iMax_HP(0)
	, m_iLest_HP(0)
{

}

CStatus::~CStatus()
{

}

void CStatus::Init_Stat(const char* _cName, const int& _iAttack, const int& _iHP)
{
	strcpy_s(m_cName, sizeof(m_cName), _cName);
	m_iAttack_Point = _iAttack;
	m_iMax_HP = _iHP;
	m_iLest_HP = m_iMax_HP;
}

void CStatus::Render() const
{
	cout << "=================================" << endl;
	cout << "이름 : " << m_cName << endl;
	cout << "공격력 : " << m_iAttack_Point << endl;
	cout << "체력 : < " << m_iLest_HP << " / " << m_iMax_HP << " >" << endl;
}

int CStatus::Get_Max_HP() const
{
	return m_iMax_HP;
}

int CStatus::Get_Lest_HP() const
{
	return m_iLest_HP;
}

int CStatus::Get_Attack_Point() const
{
	return m_iAttack_Point;
}

void CStatus::Set_Lest_HP(const int& _iHP)
{
	m_iLest_HP = _iHP;
}

void CStatus::Set_Max_HP(const int & _iHP)
{
	m_iMax_HP = _iHP;
}

void CStatus::Set_Attack_Point(const int & _Attack_Point)
{
	m_iAttack_Point = _Attack_Point;
}
