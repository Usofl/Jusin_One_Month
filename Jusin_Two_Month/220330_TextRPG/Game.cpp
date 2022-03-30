#include "stdafx.h"
#include "Game.h"

CGame::CGame()
	: m_Player(nullptr)
	, m_Feild (nullptr)
{

}

CGame::~CGame()
{
	Release();
}

void CGame::Initialize()
{
	assert(m_Player == nullptr);
	int iChoice = 0;

	while (true)
	{
		system("cls");

		m_Player = new CPlayer;

		cout << "1. 전사 2. 마법사 3. 도적 4. 종료" << endl;
		cin >> iChoice;

		if (Job_Start < iChoice && Job_Exit > iChoice)
		{
			m_Player->Initialize(iChoice);
			return;
		}
		else if (4 == Job_Exit)
		{
			cout << "게임을 종료합니다." << endl;
			Release();
			return;
		}
		else
		{
			cout << "잘못 입력하셨습니다." << endl;
			system("pause");
		}
	}
}

void CGame::Update()
{
	if (m_Player == nullptr)
	{
		return;
	}

	assert(m_Player != nullptr);
	int iChoice = 0;

	while (true)
	{
		system("cls");
		m_Player->Render();

		cout << "1. 사냥터 2. 상점 3. 인벤토리 4. 종료" << endl;
		cin >> iChoice;

		switch (iChoice)
		{
		case Feild_Hunting:
			assert(m_Feild == nullptr);
			m_Feild = new CHunting;
			Start_Feild();
			break;
		
		case Feild_Shop:
			/*
			assert(m_Feild == nullptr);
			m_Feild = new CShop;

			Start_Feild();
			*/
			break;

		case Feild_Inventory:
			break;

		case Feild_Exit:
			cout << "게임을 종료합니다." << endl;
			Release();
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
	SAFE_DELETE(m_Player);
	SAFE_DELETE(m_Feild);
}

void CGame::Start_Feild()
{
	m_Feild->Set_Player(m_Player);
	m_Feild->Initialize();
	m_Feild->Update();

	SAFE_DELETE(m_Feild);
}
