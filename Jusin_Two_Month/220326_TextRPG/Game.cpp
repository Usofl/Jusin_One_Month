#include "stdafx.h"
#include "Game.h"

CGame::CGame()
	: m_Player(nullptr)
	, m_Feild(nullptr)
	, m_Shop(nullptr)
{

}

CGame::~CGame()
{
	Release();
}

void CGame::Initialize()
{
	assert(m_Player == nullptr);

	m_Player = new CPlayer;

	while (true)
	{
		system("cls");

		cout << "1. 전사 2. 마법사 3. 도적" << endl;
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			m_Player->Get_pStatus()->Init_Stat("전사", 10, 100);
			return;

		case 2:
			m_Player->Get_pStatus()->Init_Stat("마법사", 10, 100);
			return;

		case 3:
			m_Player->Get_pStatus()->Init_Stat("도적", 10, 100);
			return;

		default:
			break;
		}
	}
}

void CGame::Update()
{
	assert(m_Player != nullptr);

	while (true)
	{
		system("cls");

		m_Player->Render();
		cout << "=================================" << endl;

		cout << "1. 사냥터 2. 상점 3. 인벤토리 4. 종료" << endl;
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			if (m_Feild == nullptr)
			{
				m_Feild = new CFeild;
				m_Feild->Set_Player(m_Player);
			}
			m_Feild->Initialize();
			m_Feild->Update();

			break;

		case 2:
			if (m_Shop == nullptr)
			{
				m_Shop = new CShop;
				m_Shop->Set_Player(m_Player);
			}

			m_Shop->Initialize();
			m_Shop->Update();

			break;

		case 3:
			m_Player->My_Inventory();
			break;

		case 4:
			return;
			break;

		default:
			break;
		}

		system("pause");
	}
}

void CGame::Release()
{
	if (nullptr != m_Player)
	{
		delete m_Player;
	}

	if (nullptr != m_Feild)
	{
		delete m_Feild;
	}

	if (nullptr != m_Shop)
	{
		delete m_Shop;
	}

	m_Player = nullptr;
	m_Feild = nullptr;
	m_Shop = nullptr;
}