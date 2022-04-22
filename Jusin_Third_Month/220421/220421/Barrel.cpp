#include "stdafx.h"
#include "Barrel.h"


CBarrel::CBarrel()
	: m_pPlayerInfo(nullptr)
	, m_dCos(0)
	, m_dReverse(1)
{
	m_dSpeed = 2;
}


CBarrel::~CBarrel()
{
}

void CBarrel::Initialize(void)
{
	m_tInfo.dX = m_pPlayerInfo->dX + (m_dCos);
	m_tInfo.dY = m_pPlayerInfo->dY - (m_pPlayerInfo->dCY);
}

void CBarrel::Update(void)
{
	Key_Input();

	m_tInfo.dX = m_pPlayerInfo->dX - (m_dCos);
	m_tInfo.dY = m_pPlayerInfo->dY - ((sqrt(((m_pPlayerInfo->dCX) * (m_pPlayerInfo->dCX)) - (m_dCos * m_dCos))) * m_dReverse);
}

void CBarrel::Late_Update(void)
{
	if (m_dCos >= (m_pPlayerInfo->dCX) || m_dCos <= (-(m_pPlayerInfo->dCX)))
	{
		m_dReverse *= -1;
	}
}

void CBarrel::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_pPlayerInfo->dX, (int)m_pPlayerInfo->dY, nullptr);

	LineTo(hDC, (int)m_tInfo.dX, (int)m_tInfo.dY);
}

void CBarrel::Release(void)
{
}

void CBarrel::Key_Input(void)
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_dCos += (m_dReverse * m_dSpeed);
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_dCos -= (m_dReverse * m_dSpeed);
	}
}
