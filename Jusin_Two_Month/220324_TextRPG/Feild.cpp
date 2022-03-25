#include "stdafx.h"
#include "Feild.h"

CFeild::CFeild(CPlayer* _Player)
	: m_Player(_Player)
{
}

CFeild::~CFeild()
{
	Release();
}

void CFeild::Initialize()
{
	system("cls");
	Release();

	m_Player->Get_Status()->Render();

	m_Monster = new CMonster;

	int iChoice = 0;

	cout << "1. �ʱ� 2. �߱� 3. ��� 4. �ڷΰ���" << endl;
	cout << "==============================" << endl;

	while (true)
	{
		cin >> iChoice;

		switch (iChoice)
		{
		case Junior:
			m_Monster->Get_Status()->Init_Stat("�ʱ�", 3, 30);
			break;

		case Sinior:
			m_Monster->Get_Status()->Init_Stat("�߱�", 30, 70);
			break;

		case Major:
			m_Monster->Get_Status()->Init_Stat("���", 50, 100);
			break;

		case Mon_Exit:
			Release();
			return;
			break;

		default:
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			break;
		}

		if (0 != m_Monster->Get_Status()->Get_Attack_Point())
		{
			return;
		}
	}
}

void CFeild::Update()
{
	if (nullptr == m_Monster)
	{
		return;
	}

	int iChoice = 0;

	while (true)
	{
		system("cls");

		m_Player->Get_Status()->Render();
		m_Monster->Get_Status()->Render();

		cout << "1. ���� 2. ����" << endl;
		cout << "==============================" << endl;

		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			m_Monster->Get_Status()->Damage_Process(m_Player->Get_Status()->Get_Attack_Point());

			if (0 >= m_Monster->Get_Status()->Get_Lest_HP())
			{
				cout << "�¸�" << endl;
				Release();

				system("pause");
				return;
			}

			m_Player->Get_Status()->Damage_Process(m_Monster->Get_Status()->Get_Attack_Point());

			if (0 >= m_Player->Get_Status()->Get_Lest_HP())
			{
				cout << "�÷��̾� ���" << endl;
				m_Player->Get_Status()->Set_Lest_HP(m_Player->Get_Status()->Get_Max_HP());
				Release();

				system("pause");
				return;
			}

			break;

		case 2:
			cout << "����" << endl;

			Release();
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
	if (m_Monster != nullptr)
	{
		delete m_Monster;
	}

	m_Monster = nullptr;
}
