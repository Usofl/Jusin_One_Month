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

	cout << "1. �ʱ� 2. �߱� 3. ��� 4. �ڷΰ���" << endl;
	cin >> iChoice;

	switch (iChoice)
	{
	case 1:
		if (m_monster == nullptr)
		{
			m_monster = new CMonster;
		}

		m_monster->get_Status()->Set_Status("�ʱ�", 3, 30);


		break;

	case 2:
		if (m_monster == nullptr)
		{
			m_monster = new CMonster;
		}

		m_monster->get_Status()->Set_Status("�߱�", 15, 70);
		break;

	case 3:
		if (m_monster == nullptr)
		{
			m_monster = new CMonster;
		}

		m_monster->get_Status()->Set_Status("���", 30, 100);
		break;

	case 4:
		return;
		break;

	default:
		cout << "�߸��Է��ϼ̽��ϴ�." << endl;
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

		cout << "1. ���� 2. ����" << endl;
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			cout << "����!.." << endl;
			m_monster->get_Status()->Set_Damage(m_player->get_Status()->Get_Attack_Point());

			if (0 >= m_monster->get_Status()->Get_Lest_HP())
			{
				cout << "�¸�" << endl;
				return;
			}

			m_player->get_Status()->Set_Damage(m_monster->get_Status()->Get_Attack_Point());

			if (0 >= m_player->get_Status()->Get_Lest_HP())
			{
				cout << "�й�.." << endl;
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