#include "stdafx.h"
#include "Player.h"

bool CPlayer::Init_Player()
{
	int iChoice = 0;
	char cNickName[20];

	cout << "1. 전사 2. 마법사 3. 도적 4. 불러오기 5.종료" << endl;

	cin >> iChoice;

	system("cls");

	cout << "닉네임을 입력하세요(1~9자) : ";
	cin >> cNickName;

	strcpy_s(m_NickName, sizeof(m_NickName), cNickName);

	switch (iChoice)
	{
	case 1:
		strcpy_s(m_Class, sizeof(m_Class), "전사");
		Set_Attack_Point(10);
		Set_Max_HP(200);
		break;

	case 2:
		strcpy_s(m_Class, sizeof(m_Class), "마법사");
		break;

	case 3:
		strcpy_s(m_Class, sizeof(m_Class), "도적");
		break;

	case 5:
		return false;
		break;

	default:
		break;
	}

	return true;
}

void CPlayer::Set_Attack_Point(int _AttackPoint)
{
	m_Attack_Point = _AttackPoint;
}

void CPlayer::Set_Max_HP(int _HP)
{
	m_Max_HP = _HP;
}

void CPlayer::Set_Lest_HP(int _HP)
{
	m_Lest_HP = _HP;
}

const int CPlayer::Get_Attack_Point()
{
	return m_Attack_Point;
}

const int CPlayer::Get_Max_HP()
{
	return m_Max_HP;
}

const int CPlayer::Get_Lest_HP()
{
	return m_Lest_HP;
}
