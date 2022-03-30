#pragma once
#include "Status.h"

class CMonster : public CStatus
{
public:
	CMonster();
	~CMonster();

	virtual void Render();
	virtual void Init_Stat(const int& _iChoice);
private:

};