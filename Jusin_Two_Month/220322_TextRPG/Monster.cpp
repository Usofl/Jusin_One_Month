#include "stdafx.h"
#include "Monster.h"

CMonster::CMonster(int _iLevel)
{
	switch (_iLevel)
	{
	case 1:
		strcpy_s(m_cName, sizeof(m_cName), "2D 포폴");
		m_Status.m_iAttack_Point = 10;
		m_Status.m_iMax_HP = 50;
		break;

	case 2:
		strcpy_s(m_cName, sizeof(m_cName), "3D 포폴");
		m_Status.m_iAttack_Point = 30;
		m_Status.m_iMax_HP = 70;
		break;

	case 3:
		strcpy_s(m_cName, sizeof(m_cName), "졸업 포폴");
		m_Status.m_iAttack_Point = 50;
		m_Status.m_iMax_HP = 100;
		break;

	default:
		break;
	}

	m_Status.m_iLest_HP = m_Status.m_iMax_HP;
}

CMonster::~CMonster()
{
}

void CMonster::Rander()
{
	cout << "이름 : " << m_cName << endl;
	cout << "공격력 : " << m_Status.m_iAttack_Point << endl;
	cout << "체력 : <" << m_Status.m_iLest_HP << " / " << m_Status.m_iMax_HP << ">" << endl;
	cout << "==========================" << endl;
}

void CMonster::Set_Lest_HP(const int _iHP)
{
	m_Status.m_iLest_HP = _iHP;
}

void CMonster::Set_Max_HP(const int _iHP)
{
	m_Status.m_iMax_HP = _iHP;
}

const int CMonster::Get_Attack_Point()
{
	return m_Status.m_iAttack_Point;
}

const int CMonster::Get_Lest_HP()
{
	return m_Status.m_iLest_HP;
}

const int CMonster::Get_Max_HP()
{
	return m_Status.m_iMax_HP;
}