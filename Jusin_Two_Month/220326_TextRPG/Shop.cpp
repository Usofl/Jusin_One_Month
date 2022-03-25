#include "stdafx.h"
#include "Shop.h"

CShop::CShop()
	: m_Player(nullptr)
{

}

CShop::~CShop()
{

}

void CShop::Set_Player(CPlayer* _player)
{
	m_Player = _player;
}

void CShop::Show_Item()
{
	for (int i = 0; i < 10; ++i)
	{
		if (0 != m_Shop_Item[i].Get_Price())
		{
			cout << i + 1 << ". [" << m_Shop_Item[i].Get_Name() << "] 가격 : " << m_Shop_Item[i].Get_Price() << "원" << endl;
		}
		else
		{
			cout << i + 1 << ". " << "준비중" << endl;
		}
	}
	cout << "=================================" << endl;
}

void CShop::CloseUp_Item(const int& _iItem) const
{
	while (true)
	{
		system("cls");

		m_Player->Render();
		cout << "=================================" << endl;
		m_Shop_Item[_iItem].Render();

		cout << "1. 구매 2. 뒤로가기" << endl;
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			if (m_Player->Buy_Item(m_Shop_Item[_iItem]))
			{
				cout << "구매 완료" << endl;
			}
			else
			{
				cout << "잔액이 부족합니다." << endl;
			}
			system("pause");
			break;

		case 2:
			return;
			break;

		default:
			break;
		}
	}
}

void CShop::Initialize()
{
	m_Shop_Item[0].Init_Info("체력 포션", 20, 0, true, 10);
	m_Shop_Item[1].Init_Info("공격력 포션", 0, 10, true, 30);
	m_Shop_Item[2].Init_Info("장갑", 0, 10, false, 50);
	m_Shop_Item[3].Init_Info("신발", 10, 0, false, 50);
	m_Shop_Item[4].Init_Info("강철검", 0, 50, false, 150);
	m_Shop_Item[5].Init_Info("헬멧", 20, 0, false, 100);
	m_Shop_Item[6].Init_Info("갑옷", 30, 0, false, 150);
}

void CShop::Update()
{
	while (true)
	{
		system("cls");
		int iItem_Num = 0;

		m_Player->Render();
		cout << "=================================" << endl;
		Show_Item();

		cout << "0. 나가기" << endl;
		cin >> iItem_Num;

		if (iItem_Num == 0)
		{
			return;
		}
		--iItem_Num;
		CloseUp_Item(iItem_Num);
	}
}

void CShop::Release()
{
}
