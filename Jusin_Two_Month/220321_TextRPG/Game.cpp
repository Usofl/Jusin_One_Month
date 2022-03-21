#include "stdafx.h"
#include "Game.h"

bool CGame::Menu()
{
	if (m_player == nullptr)
	{
		m_player = new CPlayer;
		if (!m_player->Init_Player())
		{
			delete m_player;
			m_player = nullptr;
			return true;
		}
	}

	system("cls");

	m_player->Print_Player_Info();

	int iChoice = 0;

	cout << "1. 사냥터 2. 상점 3. 종료" << endl;

	cin >> iChoice;

	switch (iChoice)
	{
	case 1:
		m_hunting.Hunting_Menu(m_player);
		break;

	case 2:
		break;

	case 3:
		return false;
		break;

	default:
		break;
	}

	return true;
}