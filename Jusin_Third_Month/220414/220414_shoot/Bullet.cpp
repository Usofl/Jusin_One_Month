#include "stdafx.h"
#include "Bullet.h"

CBullet::CBullet(RECT _rc, Bullet _Direction)
	: rc(_rc)
	, eDirection(_Direction)
{
}

CBullet::~CBullet()
{
}

void CBullet::shoot()
{
	switch (eDirection)
	{
	case Bullet_UP:
		rc.top -= 10;
		rc.bottom -= 10;
		break;

	case Bullet_Down:
		rc.top += 10;
		rc.bottom += 10;
		break;

	case Bullet_Left:
		rc.left -= 10;
		rc.right -= 10;
		break;

	case Bullet_Right:
		rc.left += 10;
		rc.right += 10;
		break;

	default:
		break;
	}
}

bool CBullet::Hit_Monster(std::list<CMonster*>& _mlist)
{
	for (auto& iter : _mlist)
	{
		RECT mRc = iter->Get_RECT();

		if (mRc.left <= rc.right && mRc.right >= rc.left && mRc.bottom >= rc.top)
		{
			iter->Dead();
			return true;
		}
	}

	return false;
}
