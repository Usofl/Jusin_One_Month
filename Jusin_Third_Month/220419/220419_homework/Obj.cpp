#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
	: m_dSpeed(0.0)
	, m_Direction(Direction_UP)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
}


CObj::~CObj()
{
}

void CObj::Update_Rect(void)
{
	m_tRect.left = long(m_tInfo.dX - (m_tInfo.dCX * 0.5));
	m_tRect.top = long(m_tInfo.dY - (m_tInfo.dCY * 0.5));
	m_tRect.right = long(m_tInfo.dX + (m_tInfo.dCX * 0.5));
	m_tRect.bottom = long(m_tInfo.dY + (m_tInfo.dCY * 0.5));
}
