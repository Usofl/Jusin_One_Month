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

private:
	D3DXMATRIX	m_matScale;
	float m_fAngle;
	float m_fRadian;

	float m_fPosinAngle;

	D3DXVECTOR3		m_vRectPoint[4];
	D3DXVECTOR3		m_vDrawPoint[4];

	D3DXVECTOR3		m_vPosin;
	/*

	D3DXVECTOR3		m_vPlayerPos;	// ¿ßƒ° ∫§≈Õ

	D3DXVECTOR3		m_vPlayerDir;	// πÊ«‚ ∫§≈Õ
	D3DXVECTOR3		m_vPlayerLook;	// πÊ«‚ ∫§≈Õ

	D3DXVECTOR3		m_vPlayerNormal;	// π˝º± ∫§≈Õ*/
};

