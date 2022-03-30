#include "stdafx.h"
#include "Hunting.h"

CHunting::CHunting()
{
}

CHunting::~CHunting()
{
	Release();
}

void CHunting::Initialize()
{
	assert(m_Player != nullptr);
	assert(m_Monster == nullptr);
	int iChoice = 0;

	while (true)
	{
		system("cls");
		m_Player->Render();

		m_Monster = new CMonster;

		cout << "1. 초급 2. 중급 3. 고급 4. 뒤로가기" << endl;
		cin >> iChoice;

		if (Monster_Start < iChoice && Monster_Exit > iChoice)
		{
			m_Monster->Initialize(iChoice);
			return;
		}
		else if (4 == Job_Exit)
		{
			Release();
			return;
		}
		else
		{
			cout << "잘못 입력하셨습니다." << endl;
			system("pause");
		}
	}
}

void CHunting::Update()
{
	assert(m_Player != nullptr);

	if (m_Monster == nullptr)
	{
		return;
	}

	int iChoice = 0;

	while (true)
	{
		system("cls");
		m_Player->Render();
		m_Monster->Render();

		cout << "1. 공격 2. 아이템 3. 도망가기" << endl;
		cin >> iChoice;

		switch (iChoice)
		{
		case Combat_Attack:
			m_Monster->Set_Lest_HP(m_Monster->Get_Lest_HP() - m_Player->Get_Attack());

			cout << "공격!!!" << endl;

			if (0 >= m_Monster->Get_Lest_HP())
			{
				cout << "승리" << endl;
				m_Player->Set_Money(m_Player->Get_Money() + m_Monster->Get_Money());
				static_cast<CPlayer*>(m_Player)->Level_Cheak(m_Monster->Get_Exp());
				Release();
				return;
			}

			m_Player->Set_Lest_HP(m_Player->Get_Lest_HP() - m_Monster->Get_Attack());

			if (0 >= m_Player->Get_Lest_HP())
			{
				cout << "사망.." << endl;
				m_Player->Set_Lest_HP(m_Player->Get_Max_HP());
				Release();
				return;
			}

			break;

		case Combat_Item:
			break;


		case Combat_Run:
			cout << "도망...." << endl;
			Release();
			return;

		default:
			break;
		}
		system("pause");
	}
}

void CHunting::Release()
{
	SAFE_DELETE(m_Monster);
}
