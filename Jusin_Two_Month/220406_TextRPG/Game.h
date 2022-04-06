#pragma once
#include "Player.h"
#include "Hunting.h"
#include "Shop.h"

class CGame
{
public:
	CGame();
	~CGame();

	void Initialize();
	void Update();
	void Release();

private:
	CStatus* m_Player;
	vector<CFeild*> m_vecFeild;
};