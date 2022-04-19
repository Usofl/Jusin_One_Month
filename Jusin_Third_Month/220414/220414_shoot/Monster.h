#pragma once

class CMonster
{
public:
	CMonster(RECT _rc);
	~CMonster();

	inline RECT Get_RECT() { return rc; }
	inline void Dead() { rc = { 0,0,0,0 }; }
public:
	RECT rc;
};

