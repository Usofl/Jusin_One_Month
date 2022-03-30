#pragma once
#include "Player.h"

class CFeild  abstract
{
public:
	CFeild();
	virtual ~CFeild();

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Release() = 0;

	void Set_Player(CStatus* _Player);

protected:
	CStatus* m_Player;
};