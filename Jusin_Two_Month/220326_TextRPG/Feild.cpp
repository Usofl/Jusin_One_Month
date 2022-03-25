#include "stdafx.h"
#include "Feild.h"

CFeild::CFeild()
	: m_Player(nullptr)
	, m_Monster(nullptr)
{

}

CFeild::~CFeild()
{
	Release();
}

void CFeild::Set_Player(CPlayer* _player)
{
	m_Player = _player;
}

void CFeild::Initialize()
{
	assert(m_Player != nullptr);

	while (true)
	{
		system("cls");
		m_Player->Render();
		cout << "=================================" << endl;
		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �ڷΰ���" << endl;
		cout << "=================================" << endl;
		cin >> iChoice;

		if (m_Monster == nullptr)
		{
			m_Monster = new CMonster;
		}

		switch (iChoice)
		{
		case 1:
			m_Monster->Get_pStatus()->Init_Stat("�ʱ�", 3, 30);
			break;

		case 2:
			m_Monster->Get_pStatus()->Init_Stat("�߱�", 15, 50);
			break;

		case 3:
			m_Monster->Get_pStatus()->Init_Stat("���", 30, 80);
			break;

		case 4:
			Release();
			return;
			break;

		default:
			continue;
			break;
		}
		return;
	}


}

void CFeild::Update()
{
	if (m_Monster == nullptr)
	{
		return;
	}

	while(true)
	{
		system("cls");
		m_Player->Render();
		m_Monster->Get_pStatus()->Render();
		cout << "=================================" << endl;

		cout << "1. ���� 2. ������ 3. ����" << endl;
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:

			if (Attack())
			{
				return;
			}

			break;

		case 2:
			m_Player->My_Inventory();
			continue;
			break;

		case 3:
			cout << "����.." << endl;
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

bool CFeild::Attack()
{
	int iPlayer_Attack = m_Player->Get_Attack_Point();
	int iMonster_Attack = m_Monster->Get_pStatus()->Get_Attack_Point();
	
	cout << "����!.." << endl;

	m_Monster->Get_pStatus()->Set_Lest_HP(m_Monster->Get_pStatus()->Get_Lest_HP() - iPlayer_Attack);

	if (0 >= m_Monster->Get_pStatus()->Get_Lest_HP())
	{
		int iMoney = RandomNum(iMonster_Attack, iMonster_Attack * 5);

		cout << "�¸�" << endl;
		cout << iMoney << "�� ȹ��!" << endl;

		m_Player->Set_Money(m_Player->Get_Money() + iMoney);

		return true;
	}

	cout << "�ƾ�!.." << endl;

	m_Player->Get_pStatus()->Set_Lest_HP(m_Player->Get_pStatus()->Get_Lest_HP() - iMonster_Attack);

	if (0 >= m_Player->Get_pStatus()->Get_Lest_HP())
	{
		cout << "�÷��̾� ���.." << endl;

		m_Player->Get_pStatus()->Set_Lest_HP(m_Player->Get_pStatus()->Get_Max_HP());

		return true;
	}

	return false;
}
