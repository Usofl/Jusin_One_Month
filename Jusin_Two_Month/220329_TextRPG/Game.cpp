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

		cout << "1. ���� 2. ������ 3. ���� 4. ����" << endl;
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
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
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

		cout << "1. ����� 2. ���� 3. ����" << endl;
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