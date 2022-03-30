#include "stdafx.h"
#include "Hunting.h"

CHunting::CHunting()
{

}

CHunting::~CHunting()
{

}

void CHunting::Initialize()
{
	assert(nullptr != m_Player);

	int iChoice = 0;
	while (true)
	{
		system("cls");
		m_Player->Render();

		cout << "1. 초급 2. 중급 3. 고급 4. 뒤로가기" << endl;
		cin >> iChoice;

		if (1 <= iChoice && 3 >= iChoice)
		{
			m_Monster = new CMonster;
			m_Monster->Init_Stat(iChoice);
			return;
		}
		else if (4 == iChoice)
		{
			return;
		}
		else
		{
			cout << "잘못 입력하셨습니다." << endl;
			continue;
		}
	}
}

void CHunting::Update()
{
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
		case 1:
			m_Monster->Set_Lest_HP(m_Monster->Get_Lest_HP() - m_Player->Get_Attack());

			cout << "공격!" << endl;

			if (0 >= m_Monster->Get_Lest_HP())
			{
				cout << "승리~" << endl;

				return;
			}

			m_Player->Set_Lest_HP(m_Player->Get_Lest_HP() - m_Monster->Get_Attack());

			if (0 >= m_Player->Get_Lest_HP())
			{
				cout << "패배 ㅠㅠ" << endl;

				m_Player->Set_Lest_HP(m_Player->Get_Max_HP());

				return;
			}

			break;

		case 2:
			break;

		case 3:
			Release();
			return;
			break;

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