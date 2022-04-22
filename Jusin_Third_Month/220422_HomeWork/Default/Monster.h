#pragma once
#include "Obj.h"

class CMonster : public CObj
{
public:
	CMonster();
	virtual ~CMonster();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	inline void Set_Player(CObj* _player) { m_pPlayer = _player; }

private:
	CObj* m_pPlayer;
};

