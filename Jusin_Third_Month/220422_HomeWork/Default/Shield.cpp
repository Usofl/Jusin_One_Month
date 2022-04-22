#include "stdafx.h"
#include "Shield.h"


CShield::CShield()
{
}


CShield::~CShield()
{
	Release();
}

void CShield::Initialize(void)
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;

	m_fSpeed = 10.f;
}

int CShield::Update(void)
{
	return 0;
}

void CShield::Late_Update(void)
{
}

void CShield::Render(HDC hDC)
{
}

void CShield::Release(void)
{
}
