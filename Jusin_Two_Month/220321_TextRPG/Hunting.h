#pragma once
#include "Monster.h"
#include "Player.h"

class CHunting
{
private:
	CMonster m_monster;
public:
	void Hunting_Menu(CPlayer* _player);
	void Hunting_Monster(CPlayer* _player);
	bool Attack_Monster(CPlayer* _player);
};