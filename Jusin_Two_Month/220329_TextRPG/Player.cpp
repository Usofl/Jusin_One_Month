#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
{

}

CPlayer::~CPlayer()
{

}

void CPlayer::Render()
{
	cout << "플레이어 : " << Get_Name() << endl;
	cout << "공격력 : " << Get_Attack() << endl;
	cout << "체력 : <" << Get_Lest_HP() << " / " << Get_Max_HP() << ">" << endl;
	cout << "=================================================" << endl;
}

void CPlayer::Init_Stat(const int& _iChoice)
{
	switch (_iChoice)
	{
	case 1:
		Set_Name("전사");
		Set_Attack(10);
		Set_Max_HP(100);
		Set_Lest_HP(Get_Max_HP());
		break;

	case 2:
		Set_Name("마법사");
		Set_Attack(30);
		Set_Max_HP(70);
		Set_Lest_HP(Get_Max_HP());
		break;

	case 3:
		Set_Name("도적");
		Set_Attack(20);
		Set_Max_HP(90);
		Set_Lest_HP(Get_Max_HP());
		break;

	default:
		break;
	}
}
