#include "stdafx.h"
#include "Game.h"

CGame::CGame()
	: m_player(nullptr)
	, m_Feild(nullptr)
{

}

CGame::~CGame()
{
	Release();
}

void CGame::Initialize()
{
	Release();
	m_player = new CPlayer;

	cout << "1. ���� 2. ������ 3. ����" << endl;
	cout << "==============================" << endl;

	int iChoice = 0;

	while (true)
	{
		cin >> iChoice;

		switch (iChoice)
		{
		case Warrior:
			m_player->Get_Status()->Init_Stat("����", 10, 100);
			break;

		case Magicion:
			m_player->Get_Status()->Init_Stat("������", 10, 100);
			break;

		case Sife:
			m_player->Get_Status()->Init_Stat("����", 10, 100);
			break;

		default:
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			break;
		}

		if (0 != m_player->Get_Status()->Get_Attack_Point())
		{
			return;
		}
	}
}

void CGame::Update()
{
	if (m_player == nullptr)
	{
		return;
	}

	while(true)
	{
		system("cls");
		m_player->Get_Status()->Render();

		int iChoice = 0;

		cout << "1. ����� 2. ���� 3. ����" << endl;
		cin >> iChoice;

		switch (iChoice)
		{

		case Hunting:
			if (m_Feild == nullptr)
			{
				m_Feild = new CFeild(m_player);
			}

			m_Feild->Initialize();
			m_Feild->Update();

			break;

		case Shop:
			break;

		case Lobby_Exit:
			return;
			break;

		default:
			break;
		}
	}

	system("pause");
}

void CGame::Release()
{
	if (m_player != nullptr)
	{
		delete m_player;
	}

	if (m_Feild != nullptr)
	{
		delete m_Feild;
	}

	m_player = nullptr;
	m_Feild = nullptr;
}