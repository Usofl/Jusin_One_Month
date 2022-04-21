#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
	: CObj()
	, m_Barrel(new CBarrel)
	, m_Bullet_List(nullptr)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo.dX = 400.0;
	m_tInfo.dY = 300.0;

	m_tInfo.dCX = 100.0;
	m_tInfo.dCY = 100.0;

	m_dSpeed = 0.01;

	m_Barrel->Set_Player_Info(&m_tInfo);
	m_Barrel->Set_Player_Rect(&m_tRect);
	m_Barrel->Initialize();

	m_Direction = DIRECTION_UP;
}

void CPlayer::Update(void)
{
	Key_Input();

	m_Barrel->Update();

	Update_Rect();
}

void CPlayer::Late_Update(void)
{
	m_Barrel->Late_Update();
}

void CPlayer::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	m_Barrel->Render(hDC);
}

void CPlayer::Release(void)
{
	Safe_Delete<CBarrel*>(m_Barrel);
}

void CPlayer::Key_Input(void)
{
	if (GetAsyncKeyState(VK_UP))
	{
		if ((m_tRect.top >= GAME_SIZE || m_tRect.bottom <= WINCY - GAME_SIZE)
			&& (m_tRect.left >= GAME_SIZE || m_tRect.right <= WINCX - GAME_SIZE))
		{
			m_tInfo.dX += (m_dSpeed * m_Barrel->Get_Dir_X());
			m_tInfo.dY += (m_dSpeed * m_Barrel->Get_Dir_Y());
		}
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		if ((m_tRect.top >= GAME_SIZE || m_tRect.bottom <= WINCY - GAME_SIZE)
			 && (m_tRect.left >= GAME_SIZE || m_tRect.right <= WINCX - GAME_SIZE) )
		{
			m_tInfo.dX -= (m_dSpeed * m_Barrel->Get_Dir_X());
			m_tInfo.dY -= (m_dSpeed * m_Barrel->Get_Dir_Y());
		}
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		m_Bullet_List->push_back(new CBullet(*this, m_Barrel->Get_Dir_X(), m_Barrel->Get_Dir_Y()));
	}
}
