#include "stdafx.h"
#include "Game.h"

CGame::CGame()
{
	m_Player = nullptr;
}

CGame::~CGame()
{
	delete m_Player;
}

bool CGame::Main_Game()
{
	int iChoice = 0;

	if (nullptr == m_Player)
	{
		cout << "1. ���� 2. ������ 3. ���� 4. �ҷ����� 5. ����" << endl;
		cin >> iChoice;

		if (3 >= iChoice && 1 <= iChoice)
		{
			m_Player = new CPlayer(iChoice);
		}
		else if (iChoice == 5)
		{
			cout << "������ �����մϴ�." << endl;
			return false;
		}
		else
		{
			return true;
		}
	}

	system("cls");

	m_Player->Rander();

	cout << "1. ����� 2. ���� 3. ����" << endl;

	cin >> iChoice;

	switch (iChoice)
	{
	case 1:
		m_Hunting.Hunting_Menu(m_Player);
		break;

	case 2:
		break;

	case 3:
		return false;
		break;

	default:
		break;
	}

	system("pause");
	return true;
}
