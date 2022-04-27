#pragma once
class CObj abstract
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual void Initialize(void) PURE;
	virtual void Update(void) PURE;
	virtual void Late_Update(void) PURE;
	virtual void Render(HDC _hDC) PURE;
	virtual void Release(void) PURE;

protected:
	void Update_Rect(void);

protected:
	INFO m_tInfo;
	RECT m_tRect;
	POINT m_tPoint; // ��ǥ longŸ��.
	
	int m_iReverse;

	float m_fSpeed;
	float m_fAngle;
};