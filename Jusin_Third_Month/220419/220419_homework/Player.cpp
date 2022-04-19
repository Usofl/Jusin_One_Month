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
	m_tInfo.dX = 400.0;		// 중점 X
	m_tInfo.dY = 300.0;		// 중점 Y

	m_tInfo.dCX = 100.0;	// 플레이어 가로 사이즈
	m_tInfo.dCY = 100.0;	// 플레이어 세로 사이즈

	m_dSpeed = 10.0;
}

void CPlayer::Update(void)
{
	Key_Input();

	// 위쪽에서 중점 또는 사이즈의 변화를 끝낸 다음에 Update_Rect함수를 호출
	Update_Rect();
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
		m_tInfo.dX -= m_dSpeed;
		Set_Direction(Direction_Left);
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.dX += m_dSpeed;
		Set_Direction(Direction_Right);
	}

	if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.dY -= m_dSpeed;
		Set_Direction(Direction_UP);
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.dY += m_dSpeed;
		Set_Direction(Direction_Down);
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		m_Bullet_List->push_back(new CBullet(*static_cast<CObj*>(this)));
	}
}
