#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
	: m_Left_Leg({ 0,0 })
	, m_Right_Leg({ 0,0 })
{
}


CPlayer::~CPlayer()
{
}

void CPlayer::Initialize(void)
{
	//theta = 0.f;

	m_tInfo.fX = WINCX * 0.5f;
	m_tInfo.fY = WINCY * 0.5f;

	m_tInfo.fCX = 75.f;
	m_tInfo.fCY = 75.f;

	m_fAngle = asinf((m_tInfo.fCY * 0.5f) / LEGSIZE);

	m_Left_Leg = { (LONG)(m_tInfo.fX - LEGSIZE * cos(m_fAngle)) , (LONG)(m_tInfo.fY + LEGSIZE * sin(m_fAngle)) };
	m_Right_Leg = { (LONG)(m_tInfo.fX + LEGSIZE * cos(m_fAngle)) , (LONG)(m_tInfo.fY + LEGSIZE * sin(m_fAngle)) };

	m_iReverse = 1;

	m_fSpeed = 2.f;
}

void CPlayer::Update(void)
{
	Key_Input();

	Update_Rect();
}

void CPlayer::Late_Update(void)
{
}

void CPlayer::Render(HDC _hDC)
{

	Ellipse(_hDC, m_tRect.left + (int)(m_tInfo.fCX * 0.25f), m_tRect.top - (int)(m_tInfo.fCY * 0.5f)
			, m_tRect.right - (int)(m_tInfo.fCX * 0.25f), m_tRect.bottom - (int)((m_tInfo.fCY / 3.f) * 2.3f));

	Ellipse(_hDC, m_tRect.left + (int)(m_tInfo.fCX * 0.1f), m_tRect.top - (int)(m_tInfo.fCY * 0.4f)
			, m_tRect.right - (int)(m_tInfo.fCX * 0.1f), m_tRect.bottom - (int)((m_tInfo.fCY / 3.f) * 2.3f));

	Ellipse(_hDC, m_tRect.left + (int)(m_tInfo.fCX * 0.25f), m_tRect.top - (int)(m_tInfo.fCY * 0.3f)
			, m_tRect.right - (int)(m_tInfo.fCX * 0.25f), m_tRect.bottom - (int)(m_tInfo.fCY * 0.8f));
	
	MoveToEx(_hDC, (int)(m_tInfo.fX), m_tRect.bottom - (int)(m_tInfo.fCY * 0.8f), nullptr);
	LineTo(_hDC, (int)(m_tInfo.fX), (int)(m_tInfo.fY));

	LineTo(_hDC, m_Left_Leg.x, m_Left_Leg.y);
	MoveToEx(_hDC, (int)(m_tInfo.fX), (int)(m_tInfo.fY), nullptr);
	LineTo(_hDC, m_Right_Leg.x, m_Right_Leg.y);
}

void CPlayer::Release(void)
{
}

