#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Feild.h"

CGame::CGame()
{
	m_player = nullptr;
	m_feild = nullptr;
}

CGame::~CGame()
{
	Release();
	
	if (m_feild != nullptr)
	{
		delete m_feild;
		m_feild = nullptr;
	}
}

void CGame::Initialize()
{
	int iChoice = 0;

	while (m_player == nullptr)
	{

		cout << "1. 전사 2. 마법사 3. 도적 4. 종료" << endl;
		cin >> iChoice;

		m_player = new CPlayer;

		switch (iChoice)
		{
		case 1:
			m_player->get_Status()->Set_Status("전사", 10, 100);
			break;

		case 2:
			m_player->get_Status()->Set_Status("마법사", 10, 100);
			break;

		case 3:
			m_player->get_Status()->Set_Status("도적", 10, 100);
			break;

		case 4:
			return;
			break;

		default:
			Release();
			continue;
		}
	}
}

void CGame::Update()
{
	if (m_player == nullptr)
	{
		return;
	}

	int iChoice = 0;

	while (true)
	{
		system("cls");
		m_player->get_Status()->Rander();

		cout << "1. 사냥터 2. 상점 3. 종료" << endl;
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			if (m_feild == nullptr)
			{
				m_feild = new CFeild;
			}

			m_feild->Set_Player(m_player);
			m_feild->Update();

			break;

		case 2:
			break;

		case 3:
			return;
			break;
		
		default:
			continue;
		}

		system("pause");
	}
}

void CGame::Release()
{
	if (m_player != nullptr)
	{
		delete m_player;
		m_player = nullptr;
	}
}