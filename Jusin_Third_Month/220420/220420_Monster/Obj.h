#pragma once
#include "AbstractFactory.h"

class CObj abstract
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual void		Initialize(void)	PURE;
	virtual void		Update(void)		PURE;
	virtual void		Late_Update(void)	PURE;
	virtual void		Render(HDC hDC)		PURE;
	virtual void		Release(void)		PURE;

	inline const DIRECTION& Get_Direction() { return m_Direction; }
	inline const void Set_Direction(const DIRECTION& _direction) { m_Direction = _direction; }

	inline const bool& Get_Dead() { return m_bDead; }
	inline const void Set_Dead(const bool& _dead) { m_bDead = _dead; }

	inline const RECT& Get_Rect() { return m_tRect; }

protected:
	void			Update_Rect(void);

protected:
	INFO			m_tInfo;
	RECT			m_tRect;
	DIRECTION		m_Direction;

	double			m_dSpeed;
	bool			m_bDead;
};

