#pragma once
#include "Status.h"

class CMonster final : public CStatus
{
public:
	CMonster();
	virtual ~CMonster();

	virtual void Render();

	virtual void Init_Stat(const int& _iChoice);

private:
};