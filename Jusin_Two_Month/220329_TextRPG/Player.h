#pragma once
#include "Status.h"

class CPlayer : public CStatus
{
public:
	CPlayer();
	~CPlayer();

	virtual void Render();
	virtual void Init_Stat(const int& _iChoice);

private:

};