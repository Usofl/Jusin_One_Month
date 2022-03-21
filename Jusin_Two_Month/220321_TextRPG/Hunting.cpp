#include "stdafx.h"
#include "Hunting.h"

void CHunting::Hunting_Menu(CPlayer * _player)
{
	int iChoice = 0;

	system("cls");

	_player->Print_Player_Info();

	cout << "1. 초급 2. 중급 3. 고급 4. 뒤로가기" << endl;

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

		cout << "1. 공격 2.아이템 3.도망" << endl;
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
			cout << "ㅈㅅ 아직없음" << endl;
		}
		else if (3 == iChoice)
		{
			cout << "도망..." << endl;
			break;
		}
		else
		{
			cout << "잘못입력하셨습니다." << endl;
		}
	}
	system("pause");
}

bool CHunting::Attack_Monster(CPlayer * _player)
{
	m_monster.Set_Lest_HP(m_monster.Get_Lest_HP() - _player->Get_Attack_Point());

	cout << "공격! 몬스터에게 " << _player->Get_Attack_Point() << "만큼의 데미지를 입힘.." << endl;

	if (m_monster.Get_Lest_HP() <= 0)
	{
		cout << "사냥 성공" << endl;

		return true;
	}

	_player->Set_Lest_HP(_player->Get_Lest_HP() - m_monster.Get_Attack_Point());

	cout << "아야! 몬스터가 " << m_monster.Get_Attack_Point() << "만큼의 공격!" << endl;

	if (_player->Get_Lest_HP() <= 0)
	{
		cout << "플레이어 사망" << endl;

		_player->Set_Lest_HP(_player->Get_Max_HP());
		
		return true;
	}

	return false;
}
