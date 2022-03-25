#include "..\220326_TextRPG\Status.h"
#include "..\220326_TextRPG\Status.h"
#include "..\220326_TextRPG\Status.h"
#include "..\220326_TextRPG\Status.h"
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

void CStatus::Init_Stat(const char* _cName, const int& _iAttack_Point, const int& _iHP)
{
	strcpy_s(m_cName, sizeof(m_cName), _cName);
	m_iAttack_Point = _iAttack_Point;
	m_iMax_HP = _iHP;
	m_iLest_HP = m_iMax_HP;
}

void CStatus::Damage_Process(const int& _iDamage)
{
	m_iLest_HP -= _iDamage;
}

void CStatus::Set_Lest_HP(const int& _iHP)
{
	m_iLest_HP = _iHP;
}

const int& CStatus::Get_Attack_Point()
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

void CStatus::Render() const
{
	cout << "�̸� : " << m_cName << endl;
	cout << "���ݷ� : " << m_iAttack_Point << endl;
	cout << "ü�� : < " << m_iLest_HP << " / " << m_iMax_HP << " >" << endl;
	cout << "==============================" << endl;
}