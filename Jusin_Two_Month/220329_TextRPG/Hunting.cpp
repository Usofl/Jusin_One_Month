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

		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �ڷΰ���" << endl;
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
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
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

		cout << "1. ���� 2. ������ 3. ��������" << endl;
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			m_Monster->Set_Lest_HP(m_Monster->Get_Lest_HP() - m_Player->Get_Attack());

			cout << "����!" << endl;

			if (0 >= m_Monster->Get_Lest_HP())
			{
				cout << "�¸�~" << endl;

				return;
			}

			m_Player->Set_Lest_HP(m_Player->Get_Lest_HP() - m_Monster->Get_Attack());

			if (0 >= m_Player->Get_Lest_HP())
			{
				cout << "�й� �Ф�" << endl;

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