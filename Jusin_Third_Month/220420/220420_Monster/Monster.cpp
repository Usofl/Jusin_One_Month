#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
	: CObj()
{
}


CMonster::~CMonster()
{
}

void CMonster::Initialize(void)
{
	m_tInfo.dX = ((GetTickCount() % 56) + 13) * 10 ;
	m_tInfo.dY = 150.0;

	m_tInfo.dCX = 50.0;
	m_tInfo.dCY = 50.0;

	m_dSpeed = 10.0;

	m_Direction = DIRECTION_LEFT;
}

void CMonster::Update(void)
{
	switch (m_Direction)
	{
	case DIRECTION_LEFT:
		m_tInfo.dX -= m_dSpeed;
		break;

	case DIRECTION_RIGHT:
		m_tInfo.dX += m_dSpeed;
		break;
	}

	Update_Rect();
}

void CMonster::Late_Update(void)
{
	if (m_tRect.left <= 100 || m_tRect.right >= WINCX - GAME_SIZE)
	{
		Reverse_Dit();
	}
}

void CMonster::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonster::Release(void)
{
}

void CMonster::Attacked_Bullet(std::list<CObj*>& _BulletList)
{
	RECT rc = {0,0,0,0};

	for (auto& iter : _BulletList)
	{
		if (IntersectRect(&rc, &m_tRect, &iter->Get_Rect()) && !iter->Get_Dead())
		{
			m_bDead = true;
			iter->Set_Dead(true);
		}
	}
}

void CMonster::Reverse_Dit()
{
	if (m_Direction == DIRECTION_LEFT)
	{
		m_Direction = DIRECTION_RIGHT;
	}
	else
	{
		m_Direction = DIRECTION_LEFT;
	}
}
