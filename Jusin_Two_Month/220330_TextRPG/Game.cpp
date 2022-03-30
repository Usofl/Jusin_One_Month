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

		cout << "1. ���� 2. ������ 3. ���� 4. ����" << endl;
		cin >> iChoice;

		if (Job_Start < iChoice && Job_Exit > iChoice)
		{
			m_Player->Initialize(iChoice);
			return;
		}
		else if (4 == Job_Exit)
		{
			cout << "������ �����մϴ�." << endl;
			Release();
			return;
		}
		else
		{
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
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

		cout << "1. ����� 2. ���� 3. �κ��丮 4. ����" << endl;
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
			cout << "������ �����մϴ�." << endl;
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
