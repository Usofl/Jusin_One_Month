#include "stdafx.h"
#include "Monster.h"

CMonster::CMonster()
	: CStatus()
{

}

CMonster::~CMonster()
{

}

void CMonster::Set_Monster(const int& _iLevel)
{
	switch (_iLevel)
	{
	case 1:
		this->Init_Stat("�ʱ�", 3, 30, 15, 20);
		break;

	case 2:
		this->Init_Stat("�߱�", 15, 50, 30, 70);
		break;

	case 3:
		this->Init_Stat("���", 30, 100, 80, 150);
		break;

	default:
		break;
	}
}