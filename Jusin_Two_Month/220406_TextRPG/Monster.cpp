#include "stdafx.h"
#include "Monster.h"

CMonster::CMonster()
	: CStatus()
{
}

CMonster::~CMonster()
{
}

void CMonster::Render()
{
	cout << "ÀÌ¸§ : " << Get_Name() << endl;
	cout << "°ø°Ý·Â : " << Get_Attack() << endl;
	cout << "Ã¼·Â : <" << Get_Lest_HP() << " / " << Get_Max_HP() << ">" << endl;
	cout << "=================================================" << endl;
}

void CMonster::Init_Stat(const int& _iChoice)
{
	switch (_iChoice)
	{
	case Job_Warrior:
		Set_Name("º£½ºÅ°");
		Set_Attack(5);
		Set_Max_HP(30);
		Set_Money(15);
		Set_Exp(15);
		break;

	case Job_Magician:
		Set_Name("°øÄ¥»§");
		Set_Attack(15);
		Set_Max_HP(50);
		Set_Money(30);
		Set_Exp(30);
		break;

	case Job_Thief:
		Set_Name("»ïÀ°±¸");
		Set_Attack(30);
		Set_Max_HP(80);
		Set_Money(100);
		Set_Exp(100);
		break;

	default:
		break;
	}

	Set_Lest_HP(Get_Max_HP());
}
