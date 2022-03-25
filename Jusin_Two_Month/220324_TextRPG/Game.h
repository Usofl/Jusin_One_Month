#pragma once
#include "Player.h"
#include "Feild.h"

class CGame
{
public:
	CGame();
	~CGame();

	void Initialize();
	void Update();
	void Release();

private:
	CPlayer* m_player;
	CFeild* m_Feild;
};