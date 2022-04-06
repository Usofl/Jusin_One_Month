#include "stdafx.h"
#include "Hunting.h"

CHunting::CHunting()
	: CFeild()
	, m_Monster(nullptr)
{

}

CHunting::~CHunting()
{
	Release();
}

void CHunting::Initialize()
{
	assert(nullptr != m_Player);
	Release();
	int iChoice = 0;

	while (true)
	{
		system("cls");
		m_Player->Render();
		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �ڷΰ���" << endl;
		cin >> iChoice;

		if (Monster_Start < iChoice && Monster_End > iChoice)
		{
			m_Monster = new CMonster;
			m_Monster->Init_Stat(iChoice);
			break;
		}
		else if (Monster_End == iChoice)
		{
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
	assert(nullptr != m_Player);
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
			if(Attack_Monster())
			{
				Release();
				return;
			}
			break;
		case Combat_Item:
			static_cast<CPlayer*>(m_Player)->Show_Inventory();
			break;
		case Combat_End:
			cout << "����..." << endl;
			Release();
			return;
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			break;
		}
		system("pause");
	}
}

void CHunting::Release()
{
	CDelete<CStatus*>()(m_Monster);
}


bool CHunting::Attack_Monster()
{
	cout << "����!!" << endl;

	m_Monster->Set_Lest_HP(m_Monster->Get_Lest_HP() - m_Player->Get_Attack());

	if (0 >= m_Monster->Get_Lest_HP())
	{
		cout << "�¸�!" << endl;
		static_cast<CPlayer*>(m_Player)->Level_Up_Cheak(m_Monster->Get_Exp());
		m_Player->Set_Money(m_Player->Get_Money() + m_Monster->Get_Money());

		return true;
	}

	m_Player->Set_Lest_HP(m_Player->Get_Lest_HP() - m_Monster->Get_Attack());

	if (0 >= m_Player->Get_Lest_HP())
	{
		cout << "�÷��̾� ���.." << endl;
		m_Player->Set_Lest_HP(m_Player->Get_Max_HP());

		return true;
	}

	return false;
}