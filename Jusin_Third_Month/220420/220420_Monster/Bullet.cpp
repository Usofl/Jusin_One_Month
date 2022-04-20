#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet(CObj& _rObj)
	: CObj(_rObj)
{
	m_tInfo.dCX *= 0.3;
	m_tInfo.dCY *= 0.3;

	m_dSpeed = 15.0;
}


CBullet::~CBullet()
{
}

void CBullet::Initialize(void)
{
}

void CBullet::Update(void)
{
	switch (m_Direction)
	{
	case DIRECTION_LEFT:
		m_tInfo.dX -= m_dSpeed;
		break;
	case DIRECTION_RIGHT:
		m_tInfo.dX += m_dSpeed;
		break;
	case DIRECTION_UP:
		m_tInfo.dY -= m_dSpeed;
		break;
	case DIRECTION_DOWN:
		m_tInfo.dY += m_dSpeed;
		break;
	}

	Update_Rect();
}

void CBullet::Late_Update(void)
{
	if (Escape_Bullet())
	{
		m_bDead = true;
	}
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Release(void)
{
}

bool CBullet::Escape_Bullet()
{
	if (GAME_SIZE > m_tRect.top
		|| WINCY - GAME_SIZE < m_tRect.bottom
		|| GAME_SIZE > m_tRect.left
		|| WINCX - GAME_SIZE < m_tRect.right)
	{
		return true;
	}

	return false;
}