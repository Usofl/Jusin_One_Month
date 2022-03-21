#include "stdafx.h"
#include "Hunting.h"

void CHunting::Hunting_Menu(CPlayer * _player)
{
	int iChoice = 0;

	system("cls");

	_player->Print_Player_Info();

	cout << "1. �ʱ� 2. �߱� 3. ��� 4. �ڷΰ���" << endl;

	cin >> iChoice;

	if (1 <= iChoice && 3 >= iChoice)
	{
		m_monster.Init_Monster(iChoice);
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

void CHunting::Hunting_Monster(CPlayer * _player)
{
	int iChoice = 0;
	while (true)
	{
		system("cls");

		_player->Print_Player_Info();
		m_monster.Print_Monster_Info();

		cout << "1. ���� 2.������ 3.����" << endl;
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
			cout << "���� ��������" << endl;
		}
		else if (3 == iChoice)
		{
			cout << "����..." << endl;
			break;
		}
		else
		{
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
		}
	}
	system("pause");
}

bool CHunting::Attack_Monster(CPlayer * _player)
{
	m_monster.Set_Lest_HP(m_monster.Get_Lest_HP() - _player->Get_Attack_Point());

	cout << "����! ���Ϳ��� " << _player->Get_Attack_Point() << "��ŭ�� �������� ����.." << endl;

	if (m_monster.Get_Lest_HP() <= 0)
	{
		cout << "��� ����" << endl;

		return true;
	}

	_player->Set_Lest_HP(_player->Get_Lest_HP() - m_monster.Get_Attack_Point());

	cout << "�ƾ�! ���Ͱ� " << m_monster.Get_Attack_Point() << "��ŭ�� ����!" << endl;

	if (_player->Get_Lest_HP() <= 0)
	{
		cout << "�÷��̾� ���" << endl;

		_player->Set_Lest_HP(_player->Get_Max_HP());
		
		return true;
	}

	return false;
}
