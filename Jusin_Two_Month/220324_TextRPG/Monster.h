#pragma once
#include "Status.h"

class CMonster
{
public:
	CMonster();
	~CMonster();

	CStatus* Get_Status();

private:
	CStatus m_Status;
};