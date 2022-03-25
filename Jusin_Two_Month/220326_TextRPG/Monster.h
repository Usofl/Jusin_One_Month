#pragma once
#include "Status.h"

class CMonster
{
public:
	CMonster();
	~CMonster();

	CStatus* CMonster::Get_pStatus();

private:
	CStatus m_Status;
};