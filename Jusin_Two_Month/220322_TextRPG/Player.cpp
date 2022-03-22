#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer(int _iChoice)
{
	char cName[20] = {};

	switch (_iChoice)
	{
	case 1:
		strcpy_s(m_cClass, sizeof(m_cClass), "전사");
		m_Status.m_iAttack_Point = 10;
		m_Status.m_iMax_HP = 200;
		break;

	case 2:
		strcpy_s(m_cClass, sizeof(m_cClass), "마법사");
		m_Status.m_iAttack_Point = 10;
		m_Status.m_iMax_HP = 200;
		break;

	case 3:
		strcpy_s(m_cClass, sizeof(m_cClass), "도적");
		m_Status.m_iAttack_Point = 10;
		m_Status.m_iMax_HP = 200;
		break;

	default:
		break;
	}
	cout << "닉네임을 입력 하세요(1~9자) : ";
	cin >> cName;

	strcpy_s(m_cNick_Name, sizeof(m_cNick_Name), cName);
	m_Status.m_iLest_HP = m_Status.m_iMax_HP;
}

CPlayer::~CPlayer()
{
}

void CPlayer::Rander()
{
	cout << "닉네임 : " << m_cNick_Name << endl;
	cout << "직업 : " << m_cClass << endl;
	cout << "공격력 : " << m_Status.m_iAttack_Point << endl;
	cout << "체력 : <" << m_Status.m_iLest_HP << " / " << m_Status.m_iMax_HP << ">" << endl;
	cout << "==========================" << endl;
}

void CPlayer::Set_Attack_Point(const int _iAttack_Point)
{
	m_Status.m_iAttack_Point = _iAttack_Point;
}

void CPlayer::Set_Lest_HP(const int _iHP)
{
	m_Status.m_iLest_HP = _iHP;
}

void CPlayer::Set_Max_HP(const int _iHP)
{
	m_Status.m_iMax_HP = _iHP;
}

const int CPlayer::Get_Attack_Point()
{
	return m_Status.m_iAttack_Point;
}

const int CPlayer::Get_Lest_HP()
{
	return m_Status.m_iLest_HP;
}

const int CPlayer::Get_Max_HP()
{
	return m_Status.m_iMax_HP;
}