#pragma once

#include "Player.h"

class CFeild abstract
{
public:
	CFeild() {};
	virtual ~CFeild() {};

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Release() = 0;

	inline void Set_Player(CStatus*& _player) { m_Player = _player; }

protected:
	CStatus* m_Player;
};