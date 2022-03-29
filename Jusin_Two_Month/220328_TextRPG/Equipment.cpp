#include "stdafx.h"
#include "Equipment.h"

CEquipment::CEquipment()
	: CItem()
	, m_bWear(false)
{
}

CEquipment::~CEquipment()
{
}

void CEquipment::Set_Wear()
{
	m_bWear = !m_bWear;
}

const bool& CEquipment::Get_Wear()
{
	return m_bWear;
}

void CEquipment::Render_Equipment()
{
	cout << "=================================================" << endl;
	cout << "�̸� : [" << this->Get_Item_Name() << "]" << endl;
	cout << "ȿ��" << endl;
	cout << "----------------------" << endl;
	cout << "�����" << endl;
	if (this->Get_Plus_Attack())
	{
		cout << "���ݷ� " << this->Get_Plus_Attack() << " ����" << endl;
	}
	else if (this->Get_Plus_HP())
	{
		cout << "ü�� " << this->Get_Plus_HP() << " ����" << endl;
	}
	if (this->Get_Wear())
	{
		cout << "[������]" << endl;
	}
	cout << "=================================================" << endl;
}
