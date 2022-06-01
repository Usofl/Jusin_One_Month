#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo.vPos = { 400.f, 300.f, 0.f };
	m_tInfo.vDir = { 1.f, 0.f, 0.f };

	m_vRectPoint[0] = { - 50.f, - 50.f, 0.f };
	m_vRectPoint[1] = { 50.f, -50.f, 0.f };
	m_vRectPoint[2] = { 50.f, 50.f, 0.f };
	m_vRectPoint[3] = { - 50.f, 50.f, 0.f };

	m_fAngle = 90.f;
	m_fPosinAngle = m_fAngle;

	for (int i = 0; i < 4; ++i)
	{
		m_vDrawPoint[i] = m_vRectPoint[i] + m_tInfo.vPos;
	}

	m_fSpeed = 3.f;
	// 크기 변환 행렬 생성 함수
	D3DXMatrixScaling(&m_matScale, 1.f, 1.f, 1.f);

}

void CPlayer::Update(void)
{
	// 연산을 진행
	Key_Input();

	//m_tInfo.vPos += m_tInfo.vDir;

	D3DXMATRIX	matRotZ, matTrans;
	// dx에서 제공하는 행렬 함수는 매개 변수로 넣어주는 행렬을 먼저 항등 행렬로 초기화 한 후, 값 적용을 수행한다.
	m_fRadian = D3DXToRadian(m_fAngle);

	// z축 회전 행렬 생성 함수
	D3DXMatrixRotationZ(&matRotZ, m_fRadian);

	// 이동 행렬 생성 함수
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, m_tInfo.vPos.z);

	m_tInfo.matWorld = m_matScale * matRotZ * matTrans;

	//float fX = ((m_tInfo.matWorld._41) * (m_tInfo.matWorld._11)) - ((m_tInfo.matWorld._42) * (m_tInfo.matWorld._12));
	//float fY = ((m_tInfo.matWorld._41) * (m_tInfo.matWorld._21)) + ((m_tInfo.matWorld._42) * (m_tInfo.matWorld._22));
	

	for (int i = 0; i < 4; ++i)
	{
		m_vDrawPoint[i].x = (m_vRectPoint[i].x * m_tInfo.matWorld._11) - (m_vRectPoint[i].y * -m_tInfo.matWorld._12);
		m_vDrawPoint[i].y = (m_vRectPoint[i].x * m_tInfo.matWorld._21) + (m_vRectPoint[i].y * m_tInfo.matWorld._22);

		m_vDrawPoint[i] += m_tInfo.vPos;

		//m_vDrawPoint[i].x = (m_vRectPoint[i].x * cosf(m_fRadian)) - (m_vRectPoint[i].y * -sinf(m_fRadian)) + m_tInfo.vPos.x;
		//m_vDrawPoint[i].y = (m_vRectPoint[i].x * -sinf(m_fRadian)) + (m_vRectPoint[i].y * cosf(m_fRadian)) + m_tInfo.vPos.y;
	}

	// 벡터와 행렬의 곱셈을 수행해주는 dx 함수

	// 위치 벡터와 행렬을 곱셈하여 최종적인 위치 벡터를 반환하는 함수
	//D3DXVec3TransformCoord(&vPos, &vPos, &m_tInfo.matWorld);

	// 위치 벡터와 행렬을 곱셈하여 최종적인 방향 벡터를 반환하는 함수
	//D3DXVec3TransformNormal(&vDir, &vDir, &m_tInfo.matWorld);

}

void CPlayer::Render(HDC hDC)
{
	MoveToEx(hDC, int(m_vDrawPoint[0].x), int(m_vDrawPoint[0].y), nullptr);
	
	LineTo(hDC, int(m_vDrawPoint[1].x), int(m_vDrawPoint[1].y));
	
	LineTo(hDC, int(m_vDrawPoint[2].x), int(m_vDrawPoint[2].y));
	
	LineTo(hDC, int(m_vDrawPoint[3].x), int(m_vDrawPoint[3].y));
	
	LineTo(hDC, int(m_vDrawPoint[0].x), int(m_vDrawPoint[0].y));

	MoveToEx(hDC, int(m_tInfo.matWorld._41), int(m_tInfo.matWorld._42), nullptr);

	LineTo(hDC, int((m_tInfo.matWorld._41) + (100.f * cosf(D3DXToRadian(m_fPosinAngle)))),int(((m_tInfo.matWorld._42) - (100.f * sin(D3DXToRadian(m_fPosinAngle))))));
	//Rectangle(hDC,
	//	int(m_tInfo.matWorld._41 - 50.f),
	//	int(m_tInfo.matWorld._42 - 50.f),
	//	int(m_tInfo.matWorld._41 + 50.f),
	//	int(m_tInfo.matWorld._42 + 50.f));
}

void CPlayer::Release(void)
{

}

void CPlayer::Key_Input(void)
{
	 //GetKeyState
	if (GetAsyncKeyState(VK_LEFT))
	{
		//m_tInfo.vPos.x -= m_fSpeed;
		m_fAngle += 3.f;
		m_fPosinAngle += 3.f;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
	//	m_tInfo.vPos.x += m_fSpeed;
		m_fAngle -= 3.f;
		m_fPosinAngle -= 3.f;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.vPos.x += m_fSpeed * cosf(m_fRadian);
		m_tInfo.vPos.y -= m_fSpeed * sinf(m_fRadian);
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.vPos.x -= m_fSpeed * cosf(m_fRadian);
		m_tInfo.vPos.y += m_fSpeed * sinf(m_fRadian);
	}

	if (GetAsyncKeyState('A'))
	{
		m_fPosinAngle += 3.f;
	}

	if (GetAsyncKeyState('D'))
	{
		m_fPosinAngle -= 3.f;
	}
}
