#pragma once
#include "stdafx.h"
#include "Player.h"
#include "HuntingZone.h"

class CGame
{
private:
	CPlayer* m_Player;
	CHuntingZone m_Hunting;
public:
	CGame();
	~CGame();

	bool Main_Game();
};