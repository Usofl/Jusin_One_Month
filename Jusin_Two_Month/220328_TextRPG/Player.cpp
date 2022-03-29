#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
	: CStatus()
	, m_iLevel(1)
	, m_iMax_Exp(100)
	, m_iPlus_HP(0)
	, m_iPlus_Attack(0)
	, m_Inventory()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Render_Player()
{
	cout << "레벨 " << m_iLevel << " <" << this->Get_Exp() << " / " << m_iMax_Exp << "> " << endl;
	cout << "소지금 : " << this->Get_Money() << "원" << endl;
	cout << "=================================================" << endl;
	this->Render();
}

void CPlayer::Init_Player(int _iChoice)
{
	switch (_iChoice)
	{
	case 1:
		Init_Stat("전사", 10, 100, 0, 0);
		break;

	case 2:
		Init_Stat("마법사", 30, 70, 0, 0);
		break;

	case 3:
		Init_Stat("도적", 15, 80, 0, 0);
		break;

	default:
		break;
	}
}

void CPlayer::Level_Up_Cheak()
{
	if (m_iMax_Exp <= this->Get_Exp())
	{
		++m_iLevel;
		this->Init_Stat(this->Get_Name(), Get_Attack_Point() + 5, this->Get_Max_HP() + 10, this->Get_Exp() - m_iMax_Exp, Get_Money());

		m_iMax_Exp += 10;

		this->Set_Lest_HP(this->Get_Max_HP());

		cout << "레벨 업 !" << endl;
	}
}

CInventory * CPlayer::Get_Inventory()
{
	return &m_Inventory;
}

void CPlayer::Cheak_Wearing()
{
	CEquipment* pEquip = m_Inventory.Get_Equiq();
	size_t iEquiq_Size = m_Inventory.Get_Equiq_size();

	Set_Max_HP(Get_Max_HP() - m_iPlus_HP);
	Set_Attack_Point(Get_Attack_Point() - m_iPlus_Attack);

	for (unsigned int i = 0; i < iEquiq_Size; ++i)
	{
		if (pEquip[i].Get_Wear())
		{
			m_iPlus_Attack += pEquip[i].Get_Plus_Attack();
			m_iPlus_HP += pEquip[i].Get_Plus_HP();
		}
	}

	Set_Max_HP(Get_Max_HP() + m_iPlus_HP);
	Set_Attack_Point(Get_Attack_Point() + m_iPlus_Attack);
}

void CPlayer::Use_Consum(CConsum* _consum)
{
	Set_Attack_Point(Get_Attack_Point() + _consum->Get_Plus_Attack());

	if (Get_Max_HP() <= Get_Lest_HP() + _consum->Get_Plus_HP())
	{
		Set_Lest_HP(Get_Max_HP());
	}
	else
	{
		Set_Lest_HP(Get_Lest_HP() + _consum->Get_Plus_HP());
	}
}
