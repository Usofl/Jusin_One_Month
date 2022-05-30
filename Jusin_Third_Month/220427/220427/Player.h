#pragma once
#include "Obj.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC _hDC) override;
	virtual void Release(void) override;

private:
	void Key_Input(void);

private:
	bool m_bChange;
	bool m_bJump;
	float m_fTime;
	float m_fJumpAngle;
	float m_fJumpY;

	POINT m_Left_Leg;
	POINT m_Right_Leg;
};

