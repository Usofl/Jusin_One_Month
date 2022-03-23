#include "stdafx.h"
#include "Status.h"

CStat::CStat()
{
	strcpy_s(m_Name, sizeof(m_Name), "");

	m_iAttack_Point = 0;
	m_iMax_HP = 0;
	m_iLest_HP = m_iMax_HP;
}

CStat::~CStat()
{
}

void CStat::Set_Status(char * _cName, int _iAttack_Point, int _iMax_HP)
{
	strcpy_s(m_Name, sizeof(m_Name), _cName);

	m_iAttack_Point = _iAttack_Point;
	m_iMax_HP = _iMax_HP;
	m_iLest_HP = m_iMax_HP;
}

void CStat::Set_Damage(int _iAttack_Point)
{
	m_iLest_HP -= _iAttack_Point;
}

void CStat::Set_Lest_Max_HP()
{
	m_iLest_HP = m_iMax_HP;
}

const int CStat::Get_Attack_Point()
{
	return m_iAttack_Point;
}

const int CStat::Get_Lest_HP()
{
	return m_iLest_HP;
}

void CStat::Rander()
{
	cout << "=================================" << endl;
	cout << "이름 : " << m_Name << endl;
	cout << "공격력 : " << m_iAttack_Point << endl;
	cout << "체력 : <" << m_iLest_HP << " / " << m_iMax_HP << ">" << endl;
	cout << "=================================" << endl;
}
