#pragma once
#include "Player.h"
#include "Monster.h"

class CFeild
{
public:
	CFeild();
	~CFeild();

	void Set_Player(CPlayer* _player);

	void Initialize();
	void Update();
	void Release();

	bool Attack();

private:
	CPlayer* m_Player;
	CMonster* m_Monster;
};