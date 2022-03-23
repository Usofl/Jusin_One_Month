#include "stdafx.h"
#include "Monster.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
}

CStat* CMonster::get_Status()
{
	return &m_Status;
}