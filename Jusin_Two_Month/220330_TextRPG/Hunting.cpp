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

		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �ڷΰ���" << endl;
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
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
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

		cout << "1. ���� 2. ������ 3. ��������" << endl;
		cin >> iChoice;

		switch (iChoice)
		{
		case Combat_Attack:
			m_Monster->Set_Lest_HP(m_Monster->Get_Lest_HP() - m_Player->Get_Attack());

			cout << "����!!!" << endl;

			if (0 >= m_Monster->Get_Lest_HP())
			{
				cout << "�¸�" << endl;
				m_Player->Set_Money(m_Player->Get_Money() + m_Monster->Get_Money());
				static_cast<CPlayer*>(m_Player)->Level_Cheak(m_Monster->Get_Exp());
				Release();
				return;
			}

			m_Player->Set_Lest_HP(m_Player->Get_Lest_HP() - m_Monster->Get_Attack());

			if (0 >= m_Player->Get_Lest_HP())
			{
				cout << "���.." << endl;
				m_Player->Set_Lest_HP(m_Player->Get_Max_HP());
				Release();
				return;
			}

			break;

		case Combat_Item:
			break;


		case Combat_Run:
			cout << "����...." << endl;
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
