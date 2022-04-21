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

	inline const void Set_Pos(const double& _dX, const double& _dY) { m_tInfo.dX = _dX; m_tInfo.dY = _dY; }

	inline const bool& Get_Dead() { return m_bDead; }
	inline const void Set_Dead(const bool& _dead) { m_bDead = _dead; }

	inline const RECT& Get_Rect() { return m_tRect; }

	inline const INFO& Get_Info() { return m_tInfo; }

protected:
	void			Update_Rect(void);

protected:
	INFO			m_tInfo;
	RECT			m_tRect;
	DIRECTION		m_Direction;

	double			m_dSpeed;
	bool			m_bDead;
};

