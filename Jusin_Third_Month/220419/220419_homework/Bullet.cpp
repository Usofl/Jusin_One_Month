#include "stdafx.h"
#include "Bullet.h"

CBullet::CBullet(CObj& _Obj)
{
	m_tInfo.dX = _Obj.Get_Info().dX;		// 중점 X
	m_tInfo.dY = _Obj.Get_Info().dY;		// 중점 Y

	m_tInfo.dCX = (_Obj.Get_Info().dCX * 0.5);	// 플레이어 가로 사이즈
	m_tInfo.dCY = (_Obj.Get_Info().dCY * 0.5);	// 플레이어 세로 사이즈

	m_dSpeed = 15.0;

	m_Direction = _Obj.Get_Direction();
}

CBullet::~CBullet()
{
}

void CBullet::Initialize(void)
{
}

void CBullet::Update(void)
{
	Move_Bullet();

	Update_Rect();
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Release(void)
{
}

void CBullet::Move_Bullet(void)
{
	switch (m_Direction)
	{
	case Direction_Left:
		m_tInfo.dX -= m_dSpeed;
		break;
	case Direction_Right:
		m_tInfo.dX += m_dSpeed;
		break;
	case Direction_UP:
		m_tInfo.dY -= m_dSpeed;
		break;
	case Direction_Down:
		m_tInfo.dY += m_dSpeed;
		break;
	default:
		break;
	}
}

bool CBullet::Escape_Bullet(RECT _area)
{
	if ((_area.top + m_tInfo.dCY) > m_tInfo.dY
		|| (_area.bottom - m_tInfo.dCY) < m_tInfo.dY
		|| (_area.left + m_tInfo.dCX) > m_tInfo.dX
		|| (_area.right - m_tInfo.dCX) < m_tInfo.dX)
	{
		return true;
	}

	return false;
}
