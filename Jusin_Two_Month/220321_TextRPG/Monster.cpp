#include "stdafx.h"
#include "Monster.h"

void CMonster::Init_Monster(int _Level)
{
	switch (_Level)
	{
	case 1:
		Set_Monster_Name("쥬신 1개월차");
		Set_Attack_Point(5);
		Set_Max_HP(30);
		break;
	case 2:
		Set_Monster_Name("쥬신 2개월차");
		Set_Attack_Point(30);
		Set_Max_HP(70);
		break;
	case 3:
		Set_Monster_Name("쥬신 3개월차");
		Set_Attack_Point(50);
		Set_Max_HP(100);
		break;
	default:
		break;
	}

	Set_Lest_HP(Get_Max_HP());
}

void CMonster::Print_Monster_Info()
{
	cout << "이름 : " << Get_Monster_Name() << endl;
	cout << "공격력 : " << Get_Attack_Point() << endl;
	cout << "체력 : <" << Get_Lest_HP() << " / " << Get_Max_HP() << ">" << endl;
	cout << "=============================" << endl;
}

void CMonster::Set_Monster_Name(char * _cMonsterName)
{
	strcpy_s(m_MonsterName, sizeof(m_MonsterName), _cMonsterName);
}

void CMonster::Set_Attack_Point(int _AttackPoint)
{
	m_Attack_Point = _AttackPoint;
}

void CMonster::Set_Max_HP(int _HP)
{
	m_Max_HP = _HP;
}

void CMonster::Set_Lest_HP(int _HP)
{
	m_Lest_HP = _HP;
}

const char * CMonster::Get_Monster_Name()
{
	return m_MonsterName;
}

const int CMonster::Get_Attack_Point()
{
	return m_Attack_Point;
}

const int CMonster::Get_Max_HP()
{
	return m_Max_HP;
}

const int CMonster::Get_Lest_HP()
{
	return m_Lest_HP;
}
