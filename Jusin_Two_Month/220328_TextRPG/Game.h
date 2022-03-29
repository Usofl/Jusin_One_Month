#pragma once
#include "Player.h"
#include "Feild.h"
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
	CPlayer* m_Player;
	CFeild* m_Feild;
	CShop* m_Shop;
};