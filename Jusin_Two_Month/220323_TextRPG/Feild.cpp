#include "stdafx.h"
#include "Feild.h"
#include "Player.h"
#include "Monster.h"

CFeild::CFeild()
{
}

CFeild::~CFeild()
{
	Release();
}

void CFeild::Initialize()
{
}

void CFeild::Update()
{
	if (m_player == nullptr)
	{
		return;
	}

	int iChoice = 0;

	system("cls");
	m_player->get_Status()->Rander();

	cout << "1. 초급 2. 중급 3. 고급 4. 뒤로가기" << endl;
	cin >> iChoice;

	switch (iChoice)
	{
	case 1:
		if (m_monster == nullptr)
		{
			m_monster = new CMonster;
		}

		m_monster->get_Status()->Set_Status("초급", 3, 30);


		break;

	case 2:
		if (m_monster == nullptr)
		{
			m_monster = new CMonster;
		}

		m_monster->get_Status()->Set_Status("중급", 15, 70);
		break;

	case 3:
		if (m_monster == nullptr)
		{
			m_monster = new CMonster;
		}

		m_monster->get_Status()->Set_Status("고급", 30, 100);
		break;

	case 4:
		return;
		break;

	default:
		cout << "잘못입력하셨습니다." << endl;
		Update();
		return;
		break;
	}

	Hunting_Monster();
}

void CFeild::Release()
{
	if (m_monster != nullptr)
	{
		delete m_monster;
		m_monster = nullptr;
	}
}

void CFeild::Set_Player(CPlayer * _player)
{
	m_player = _player;
}

void CFeild::Hunting_Monster()
{
	if (m_player == nullptr || m_monster == nullptr)
	{
		return;
	}

	int iChoice = 0;

	while (true)
	{
		system("cls");
		m_player->get_Status()->Rander();
		m_monster->get_Status()->Rander();

		cout << "1. 공격 2. 도망" << endl;
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			cout << "공격!.." << endl;
			m_monster->get_Status()->Set_Damage(m_player->get_Status()->Get_Attack_Point());

			if (0 >= m_monster->get_Status()->Get_Lest_HP())
			{
				cout << "승리" << endl;
				return;
			}

			m_player->get_Status()->Set_Damage(m_monster->get_Status()->Get_Attack_Point());

			if (0 >= m_player->get_Status()->Get_Lest_HP())
			{
				cout << "패배.." << endl;
				m_player->get_Status()->Set_Lest_Max_HP();
				return;
			}

			break;

		case 2:
			break;

		default:
			continue;
		}
	}
}