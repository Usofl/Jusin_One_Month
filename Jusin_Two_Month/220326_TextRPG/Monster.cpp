#include "stdafx.h"
#include "Monster.h"

CMonster::CMonster()
{

}

CMonster::~CMonster()
{

}

CStatus* CMonster::Get_pStatus()
{
	return &m_Status;
}