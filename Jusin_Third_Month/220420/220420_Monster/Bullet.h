#pragma once
#include "Obj.h"
class CBullet :
	public CObj
{
public:
	CBullet(CObj& _rObj);
	virtual ~CBullet();

public:
	// CObj��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	bool Escape_Bullet();
};

