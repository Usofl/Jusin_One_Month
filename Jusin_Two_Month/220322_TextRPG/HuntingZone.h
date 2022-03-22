#pragma once
#include "stdafx.h"
#include "Player.h"
#include "Monster.h"

class CHuntingZone
{
private:
	CMonster* m_monster;
public:
	CHuntingZone();
	~CHuntingZone();

	void Hunting_Menu(CPlayer* _player);
	void Hunting_Monster(CPlayer* _player);
	bool Attack_Monster(CPlayer* _player);
};