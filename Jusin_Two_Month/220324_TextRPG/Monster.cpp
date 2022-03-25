#include "stdafx.h"
#include "Monster.h"

CMonster::CMonster()
{

}

CMonster::~CMonster()
{

}

CStatus* CMonster::Get_Status()
{
	return &m_Status;
}