#pragma once
#include "Status.h"

class CMonster : public CStatus
{
public:
	CMonster();
	~CMonster();

	void Set_Monster(const int& _iLevel);

private:
	
};