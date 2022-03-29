#include "stdafx.h"
#include "Game.h"

CGame::CGame()
	: m_Player(nullptr)
{

}
CGame::~CGame()
{
	Release();
}

void CGame::Initialize()
{
	assert(m_Player == nullptr);

	while (true)
	{
		system("cls");

		cout << "1. 전사 2. 마법사 3. 도적 4. 종료" << endl;
		cin >> iChoice;

		if (1 <= iChoice && 3 >= iChoice)
		{
			m_Player = new CPlayer;

			m_Player->Init_Player(iChoice);

			return;
		}
		else if (4 == iChoice)
		{
			return;
		}
		else
		{
			cout << "잘못 입력하셨습니다." << endl;
			system("pause");
			continue;
		}
	}
}

void CGame::Update()
{
	if (m_Player == nullptr)
	{
		return;
	}

	while (true)
	{
		system("cls");

		m_Player->Render_Player();

		CConsum* p = nullptr;

		cout << "1. 사냥터 2. 상점 3. 인벤토리 4. 종료" << endl;
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			if (nullptr == m_Feild)
			{
				m_Feild = new CFeild;
			}

			m_Feild->Set_Player(m_Player);
			m_Feild->Initialize();
			m_Feild->Update();

			break;

		case 2:
			if (nullptr == m_Shop)
			{
				m_Shop = new CShop;
			}

			m_Shop->Set_Player(m_Player);
			m_Shop->Initialize();
			m_Shop->Update();

			break;

		case 3:
			p = m_Player->Get_Inventory()->My_Inventory();
			if (p != nullptr)
			{
				m_Player->Use_Consum(p);
			}
			m_Player->Cheak_Wearing();
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
	SAFE_DELETE(m_Player);
}