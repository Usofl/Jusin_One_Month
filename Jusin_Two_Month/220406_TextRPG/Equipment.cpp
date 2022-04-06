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
	cout << "이름 : [" << this->Get_Item_Name() << "]" << endl;
	cout << "효과" << endl;
	cout << "----------------------" << endl;
	cout << "착용시" << endl;
	if (this->Get_Plus_Attack())
	{
		cout << "공격력 " << this->Get_Plus_Attack() << " 증가" << endl;
	}
	else if (this->Get_Plus_HP())
	{
		cout << "체력 " << this->Get_Plus_HP() << " 증가" << endl;
	}
	if (this->Get_Wear())
	{
		cout << "[착용중]" << endl;
	}
	cout << "=================================================" << endl;
}
