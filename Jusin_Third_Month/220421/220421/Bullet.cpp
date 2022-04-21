#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet(CObj& _rObj, const double& _dShotX, const double& _dShotY )
	: CObj(_rObj)
	, m_dShotDirX(_dShotX)
	, m_dShotDirY(_dShotY)
{
	m_tInfo.dCX *= 0.3;
	m_tInfo.dCY *= 0.3;

	m_dSpeed = 0.3;
}


CBullet::~CBullet()
{
}

void CBullet::Initialize(void)
{
}

void CBullet::Update(void)
{
	m_tInfo.dX += (m_dShotDirX * m_dSpeed);
	m_tInfo.dY += (m_dShotDirY * m_dSpeed);

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