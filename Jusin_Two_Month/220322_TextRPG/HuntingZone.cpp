#include "stdafx.h"
#include "HuntingZone.h"

CHuntingZone::CHuntingZone()
{
	m_monster = nullptr;
}

CHuntingZone::~CHuntingZone()
{
	delete m_monster;
}

void CHuntingZone::Hunting_Menu(CPlayer * _player)
{
	system("cls");
	int iChoice = 0;

	_player->Rander();

	cout << "1. �ʱ� 2. �߱� 3. ��� 4. �ڷΰ���" << endl;
	cin >> iChoice;

	if (3 >= iChoice && 1 <= iChoice)
	{
		m_monster = new CMonster(iChoice);
		Hunting_Monster(_player);
	}
	else if (4 == iChoice)
	{
		return;
	}
	else
	{
		Hunting_Menu(_player);
		return;
	}
}

void CHuntingZone::Hunting_Monster(CPlayer * _player)
{
	int iChoice = 0;
	while (true)
	{
		system("cls");
		_player->Rander();
		m_monster->Rander();
		cout << "1. ���� 2. ����" << endl;
		cin >> iChoice;

		if (1 == iChoice)
		{
			if (Attack_Monster(_player))
			{
				break;
			}
			system("pause");
		}
		else if (2 == iChoice)
		{
			cout << "����..." << endl;
			delete m_monster;
			m_monster = nullptr;

			break;
		}
	}
}

bool CHuntingZone::Attack_Monster(CPlayer * _player)
{
	m_monster->Set_Lest_HP(m_monster->Get_Lest_HP() - _player->Get_Attack_Point());
	cout << "����!.." << endl;

	if (0 >= m_monster->Get_Lest_HP())
	{
		cout << "��ɼ���" << endl;
		delete m_monster;
		m_monster = nullptr;

		return true;
	}

	_player->Set_Lest_HP(_player->Get_Lest_HP() - m_monster->Get_Attack_Point());
	cout << "������ ����..." << endl;

	if (0 >= _player->Get_Lest_HP())
	{
		_player->Set_Lest_HP(_player->Get_Max_HP());
		cout << "�÷��̾� ���.." << endl;

		return true;
	}

	return false;
}