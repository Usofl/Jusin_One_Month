#include "stdafx.h"
#include "Maingame.h"

CMainGame::CMainGame()
	: m_dwTime(GetTickCount())
	, m_iFPS(0)
{
	ZeroMemory(m_szFPS, sizeof(TCHAR) * 64);
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_Objlist[OBJ_PLAYER].push_back(new CPlayer);
	m_Objlist[OBJ_PLAYER].back()->Initialize();
	m_Objlist[OBJ_FEILD].push_back(new CFeild);
}

void CMainGame::Update(void)
{
	
}

void CMainGame::Late_Update(void)
{
}

void CMainGame::Render(void)
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	//Rectangle(m_hDC, GAMESIZE, GAMESIZE, WINCX - GAMESIZE, WINCY - GAMESIZE);

	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount())   // GetTickCount() 1000���� 1��
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount();
	}
}

void CMainGame::Release(void)
{
	for (auto& List_iter : m_Objlist)
	{
		for (auto iter = List_iter.begin(); iter != List_iter.end();)
		{
			(*iter)->Release();
			Safe_Delete<CObj*>(*iter);
			iter = List_iter.erase(iter);
		}
	}
}

void CMainGame::Key_Input(void)
{
	if (GetAsyncKeyState('R')) // ������ ī��Ʈ �߰�
	{
		
	}
}
