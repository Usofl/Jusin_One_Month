#pragma once
#include "Status.h"

class CMonster
{
public:
	CMonster();
	~CMonster();

	CStat* get_Status();

private:
	CStat m_Status;
};