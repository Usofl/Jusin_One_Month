#pragma once
#include "Obj.h"
class CBullet :
	public CObj
{
public:
	CBullet(CObj& _rObj,const double& _dShotX, const double& _dShotY );
	virtual ~CBullet();

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	bool Escape_Bullet();

private:
	double m_dShotDirX;
	double m_dShotDirY;
};

