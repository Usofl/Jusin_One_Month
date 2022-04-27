#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
	: m_fSpeed(0.f)
	, m_fAngle(0.f)
	, m_tInfo({ 0,0,0,0 })
	, m_tRect({ 0,0,0,0 })
	, m_tPoint({ 0,0 })
	, m_iReverse(1)
{
}


CObj::~CObj()
{
}

void CObj::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - (m_tInfo.fCX * 0.5f));
	m_tRect.top = LONG(m_tInfo.fY - (m_tInfo.fCY * 0.5f));
	m_tRect.right = LONG(m_tInfo.fX + (m_tInfo.fCX * 0.5f));
	m_tRect.bottom = LONG(m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}
