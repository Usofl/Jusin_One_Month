#include "stdafx.h"
#include "Status.h"

CStatus::CStatus()
	: m_cName("")
	, m_iAttack_Point(0)
	, m_iMax_HP(0)
	, m_iLest_HP(0)
	, m_iExp(0)
	, m_iMoney(0)
{

}

CStatus::~CStatus()
{

}

void CStatus::Render()
{
	cout << "이름 : " << m_cName << endl;
	cout << "공격력 : " << m_iAttack_Point << endl;
	cout << "체력 : <" << m_iLest_HP << " / " << m_iMax_HP << ">" << endl;
	cout << "=================================================" << endl;
}

void CStatus::Damage(const int& _iAttack)
{
	m_iLest_HP -= _iAttack;
}

void CStatus::Init_Stat(const char * _cName, const int& _iAttack, const int& _iHP, const int& _iExp, const int& _iMoney)
{
	strcpy_s(m_cName, sizeof(m_cName), _cName);
	m_iAttack_Point = _iAttack;
	m_iLest_HP = _iHP;
	m_iMax_HP = _iHP;
	m_iExp = _iExp;
	m_iMoney = _iMoney;
}

void CStatus::Set_Lest_HP(const int& _HP)
{
	m_iLest_HP = _HP;
}

void CStatus::Set_Max_HP(const int& _HP)
{
	m_iMax_HP = _HP;
}

void CStatus::Set_Attack_Point(const int& _Attack)
{
	m_iAttack_Point = _Attack;
}

void CStatus::Set_Money(const int & _iMoney)
{
	m_iMoney = _iMoney;
}

void CStatus::Set_Exp(const int& _iExp)
{
	m_iExp = _iExp;
}

void CStatus::Plus_Exp(const int & _iExp)
{
	m_iExp += _iExp;
}


const char* CStatus::Get_Name()
{
	return m_cName;
}

const int& CStatus::Get_Attack_Point()
{
	return m_iAttack_Point;
}
const int& CStatus::Get_Lest_HP()
{
	return m_iLest_HP;
}

const int& CStatus::Get_Max_HP()
{
	return m_iMax_HP;
}

const int& CStatus::Get_Exp()
{
	return m_iExp;
}

const int& CStatus::Get_Money() 
{
	return m_iMoney;
}