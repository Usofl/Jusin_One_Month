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
		cout << "1. 초급 2. 중급 3. 고급 4. 뒤로가기" << endl;
		cout << "=================================" << endl;
		cin >> iChoice;

		if (m_Monster == nullptr)
		{
			m_Monster = new CMonster;
		}

		switch (iChoice)
		{
		case 1:
			m_Monster->Get_pStatus()->Init_Stat("초급", 3, 30);
			break;

		case 2:
			m_Monster->Get_pStatus()->Init_Stat("중급", 15, 50);
			break;

		case 3:
			m_Monster->Get_pStatus()->Init_Stat("고급", 30, 80);
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

		cout << "1. 공격 2. 아이템 3. 도망" << endl;
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
			cout << "도망.." << endl;
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
	
	cout << "공격!.." << endl;

	m_Monster->Get_pStatus()->Set_Lest_HP(m_Monster->Get_pStatus()->Get_Lest_HP() - iPlayer_Attack);

	if (0 >= m_Monster->Get_pStatus()->Get_Lest_HP())
	{
		int iMoney = RandomNum(iMonster_Attack, iMonster_Attack * 5);

		cout << "승리" << endl;
		cout << iMoney << "원 획득!" << endl;

		m_Player->Set_Money(m_Player->Get_Money() + iMoney);

		return true;
	}

	cout << "아야!.." << endl;

	m_Player->Get_pStatus()->Set_Lest_HP(m_Player->Get_pStatus()->Get_Lest_HP() - iMonster_Attack);

	if (0 >= m_Player->Get_pStatus()->Get_Lest_HP())
	{
		cout << "플레이어 사망.." << endl;

		m_Player->Get_pStatus()->Set_Lest_HP(m_Player->Get_pStatus()->Get_Max_HP());

		return true;
	}

	return false;
}
