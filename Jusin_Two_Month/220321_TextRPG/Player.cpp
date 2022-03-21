#include "stdafx.h"
#include "Player.h"

bool CPlayer::Init_Player()
{
	int iChoice = 0;
	char cNickName[20];

	cout << "1. 전사 2. 마법사 3. 도적 4. 불러오기 5.종료" << endl;

	cin >> iChoice;

	system("cls");

	switch (iChoice)
	{
	case 1:
		cout << "닉네임을 입력하세요(1~9자) : ";
		cin >> cNickName;

		Set_Nick_Name(cNickName);
		Set_Class("전사");

		Set_Attack_Point(10);
		Set_Max_HP(200);
		Set_Lest_HP(Get_Max_HP());
		break;

	case 2:
		cout << "닉네임을 입력하세요(1~9자) : ";
		cin >> cNickName;

		Set_Nick_Name(cNickName);
		Set_Class("마법사");

		Set_Attack_Point(50);
		Set_Max_HP(100);
		Set_Lest_HP(Get_Max_HP());
		break;

	case 3:
		cout << "닉네임을 입력하세요(1~9자) : ";
		cin >> cNickName;

		Set_Nick_Name(cNickName);
		Set_Class("도적");

		Set_Attack_Point(30);
		Set_Max_HP(150);
		Set_Lest_HP(Get_Max_HP());
		break;

	case 5:
		return false;
		break;

	default:
		break;
	}

	return true;
}

void CPlayer::Print_Player_Info()
{
	cout << "닉네임 : " << Get_Nick_Name() << endl;
	cout << "직업 : " << Get_Class() << endl;
	cout << "공격력 : " << Get_Attack_Point() << endl;
	cout << "체력 : <" << Get_Lest_HP() << " / " << Get_Max_HP() << ">" << endl;
	cout << "=============================" << endl;
}

void CPlayer::Set_Nick_Name(char * _cNickName)
{
	strcpy_s(m_NickName, sizeof(m_NickName), _cNickName);
}

void CPlayer::Set_Class(char * _cClass)
{
	strcpy_s(m_Class, sizeof(m_Class), _cClass);
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

const char * CPlayer::Get_Class()
{
	return m_Class;
}

const char * CPlayer::Get_Nick_Name()
{
	return m_NickName;
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
