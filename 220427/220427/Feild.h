#pragma once
#include "Obj.h"

class CFeild :
	public CObj
{
public:
	CFeild();
	virtual ~CFeild();

	// CObj��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC _hDC) override;
	virtual void Release(void) override;
};

