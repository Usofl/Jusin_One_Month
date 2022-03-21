#pragma once
#include "Player.h"

class CGame
{
private:
	CPlayer* m_player = nullptr;

public:
	bool Menu();
};