#pragma once
#include "Bullet.h"

class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	inline void Set_Bullet_List(std::list<CObj*>& _Bullet_List) { m_Bullet_List = &_Bullet_List; }

private:
	void		Key_Input(void);

private:
	std::list<CObj*>* m_Bullet_List;
};

