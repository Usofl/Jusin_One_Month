#include "stdafx.h"
#include "Feild.h"
#include "Player.h"
#include "Monster.h"

CFeild::CFeild()
	: m_Player(nullptr)
	, m_Monster(nullptr)
{

}

CFeild::~CFeild()
{
	Release();
}

void CFeild::Initialize()
{
	assert(m_Player != nullptr);
	assert(m_Monster == nullptr);

	while (true)
	{
		system("cls");

		m_Player->Render_Player();
		cout << "1. 초급 2. 중급 3. 고급 4. 뒤로가기" << endl;
		cin >> iChoice;

		if (1 <= iChoice && 3 >= iChoice)
		{
			m_Monster = new CMonster;

			m_Monster->Set_Monster(iChoice);

			return;
		}
		else if (4 == iChoice)
		{
			Release();
			return;
		}
		else
		{
			cout << "잘못 입력하셨습니다." << endl;
			system("pause");
			continue;
		}
	}
}

void CFeild::Update()
{
	if (m_Monster == nullptr)
	{
		return;
	}

	while (true)
	{
		system("cls");

		m_Player->Render_Player();
		m_Monster->Render();

		CConsum* p = nullptr;

		cout << "1. 공격 2. 아이템 3. 도망" << endl;
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			m_Monster->Damage(m_Player->Get_Attack_Point());

			if (0 >= m_Monster->Get_Lest_HP())
			{
				cout << "승리" << endl;
				m_Player->Plus_Exp(m_Monster->Get_Exp());
				m_Player->Set_Money(m_Player->Get_Money() + m_Monster->Get_Money());
				m_Player->Level_Up_Cheak();

				Release();

				return;
			}

			m_Player->Damage(m_Monster->Get_Attack_Point());

			if (0 >= m_Player->Get_Lest_HP())
			{
				cout << "플레이어 사망.." << endl;

				m_Player->Set_Lest_HP(m_Player->Get_Max_HP());

				Release();
				return;
			}

			break;
		case 2:
			p = m_Player->Get_Inventory()->My_Inventory();
			if (p != nullptr)
			{
				m_Player->Use_Consum(p);
			}
			m_Player->Cheak_Wearing();
			break;
		case 3:
			cout << "도망....." << endl;

			return;
			break;
		default:
			break;
		}
		system("pause");
	}
}

void CFeild::Release()
{
	SAFE_DELETE(m_Monster);
}

void CFeild::Set_Player(CPlayer* _player)
{
	assert(_player != nullptr);

	m_Player = _player;
}