void CPlayer::Key_Input(void)
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (m_bChange)
		{
			m_Left_Leg.x += (LONG)m_fSpeed;

			float fX = m_Left_Leg.x - m_tInfo.fX;
			m_fAngle = acosf(fX / LEGSIZE);

			if (m_tInfo.fCX * 0.5f <= fabs(m_Left_Leg.x - m_Right_Leg.x) && m_Left_Leg.x > m_Right_Leg.x)
			{
				m_bChange = false;
			}

			if (m_tInfo.fY > m_Left_Leg.y)
			{
				m_fAngle *= -1.f;
			}

			m_tInfo.fX = m_Right_Leg.x + LEGSIZE * cos(m_fAngle);
			m_tInfo.fY = m_Right_Leg.y - LEGSIZE * sin(m_fAngle);
		}
		else
		{
			m_Right_Leg.x += (LONG)m_fSpeed;

			float fX = m_Right_Leg.x - m_tInfo.fX;
			m_fAngle = acosf(fX / LEGSIZE);

			if (m_tInfo.fCX * 0.5f <= fabs(m_Left_Leg.x - m_Right_Leg.x) && m_Left_Leg.x < m_Right_Leg.x)
			{
				m_bChange = true;
			}

			if (m_tInfo.fY > m_Right_Leg.y)
			{
				m_fAngle *= -1.f;
			}

			m_tInfo.fX = m_Left_Leg.x + LEGSIZE * cos(m_fAngle);
			m_tInfo.fY = m_Left_Leg.y - LEGSIZE * sin(m_fAngle);
		}
	}

	else if (GetAsyncKeyState(VK_LEFT))
	{
		if (m_bChange)
		{
			m_Left_Leg.x -= (LONG)m_fSpeed;

			float fX = m_Left_Leg.x - m_tInfo.fX;
			m_fAngle = acosf(fX / LEGSIZE);

			if (m_tInfo.fCX * 0.5f <= fabs(m_Left_Leg.x - m_Right_Leg.x) && m_Left_Leg.x < m_Right_Leg.x)
			{
				m_bChange = false;
			}

			if (m_tInfo.fY > m_Left_Leg.y)
			{
				m_fAngle *= -1.f;
			}

			m_tInfo.fX = m_Right_Leg.x + LEGSIZE * cos(m_fAngle);
			m_tInfo.fY = m_Right_Leg.y - LEGSIZE * sin(m_fAngle);
		}
		else
		{
			m_Right_Leg.x -= (LONG)m_fSpeed;

			float fX = m_Right_Leg.x - m_tInfo.fX;
			m_fAngle = acosf(fX / LEGSIZE);

			if (m_tInfo.fCX * 0.5f <= fabs(m_Left_Leg.x - m_Right_Leg.x) && m_Left_Leg.x > m_Right_Leg.x)
			{
				m_bChange = true;
			}

			if (m_tInfo.fY > m_Right_Leg.y)
			{
				m_fAngle *= -1.f;
			}

			m_tInfo.fX = m_Left_Leg.x + LEGSIZE * cos(m_fAngle);
			m_tInfo.fY = m_Left_Leg.y - LEGSIZE * sin(m_fAngle);
		}

	}

	/*if (GetAsyncKeyState('W'))
	{
		if (LEGSIZE * 1.9 > fabs(m_Right_Leg.x - m_Left_Leg.x) || m_Left_Leg.x < m_Right_Leg.x)
		{
			m_Left_Leg.x += (LONG)m_fSpeed;

			float fX = m_Left_Leg.x - m_tInfo.fX;
			m_fAngle = acosf(fX / LEGSIZE);

			if (m_tInfo.fY > m_Left_Leg.y)
			{
				m_fAngle *= -1.f;
			}

			m_tInfo.fX = m_Right_Leg.x + LEGSIZE * cos(m_fAngle);
			m_tInfo.fY = m_Right_Leg.y - LEGSIZE * sin(m_fAngle);
		}
	}
	else if (GetAsyncKeyState('S'))
	{
		if (LEGSIZE * 1.9 > fabs(m_Right_Leg.x - m_Left_Leg.x) || m_Left_Leg.x > m_Right_Leg.x)
		{
			m_Right_Leg.x += (LONG)m_fSpeed;

			float fX = m_Right_Leg.x - m_tInfo.fX;
			m_fAngle = acosf(fX / LEGSIZE);

			if (m_tInfo.fY > m_Right_Leg.y)
			{
				m_fAngle *= -1.f;
			}

			m_tInfo.fX = m_Left_Leg.x + LEGSIZE * cos(m_fAngle);
			m_tInfo.fY = m_Left_Leg.y - LEGSIZE * sin(m_fAngle);
		}
	}
	else if (GetAsyncKeyState('Q'))
	{
		if (LEGSIZE * 1.9 > fabs(m_Right_Leg.x - m_Left_Leg.x) || m_Left_Leg.x > m_Right_Leg.x)
		{
			m_Left_Leg.x -= (LONG)m_fSpeed;

			float fX = m_Left_Leg.x - m_tInfo.fX;
			m_fAngle = acosf(fX / LEGSIZE);

			if (m_tInfo.fY > m_Left_Leg.y)
			{
				m_fAngle *= -1.f;
			}

			m_tInfo.fX = m_Right_Leg.x + LEGSIZE * cos(m_fAngle);
			m_tInfo.fY = m_Right_Leg.y - LEGSIZE * sin(m_fAngle);
		}
	}
	else if (GetAsyncKeyState('A'))
	{
		if (LEGSIZE * 1.9 > fabs(m_Right_Leg.x - m_Left_Leg.x) || m_Left_Leg.x < m_Right_Leg.x)
		{
			m_Right_Leg.x -= (LONG)m_fSpeed;

			float fX = m_Right_Leg.x - m_tInfo.fX;
			m_fAngle = acosf(fX / LEGSIZE);

			if (m_tInfo.fY > m_Right_Leg.y)
			{
				m_fAngle *= -1.f;
			}

			m_tInfo.fX = m_Left_Leg.x + LEGSIZE * cos(m_fAngle);
			m_tInfo.fY = m_Left_Leg.y - LEGSIZE * sin(m_fAngle);
		}
	}*/
}