#include "stdafx.h"
#include "Shop.h"
#include "Player.h"
#include "Inventory.h"

CShop::CShop()
	: m_Consum(nullptr)
	, m_Equip(nullptr)
{

}

CShop::~CShop()
{
	Release();
}

void CShop::Initialize()
{
	if (nullptr == m_Equip)
	{
		m_Equip = new CEquipment[5];
	}
	
	if (nullptr == m_Consum)
	{
		m_Consum = new CConsum[5];
	}

	m_Equip[0].Init_Item_Set("강철검", 30, 0, 100);
	m_Equip[1].Init_Item_Set("강철 아머", 0, 50, 100);
	m_Equip[2].Init_Item_Set("장갑", 10, 0, 50);
	m_Equip[3].Init_Item_Set("신발", 0, 20, 50);
	m_Equip[4].Init_Item_Set("어깨보호대", 5, 10, 50);

	m_Consum[0].Init_Item_Set("체력 포션", 0, 20, 20);
	m_Consum[1].Init_Item_Set("공격력 포션", 20, 0, 20);
	m_Consum[1].Set_Turn(3);
}

void CShop::Update()
{
	while (true)
	{
		system("cls");

		m_Player->Render_Player();

		Shop_Render();
		cin >> iChoice;

		if (1 <= iChoice && 10 >= iChoice)
		{
			Buy_Item(iChoice);
		}
		else if (0 == iChoice)
		{ 
			return;
		}
		else
		{
			cout << "잘못입력하셨습니다." << endl;
		}
		system("pause");
	}
}

void CShop::Release()
{
	SAFE_DELETE_ARRAY(m_Consum);
	SAFE_DELETE_ARRAY(m_Equip);
}

void CShop::Set_Player(CPlayer* _player)
{
	assert(_player != nullptr);

	m_Player = _player;
}

void CShop::Shop_Render()
{
	cout << "=================================================" << endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << i + 1 << ". ";
		if (strcmp(m_Consum[i].Get_Item_Name(), ""))
		{
			m_Consum[i].Render();
		}
		else
		{
			cout << " [준비중]" << endl;
		}
	}
	cout << "=================================================" << endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << i + 6 << ". ";
		if (strcmp(m_Equip[i].Get_Item_Name(), ""))
		{
			m_Equip[i].Render();
		}
		else
		{
			cout << " [준비중]" << endl;
		}
	}
	cout << "=================================================" << endl;
	cout << "0. 나가기" << endl;
}

void CShop::Buy_Item(int & _iChoice)
{
	system("cls");

	m_Player->Render_Player();

	if (1 <= _iChoice && 5 >= _iChoice)
	{
		int i = _iChoice - 1;
		m_Consum[i].Render_Consum();

		cout << "1. 구매 2. 뒤로가기" << endl;
		cin >> iChoice;

		if (1 == iChoice)
		{
			if (m_Consum[i].Get_Price() <= m_Player->Get_Money())
			{
				cout << "구매 완료" << endl;
				m_Player->Set_Money(m_Player->Get_Money() - m_Consum[i].Get_Price());
				m_Player->Get_Inventory()->Add_Item(&m_Consum[i], nullptr);
			}
			else
			{
				cout << "돈이 부족합니다." << endl;
			}
		}
		else
		{
			return;
		}
	}
	else if (6 <= _iChoice && 10 >= _iChoice)
	{
		int i = _iChoice - 6;
		m_Equip[i].Render_Equipment();
		cout << "1. 구매 2. 뒤로가기" << endl;
		cin >> iChoice;

		if (1 == iChoice)
		{
			if (m_Equip[i].Get_Price() <= m_Player->Get_Money())
			{
				cout << "구매 완료" << endl;
				m_Player->Set_Money(m_Player->Get_Money() - m_Equip[i].Get_Price());
				m_Player->Get_Inventory()->Add_Item(nullptr, &m_Equip[i]);
			}
			else
			{
				cout << "돈이 부족합니다." << endl;
			}
		}
		else
		{
			return;
		}
	}
}
