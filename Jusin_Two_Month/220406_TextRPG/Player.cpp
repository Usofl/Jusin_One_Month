#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
	: CStatus()
	, m_iLevel(1)
	, m_iMax_Exp(100)
	, m_iPlus_HP(0)
	, m_iPlus_Attack(0)
	, m_vecEquipment()
	, m_vecConsum()
{
	m_vecConsum.reserve(5);
	m_vecEquipment.reserve(5);
}

CPlayer::~CPlayer()
{
}

void CPlayer::Render()
{
	cout << "레벨 " << m_iLevel << " <" << this->Get_Exp() << " / " << m_iMax_Exp << "> " << endl;
	cout << "소지금 : " << this->Get_Money() << "원" << endl;
	cout << "=================================================" << endl;
	cout << "직업 : " << Get_Name() << endl;
	cout << "공격력 : " << Get_Attack() << "(+" << m_iPlus_Attack << ")" << endl;
	cout << "체력 : <" << Get_Lest_HP() << " / " << Get_Max_HP() << ">";
	cout <<"(+" << m_iPlus_HP << ")" << endl;
	cout << "=================================================" << endl;
}

void CPlayer::Init_Stat(const int& _iChoice)
{
	switch (_iChoice)
	{
	case Job_Warrior:
		Set_Name("전사");
		Set_Attack(10);
		Set_Max_HP(100);
		break;

	case Job_Magician:
		Set_Name("마법사");
		Set_Attack(30);
		Set_Max_HP(70);
		break;

	case Job_Thief:
		Set_Name("도적");
		Set_Attack(15);
		Set_Max_HP(80);
		break;

	default:
		break;
	}

	Set_Lest_HP(Get_Max_HP());
	Set_Money(100);
}

void CPlayer::Level_Up_Cheak(const int& _Exp)
{
	Set_Exp(Get_Exp() + _Exp);

	if (m_iMax_Exp <= this->Get_Exp())
	{
		++m_iLevel;

		Set_Attack(Get_Attack() + 5);
		Set_Max_HP(Get_Max_HP() + 10);
		Set_Lest_HP(Get_Max_HP());
		Set_Exp(Get_Exp() - m_iMax_Exp);

		m_iMax_Exp += 10;

		cout << "레벨 업 !" << endl;
	}
}

void CPlayer::Show_Inventory()
{
	int iChoice = 0;

	while (true)
	{
		system("cls");

		Render();

		Inventory_Render();
		cin >> iChoice;

		if (1 <= iChoice && 5 >= iChoice)
		{
			Using_Consum(iChoice - 1);
		}
		else if (6 <= iChoice && 10 >= iChoice)
		{
			Set_Equipment(iChoice - 6);
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

void CPlayer::Inventory_Render()
{
	cout << "=================================================" << endl;
	for (int i = 0; i < m_vecConsum.size(); ++i)
	{
		cout << i + 1 << ". ";
		if (strcmp(m_vecConsum[i].Get_Item_Name(), ""))
		{
			cout << "[" << m_vecConsum[i].Get_Item_Name() << "] " << m_vecConsum[i].Get_Count() << "개" << endl;
		}
		else
		{
			cout << " [---]" << endl;
		}
	}
	cout << "=================================================" << endl;
	for (int i = 0; i < m_vecEquipment.size(); ++i)
	{
		cout << i + 6 << ". ";
		if (strcmp(m_vecEquipment[i].Get_Item_Name(), ""))
		{
			cout << "[" << m_vecEquipment[i].Get_Item_Name() << "] ";
			if (m_vecEquipment[i].Get_Wear())
			{
				cout << "[착용중]";
			}
			cout << endl;
		}
		else
		{
			cout << " [---]" << endl;
		}
	}
	cout << "=================================================" << endl;
	cout << "0. 나가기" << endl;
}

void CPlayer::Set_Equipment(const int & _index)
{
	int iChoice = 0;

	while (true)
	{
		system("cls");
		Render();

		m_vecEquipment[_index].Render();

		if (m_vecEquipment[_index].Get_Wear())
		{
			cout << "1. 헤제 ";
		}
		else
		{
			cout << "1. 착용 ";
		}
		cout << "2. 뒤로가기" << endl;
		cin >> iChoice;

		if (1 == iChoice)
		{
			m_vecEquipment[_index].Set_Wear();
			if (m_vecEquipment[_index].Get_Wear())
			{
				Set_Plus_Attack(Get_Plus_Attack() + m_vecEquipment[_index].Get_Plus_Attack());
				Set_Plus_HP(Get_Plus_HP() + m_vecEquipment[_index].Get_Plus_HP());

				Set_Max_HP(Get_Max_HP() + m_vecEquipment[_index].Get_Plus_HP());
				Set_Attack(Get_Attack() + m_vecEquipment[_index].Get_Plus_Attack());
			}
			else
			{
				Set_Plus_Attack	(Get_Plus_Attack() - m_vecEquipment[_index].Get_Plus_Attack());
				Set_Plus_HP		(Get_Plus_HP() - m_vecEquipment[_index].Get_Plus_HP());

				Set_Max_HP(Get_Max_HP() - m_vecEquipment[_index].Get_Plus_HP());
				Set_Attack(Get_Attack() - m_vecEquipment[_index].Get_Plus_Attack());
			}

			return;
		}
		else if (2 == iChoice)
		{
			return;
		}
		else
		{
			cout << "잘못 입력하셨습니다." << endl;
			system("pause");
		}
	}
}

void CPlayer::Using_Consum(const int & _index)
{
	int iChoice = 0;

	while (true)
	{
		system("cls");
		Render();

		m_vecConsum[_index].Render();

		if (m_vecConsum[_index].Get_Count())
		{
			cout << "1. 사용 ";
		}
		cout << "2. 뒤로가기" << endl;
		cin >> iChoice;

		if (1 == iChoice && m_vecConsum[_index].Get_Count())
		{
			Set_Plus_Attack(Get_Plus_Attack() + m_vecConsum[_index].Get_Plus_Attack());

			if (Get_Max_HP() <= Get_Lest_HP() + m_vecConsum[_index].Get_Plus_HP())
			{
				Set_Lest_HP(Get_Max_HP());
			}
			else
			{
				Set_Lest_HP(Get_Lest_HP() + m_vecConsum[_index].Get_Plus_HP());
			}
			m_vecConsum[_index].Set_Count(m_vecConsum[_index].Get_Count() - 1);

			return;
		}
		else if (2 == iChoice)
		{
			return;
		}
		else
		{
			cout << "잘못 입력하셨습니다." << endl;
			system("pause");
		}
	}
}

void CPlayer::Add_Item(const CConsum * _Consum, const CEquipment * _Equipment)
{
	bool find = false;
	if (_Consum != nullptr)
	{
		for (vector<CConsum>::iterator iter = m_vecConsum.begin(); iter != m_vecConsum.end(); ++iter)
		{
			if (*iter == *_Consum)
			{
				iter->Set_Count(iter->Get_Count() + 1);
				find = true;
			}
		}

		if (!find)
		{
			m_vecConsum.push_back(*_Consum);
		}
	}

	if (_Equipment != nullptr)
	{
		for (vector<CEquipment>::iterator iter = m_vecEquipment.begin(); iter != m_vecEquipment.end(); ++iter)
		{
			if (*iter == *_Equipment)
			{
				find = true;
			}
		}

		if (!find)
		{
			m_vecEquipment.push_back(*_Equipment);
		}
	}
}