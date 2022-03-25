#pragma once
#include "Player.h"
#include "Monster.h"

class CFeild
{
public:
	CFeild(CPlayer* _Player);
	~CFeild();

	void Initialize();
	void Update();
	void Release();

private:
	CPlayer* m_Player;
	CMonster* m_Monster;
};