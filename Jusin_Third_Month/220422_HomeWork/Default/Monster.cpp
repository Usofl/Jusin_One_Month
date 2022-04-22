#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize(void)
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_fSpeed = 1.f;
}

int CMonster::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	float fpX = m_pPlayer->Get_Info().fX - m_tInfo.fX;
	float fpY = m_pPlayer->Get_Info().fY - m_tInfo.fY;

	float fpC = sqrtf((fpX * fpX) + (fpY * fpY));

	float fXSeta = acosf((fpX / fpC));
	float fYSeta = asinf((fpY / fpC));

	m_tInfo.fX += (m_fSpeed * cos(fXSeta));
	m_tInfo.fY += (m_fSpeed * sin(fYSeta));

	Update_Rect();

	return OBJ_NOEVENT;
}

void CMonster::Late_Update(void)
{
	/*if (100 >= m_tRect.left || WINCX - 100 <= m_tRect.right)
		m_fSpeed *= -1.f;*/
}

void CMonster::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonster::Release(void)
{
	
}
