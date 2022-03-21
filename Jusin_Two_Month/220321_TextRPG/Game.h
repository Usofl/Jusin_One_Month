#pragma once
#include "Player.h"
#include "Hunting.h"

class CGame
{
private:
	CPlayer* m_player = nullptr;
	CHunting m_hunting;
public:
	bool Menu();
};