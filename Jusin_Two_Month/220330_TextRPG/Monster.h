#pragma once
#include "Status.h"

class CMonster final : public CStatus
{
public:
	CMonster();
	virtual ~CMonster();

	virtual void Initialize(const int& _iChoice);

	virtual void Render();

private:
};