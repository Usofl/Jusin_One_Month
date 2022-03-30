#pragma once
#include "Status.h"

class CFeild
{
public:
	CFeild();
	virtual ~CFeild();

	void Set_Player(CStatus* _player);

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

protected:
	CStatus* m_Player;
};