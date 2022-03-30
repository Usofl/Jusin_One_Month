#include "stdafx.h"
#include "Game.h"

CGame::CGame()
{

}

CGame::~CGame()
{

}

void CGame::Initialize()
{
	assert(nullptr == m_Player);

	int iChoice = 0;
	while (true)
	{
		system("cls");

		cout << "1. 전사 2. 마법사 3. 도적 4. 종료" << endl;
		cin >> iChoice;

		if (1 <= iChoice && 3 >= iChoice)
		{
			m_Player = new CPlayer;
			m_Player->Init_Stat(iChoice);
			return;
		}
		else if (4 == iChoice)
		{
			return;
		}
		else
		{
			cout << "잘못 입력하셨습니다." << endl;
			continue;
		}
	}
}

void CGame::Update()
{
	int iChoice = 0;
	while (true)
	{
		system("cls");
		m_Player->Render();

		cout << "1. 사냥터 2. 상점 3. 종료" << endl;
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			m_Feild = new CHunting;
			m_Feild->Set_Player(m_Player);
			m_Feild->Initialize();
			m_Feild->Update();
			break;

		case 2:
			break;

		case 3:
			Release();
			return;
			break;

		default:
			break;
		}

		SAFE_DELETE(m_Feild);

		system("pause");
	}
}

void CGame::Release()
{
	SAFE_DELETE(m_Player);
	SAFE_DELETE(m_Feild);
}