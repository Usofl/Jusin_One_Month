#pragma once
#include "Obj.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	void		Key_Input(void);

	/*

	D3DXVECTOR3		m_vPlayerPos;	// ��ġ ����

	D3DXVECTOR3		m_vPlayerDir;	// ���� ����
	D3DXVECTOR3		m_vPlayerLook;	// ���� ����

	D3DXVECTOR3		m_vPlayerNormal;	// ���� ����*/
};

