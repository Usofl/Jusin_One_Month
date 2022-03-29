#include "stdafx.h"
#include "Inventory.h"

CInventory::CInventory()
	: m_Consum()
	, m_Equip()
	, m_Consum_Size(0)
	, m_Equip_Size(0)
{
}

CInventory::~CInventory()
{
}

void CInventory::Add_Item(CConsum* _Consum, CEquipment* _Equip)
{
	if (nullptr != _Consum)
	{
		for (unsigned int i = 0; i <= m_Consum_Size; ++i)
		{
			if (!strcmp(_Consum->Get_Item_Name(), m_Consum[i].Get_Item_Name()))
			{
				m_Consum[i].Set_Count(m_Consum[i].Get_Count() + 1);
				return;
			}
		}
		m_Consum[m_Consum_Size] = *_Consum;
		m_Consum[m_Consum_Size].Set_Count(m_Consum[m_Consum_Size].Get_Count() + 1);
		m_Consum_Size++;
		return;
	}

	if (nullptr != _Equip)
	{
		for (unsigned int i = 0; i <= m_Equip_Size; ++i)
		{
			if (!strcmp(_Equip->Get_Item_Name(), m_Equip[i].Get_Item_Name()))
			{
				return;
			}
		}
		m_Equip[m_Equip_Size] = *_Equip;
		++m_Equip_Size;
		return;
	}
}

CConsum * CInventory::My_Inventory()
{
	while (true)
	{
		system("cls");
		Render();

		cin >> iChoice;

		if (1 <= iChoice && 5 >= iChoice)
		{
			--iChoice;
			CConsum* p = Use_Consum(iChoice);
			if (nullptr != p)
			{
				return p;
			}

		}
		else if (6 <= iChoice && 10 >= iChoice)
		{
			iChoice -= 6;
			Wear_Equiq(iChoice);
		}
		else if (0 == iChoice)
		{
			return nullptr;
		}
		else
		{
			cout << "잘못입력하셨습니다." << endl;
			return nullptr;
		}
	}
}

void CInventory::Render()
{
	cout << "=================================================" << endl;
	for (unsigned int i = 0; i < m_Consum_Size; ++i)
	{
		cout << i + 1 << ". ";
		if (strcmp(m_Consum[i].Get_Item_Name(), ""))
		{
			cout << m_Consum[i].Get_Item_Name() << " : " << m_Consum[i].Get_Count() << "개 보유중" << endl;
		}
	}
	cout << "=================================================" << endl;
	for (unsigned int i = 0; i < m_Equip_Size; ++i)
	{
		cout << i + 6 << ". ";
		if (strcmp(m_Equip[i].Get_Item_Name(), ""))
		{
			cout << m_Equip[i].Get_Item_Name();
			if (m_Equip[i].Get_Wear())
			{
				cout << " : [착용중]";
			}
			cout << endl;
		}
	}
	cout << "=================================================" << endl;
	cout << "0. 나가기" << endl;
}

void CInventory::Wear_Equiq(int _iChoice)
{
	system("cls");
	m_Equip[_iChoice].Render_Equipment();
	if (m_Equip[_iChoice].Get_Wear())
	{
		cout << "1 .해제 ";
	}
	else
	{
		cout << "1. 장착 ";
	}
	cout << "2. 뒤로가기" << endl;
	cin >> iChoice;

	if (1 == iChoice)
	{
		m_Equip[_iChoice].Set_Wear();
	}
	else
	{
		return;
	}
}

CEquipment * CInventory::Get_Equiq()
{
	return m_Equip;
}

size_t CInventory::Get_Equiq_size()
{
	return m_Equip_Size;
}

CConsum * CInventory::Use_Consum(int _iChoice)
{
	system("cls");
	m_Consum[_iChoice].Render_Consum();
	if (m_Consum[_iChoice].Get_Count())
	{
		cout << "1. 사용 ";
	}
	cout << "2. 뒤로가기" << endl;
	cin >> iChoice;

	if (1 == iChoice)
	{
		if (m_Consum[_iChoice].Get_Count())
		{
			m_Consum[_iChoice].Set_Count(m_Consum[_iChoice].Get_Count() - 1);
			return &m_Consum[_iChoice];
		}
	}
	else
	{
		return nullptr;
	}
}
