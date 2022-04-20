#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize(void)
{
	m_tInfo.dX = 400.0;
	m_tInfo.dY = 300.0;

	m_tInfo.dCX = 100.0;
	m_tInfo.dCY = 100.0;

	m_dSpeed = 10.0;
}

void CPlayer::Update(void)
{
	Key_Input();
	
	Update_Rect();
}

void CPlayer::Late_Update(void)
{
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release(void)
{
}

void CPlayer::Key_Input(void)
{

	if (GetAsyncKeyState(VK_LEFT))
	{
		if (m_tRect.left > GAME_SIZE)
		{
			m_tInfo.dX -= m_dSpeed;
		}
		Set_Direction(DIRECTION_LEFT);
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (m_tRect.right < WINCX - GAME_SIZE)
		{
			m_tInfo.dX += m_dSpeed;
		}
		Set_Direction(DIRECTION_RIGHT);
	}

	if (GetAsyncKeyState(VK_UP))
	{
		if (m_tRect.top > GAME_SIZE)
		{
			m_tInfo.dY -= m_dSpeed;
		}
		Set_Direction(DIRECTION_UP);
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		if (m_tRect.bottom < WINCY - GAME_SIZE)
		{
			m_tInfo.dY += m_dSpeed;
		}
		Set_Direction(DIRECTION_DOWN);
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		m_Bullet_List->push_back(new CBullet(*this));
	}
}
