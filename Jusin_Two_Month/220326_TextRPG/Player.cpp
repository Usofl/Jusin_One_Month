#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
	: m_iMoney(0)
	, m_Item_Count(0)
{

}

CPlayer::~CPlayer()
{

}

void CPlayer::Render() const
{
	m_Status.Render();
	cout << "소지금 : " << m_iMoney << "원" << endl;
}

void CPlayer::Set_Money(int _iMoney)
{
	m_iMoney = _iMoney;
}

bool CPlayer::Buy_Item(CItem _Item)
{
	if (m_iMoney >= _Item.Get_Price())
	{
		if (m_Item_Count == 0)
		{
			m_MyItem[m_Item_Count] = _Item;
			m_MyItem[m_Item_Count].Set_Count(m_MyItem[m_Item_Count].Get_Count() + 1);
			++m_Item_Count;
		}
		else 
		{
			for (int i = 0; i <= m_Item_Count; ++i)
			{
				if (!(strcmp(m_MyItem[i].Get_Name(), _Item.Get_Name())))
				{
					m_MyItem[i].Set_Count(m_MyItem[i].Get_Count() + 1);
					break;
				}
				else if (i == m_Item_Count)
				{
					m_MyItem[i] = _Item;
					m_MyItem[i].Set_Count(m_MyItem[i].Get_Count() + 1);

					m_Item_Count++;
					break;
				}
			}
		}
		
		m_iMoney -= _Item.Get_Price();

		return true;
	}
	return false;
}

void CPlayer::My_Inventory()
{
	while (true)
	{
		system("cls");
		int iNum = 0;
		Render();
		cout << "=================================" << endl;
		for (int i = 0; i < m_Item_Count; ++i)
		{
			cout << i + 1 << ". [" << m_MyItem[i].Get_Name() << "] : " << m_MyItem[i].Get_Count() << "개" << endl;
		}
		cout << "=================================" << endl;

		cout << "0. 나가기" << endl;
		cin >> iNum;

		if (iNum == 0)
		{
			return;
		}
		else if (1 <= iNum && m_Item_Count >= iNum)
		{
			--iNum;
			Use_Item(iNum);
		}
	}
}

void CPlayer::Use_Item(int _Item)
{
	while (true)
	{
		system("cls");
		int iNum = 0;
		Render();
		cout << "=================================" << endl;
		m_MyItem[_Item].Render();

		if (m_MyItem[_Item].Get_Consume())
		{
			if (m_MyItem[_Item].Get_Count())
			{
				cout << "1. 사용 ";
			}
			cout << "2. 뒤로가기" << endl;

			cin >> iNum;

			if (iNum == 1)
			{
				Consume_Item(_Item);
			}
			else if (iNum == 2)
			{
				return;
			}
		}
		else
		{
			if (m_MyItem[_Item].Get_Wear())
			{
				cout << "1. 헤제 2. 뒤로가기" << endl;
			}
			else
			{
				cout << "1. 사용 2. 뒤로가기" << endl;
			}
			cin >> iNum;

			if (iNum == 1)
			{
				Wear_Item(_Item);
			}
			else if (iNum == 2)
			{
				return;
			}
		}
		

	}
}

void CPlayer::Wear_Item(int _Item)
{
	if (m_MyItem[_Item].Get_Wear())
	{
		m_Status.Set_Max_HP(m_Status.Get_Max_HP() - m_MyItem[_Item].Get_Plus_HP());
		m_Status.Set_Lest_HP(m_Status.Get_Lest_HP() - m_MyItem[_Item].Get_Plus_HP());
		m_Status.Set_Attack_Point(m_Status.Get_Attack_Point() - m_MyItem[_Item].Get_Plus_Attack());
	}
	else
	{
		m_Status.Set_Max_HP(m_Status.Get_Max_HP() + m_MyItem[_Item].Get_Plus_HP());
		m_Status.Set_Lest_HP(m_Status.Get_Lest_HP() + m_MyItem[_Item].Get_Plus_HP());
		m_Status.Set_Attack_Point(m_Status.Get_Attack_Point() + m_MyItem[_Item].Get_Plus_Attack());
	}

	m_MyItem[_Item].Set_Wear(!m_MyItem[_Item].Get_Wear());
}

void CPlayer::Consume_Item(int _Item)
{
	if (0 != m_MyItem[_Item].Get_Count())
	{
		if ((m_Status.Get_Lest_HP() + m_MyItem[_Item].Get_Plus_HP()) >= m_Status.Get_Max_HP())
		{
			m_Status.Set_Lest_HP(m_Status.Get_Max_HP());
		}
		else
		{
			m_Status.Set_Lest_HP(m_Status.Get_Lest_HP() + m_MyItem[_Item].Get_Plus_HP());
		}
		
		m_Status.Set_Attack_Point(m_Status.Get_Attack_Point() + m_MyItem[_Item].Get_Plus_Attack());

		m_MyItem[_Item].Set_Count(m_MyItem[_Item].Get_Count() - 1);
	}
}

const int& CPlayer::Get_Money() const
{
	return m_iMoney;
}

CStatus* CPlayer::Get_pStatus()
{
	return &m_Status;
}

const int CPlayer::Get_Attack_Point() const
{
	int iAttack = m_Status.Get_Attack_Point();

	return iAttack;
}
