#pragma once
#include "Monster.h"

class CBullet
{
public:
	CBullet(RECT _rc, Bullet _Direction);
	~CBullet();

	void shoot();

	inline RECT Get_RECT() { return rc; }
	bool Hit_Monster(std::list<CMonster*>& _mlist);

public:
	RECT rc;
	Bullet eDirection;
};

