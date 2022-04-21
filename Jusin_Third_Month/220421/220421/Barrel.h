#pragma once
#include "Obj.h"
class CBarrel :
	public CObj
{
public:
	CBarrel();
	virtual ~CBarrel();

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	inline const void Set_Player_Info(INFO* _info) { m_pPlayerInfo = _info; }
	inline const void Set_Player_Rect(RECT* _rect) { m_pPlayerRect = _rect; }

	inline const double Get_Dir_X() { return m_tInfo.dX - m_pPlayerInfo->dX; }
	inline const double Get_Dir_Y() { return m_tInfo.dY - m_pPlayerInfo->dY; }

private:
	void Key_Input(void);

private:
	INFO* m_pPlayerInfo;
	RECT* m_pPlayerRect;

	double m_dCos;
	double m_dReverse;
};

