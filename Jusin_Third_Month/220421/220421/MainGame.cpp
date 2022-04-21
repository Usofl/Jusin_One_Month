#include "stdafx.h"
#include "MainGame.h"


CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
}

void CMainGame::Initialize(void)
{
	m_hDC = GetDC(g_hWnd);

	m_ObjList[OBJ_PLAYER].push_back(AbstractFactory<CPlayer>::Create());
	m_ObjList[OBJ_PLAYER].front()->Initialize();

	static_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_Bullet_List(&m_ObjList[OBJ_BULLET]);
}

void CMainGame::Update(void)
{
	Key_Input();

	for (auto& List_iter : m_ObjList)
	{
		for (auto iter = List_iter.begin(); iter != List_iter.end();)
		{
			if (!(*iter)->Get_Dead())
			{
				(*iter)->Update();
				++iter;
			}
			else
			{
				iter = List_iter.erase(iter);
			}
		}
	}
}

void CMainGame::Late_Update(void)
{
	for (int i = 0; i < OBJ_MONSTER; ++i)
	{
		for (auto& Obj_Iter : m_ObjList[i])
		{
			Obj_Iter->Late_Update();
		}
	}

	for (auto& Obj_Iter : m_ObjList[OBJ_MONSTER])
	{
		Obj_Iter->Late_Update();
		static_cast<CMonster*>(Obj_Iter)->Attacked_Bullet(m_ObjList[OBJ_BULLET]);
	}
}

void CMainGame::Render(void)
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	Rectangle(m_hDC, GAME_SIZE, GAME_SIZE, WINCX - GAME_SIZE, WINCY - GAME_SIZE);

	for (auto& List_iter : m_ObjList)
	{
		for (auto& Obj_Iter : List_iter)
		{
			Obj_Iter->Render(m_hDC);
		}
	}
}

void CMainGame::Release(void)
{
	for (auto& List_iter : m_ObjList)
	{
		for (auto& Obj_Iter : List_iter)
		{
			Safe_Delete<CObj*>(Obj_Iter);
		}
		List_iter.clear();
	}

	ReleaseDC(g_hWnd, m_hDC);
}

void CMainGame::Key_Input(void)
{
	if (GetAsyncKeyState('R'))
	{
		CObj* Monster = AbstractFactory<CMonster>::Create();
		Monster->Initialize();

		m_ObjList[OBJ_MONSTER].push_back(Monster);
	}
}
