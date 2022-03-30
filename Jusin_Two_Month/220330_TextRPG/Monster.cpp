#include "stdafx.h"
#include "Monster.h"

CMonster::CMonster()
{

}

CMonster::~CMonster()
{

}

void CMonster::Initialize(const int& _iChoice)
{
	switch (_iChoice)
	{
	case Job_Warrior:
		Set_Name("초급");
		Set_Attack(3);
		Set_Max_HP(30);
		Set_Money(15);
		Set_Exp(15);
		break;
	case Job_Magician:
		Set_Name("중급");
		Set_Attack(30);
		Set_Max_HP(60);
		Set_Money(45);
		Set_Exp(45);
		break;
	case Job_Thief:
		Set_Name("고급");
		Set_Attack(20);
		Set_Max_HP(80);
		Set_Money(90);
		Set_Exp(90);
		break;
	default:
		break;
	}
	Set_Lest_HP(Get_Max_HP());
}

void CMonster::Render()
{
	cout << "몬스터 : " << Get_Name() << endl;
	cout << "공격력 : " << Get_Attack() << endl;
	cout << "체력 : <" << Get_Lest_HP() << " / " << Get_Max_HP() << ">" << endl;
	cout << "=================================================" << endl;
}