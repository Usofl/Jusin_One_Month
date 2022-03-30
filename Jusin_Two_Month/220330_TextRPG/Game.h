#pragma once
#include "Player.h"
#include "Hunting.h"

class CGame
{
public:
	CGame();
	~CGame();

	void Initialize();
	void Update();
	void Release();

	void Start_Feild();

private:
	CStatus* m_Player;
	CFeild* m_Feild;
};