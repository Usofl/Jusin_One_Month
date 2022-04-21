#pragma once
#include "Obj.h"
#include "Bullet.h"
#include "Barrel.h"

class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	inline void Set_Bullet_List(std::list<CObj*>* _Bullet_List) { m_Bullet_List = _Bullet_List; }
	inline void Set_Barrel(std::list<CObj*>* _Bullet_List) { m_Bullet_List = _Bullet_List; }

private:
	void Key_Input(void);

private:
	std::list<CObj*>* m_Bullet_List;
	CBarrel* m_Barrel;
};

