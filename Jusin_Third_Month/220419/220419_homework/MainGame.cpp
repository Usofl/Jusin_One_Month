#include "stdafx.h"
#include "MainGame.h"
#include "Player.h"


CMainGame::CMainGame()
	: m_pPlayer(nullptr)
	, m_rcArea({ 50, 50, WINCX - 50, WINCY - 50 })
{
	m_Bullet_List.clear();
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_hDC = GetDC(g_hWnd);

	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();

		static_cast<CPlayer*>(m_pPlayer)->Set_Bullet_List(m_Bullet_List);
	}
}

void CMainGame::Update(void)
{
	m_pPlayer->Update();

	if (!m_Bullet_List.empty())
	{
		for (auto iter = m_Bullet_List.begin(); iter != m_Bullet_List.end(); ++iter)
		{
			if (static_cast<CBullet*>(*iter)->Escape_Bullet(m_rcArea))
			{
				delete *iter;
				iter = m_Bullet_List.erase(iter);

				if (iter == m_Bullet_List.end())
				{
					break;
				}
			}
			else
			{
				(*iter)->Update();
			}
		}
	}
}

void CMainGame::Render(void)
{
	Rectangle(m_hDC, m_rcArea.left, m_rcArea.top, m_rcArea.right, m_rcArea.bottom);

	m_pPlayer->Render(m_hDC);

	if (!m_Bullet_List.empty())
	{
		for (auto iter = m_Bullet_List.begin(); iter != m_Bullet_List.end(); ++iter)
		{
			(*iter)->Render(m_hDC);
		}
	}
}

void CMainGame::Release(void)
{
	Safe_Delete<CObj*>(m_pPlayer);

	ReleaseDC(g_hWnd, m_hDC);
}
