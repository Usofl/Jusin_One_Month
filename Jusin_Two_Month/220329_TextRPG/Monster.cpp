#include "stdafx.h"
#include "Monster.h"

CMonster::CMonster()
{

}

CMonster::~CMonster()
{

}

void CMonster::Render()
{
	cout << "몬스터 : " << Get_Name() << endl;
	cout << "공격력 : " << Get_Attack() << endl;
	cout << "체력 : <" << Get_Lest_HP() << " / " << Get_Max_HP() << ">" << endl;
	cout << "=================================================" << endl;
}

void CMonster::Init_Stat(const int& _iChoice)
{
	switch (_iChoice)
	{
	case 1:
		Set_Name("초급");
		Set_Attack(3);
		Set_Max_HP(30);
		Set_Lest_HP(Get_Max_HP());
		break;

	case 2:
		Set_Name("중급");
		Set_Attack(15);
		Set_Max_HP(50);
		Set_Lest_HP(Get_Max_HP());
		break;

	case 3:
		Set_Name("고급");
		Set_Attack(30);
		Set_Max_HP(90);
		Set_Lest_HP(Get_Max_HP());
		break;

	default:
		break;
	}
}
