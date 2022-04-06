#include "stdafx.h"
#include "Equipment.h"

CEquipment::CEquipment()
	: CItem()
	, m_bWear(false)
{
}

CEquipment::CEquipment(const char* _cName, const int& _Attack, const int& _HP, const int& _Price)
	: CItem(_cName, _Attack, _HP, _Price)
	, m_bWear(false)
{
}

CEquipment::~CEquipment()
{
}

void CEquipment::Render()
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
