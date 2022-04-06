#include "stdafx.h"
#include "Shop.h"

CShop::CShop()
	: CFeild()
	, m_vecEquipment(5)
	, m_vecConsum(5)
{
	m_vecEquipment[0] = CEquipment("��ö��", 30, 0, 100);
	m_vecEquipment[1] = CEquipment("��ö �Ƹ�", 0, 50, 100);
	m_vecEquipment[2] = CEquipment("�尩", 10, 0, 50);
	m_vecEquipment[3] = CEquipment("�Ź�", 0, 20, 50);
	m_vecEquipment[4] = CEquipment("�����ȣ��", 5, 10, 50);

	m_vecConsum[0] = CConsum("ü�� ����", 0, 20, 20);
	m_vecConsum[1] = CConsum("���ݷ� ����", 20, 0, 20, 3);
}

CShop::~CShop()
{
}

void CShop::Initialize()
{
}

void CShop::Update()
{
	int iChoice = 0;

	while (true)
	{
		system("cls");

		m_Player->Render();

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
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
		}
		system("pause");
	}
}

void CShop::Shop_Render()
{
	cout << "=================================================" << endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << i + 1 << ". ";
		if (strcmp(m_vecConsum[i].Get_Item_Name(), ""))
		{
			cout << "[" << m_vecConsum[i].Get_Item_Name() << "] " << m_vecConsum[i].Get_Price() << "��"<< endl;
		}
		else
		{
			cout << " [�غ���]" << endl;
		}
	}
	cout << "=================================================" << endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << i + 6 << ". ";
		if (strcmp(m_vecEquipment[i].Get_Item_Name(), ""))
		{
			cout << "[" << m_vecEquipment[i].Get_Item_Name() << "] " << m_vecEquipment[i].Get_Price() << "��" << endl;
		}
		else
		{
			cout << " [�غ���]" << endl;
		}
	}
	cout << "=================================================" << endl;
	cout << "0. ������" << endl;
}

void CShop::Release()
{

}

void CShop::Buy_Item(int & _iChoice)
{
	system("cls");
	int iChoice = 0;

	m_Player->Render();

	if (1 <= _iChoice && 5 >= _iChoice)
	{
		int i = _iChoice - 1;
		m_vecConsum[i].Render();

		cout << "1. ���� 2. �ڷΰ���" << endl;
		cin >> iChoice;

		if (1 == iChoice)
		{
			if (m_vecConsum[i].Get_Price() <= m_Player->Get_Money())
			{
				cout << "���� �Ϸ�" << endl;
				m_Player->Set_Money(m_Player->Get_Money() - m_vecConsum[i].Get_Price());
				static_cast<CPlayer*>(m_Player)->Add_Item(&m_vecConsum[i], nullptr);
			}
			else
			{
				cout << "���� �����մϴ�." << endl;
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
		m_vecEquipment[i].Render();
		cout << "1. ���� 2. �ڷΰ���" << endl;
		cin >> iChoice;

		if (1 == iChoice)
		{
			if (m_vecEquipment[i].Get_Price() <= m_Player->Get_Money())
			{
				cout << "���� �Ϸ�" << endl;
				m_Player->Set_Money(m_Player->Get_Money() - m_vecEquipment[i].Get_Price());
				static_cast<CPlayer*>(m_Player)->Add_Item(nullptr, &m_vecEquipment[i]);
			}
			else
			{
				cout << "���� �����մϴ�." << endl;
			}
		}
		else
		{
			return;
		}
	}
}
