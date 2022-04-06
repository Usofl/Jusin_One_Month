#include "stdafx.h"
#include "Game.h"

CGame::CGame()
	: m_Player(nullptr)
{
	m_vecFeild.reserve(2);

	m_vecFeild.push_back(new CHunting);
	m_vecFeild.push_back(new CShop);
}

CGame::~CGame()
{
	Release();
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

		if (Job_Start < iChoice && Job_End > iChoice)
		{
			m_Player = new CPlayer;

			m_Player->Init_Stat(iChoice);
			break;
		}
		else if (Job_End == iChoice)
		{
			cout << "������ �����մϴ�." << endl;
			break;
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
	int iChoice = 0;

	while (m_Player != nullptr)
	{
		system("cls");
		m_Player->Render();
		cout << "1. ����� 2. ���� 3. �κ��丮 4. ����" << endl;
		cin >> iChoice;

		if (Feild_Start < iChoice && Feild_End > iChoice)
		{
			if (Feild_Inventory != iChoice)
			{
				m_vecFeild[iChoice - 1]->Set_Player(m_Player);
				m_vecFeild[iChoice - 1]->Initialize();
				m_vecFeild[iChoice - 1]->Update();
			}
			else
			{
				static_cast<CPlayer*>(m_Player)->Show_Inventory();
			}
		}
		else if (Feild_End == iChoice)
		{
			cout << "������ �����մϴ�." << endl;
			return;
		}
		else
		{
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		}
		system("pause");
	}
}

void CGame::Release()
{
	for_each(m_vecFeild.begin(), m_vecFeild.end(), CDelete<CFeild*>());
	CDelete<CStatus*>()(m_Player);
}
