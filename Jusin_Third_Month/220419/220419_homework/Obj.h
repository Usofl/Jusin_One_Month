#pragma once

class CObj abstract
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual void		Initialize(void)	PURE;
	virtual void		Update(void)		PURE;
	virtual void		Render(HDC hDC)		PURE;
	virtual void		Release(void)		PURE;

	inline const INFO& Get_Info() { return m_tInfo; }
	inline const Direction& Get_Direction() { return m_Direction; }
	inline const void Set_Direction(const Direction& _direction) { m_Direction = _direction; }

protected:
	void			Update_Rect(void);

protected:
	INFO			m_tInfo;
	RECT			m_tRect;
	Direction		m_Direction;

	double			m_dSpeed; 
};

