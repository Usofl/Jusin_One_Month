#include "stdafx.h"
#include "Item.h"

CItem::CItem()
	: m_cItem_Name("")
	, m_iPlus_Attack(0)
	, m_iPlus_HP(0)
	, m_iPrice(0)
{

}

CItem::~CItem()
{

}

void CItem::Render()
{
	cout << " [" << m_cItem_Name << "] " << ": " << m_iPrice << "¿ø" << endl; ;
}

void CItem::Init_Item_Set(const char* _cName, int _Attack, int _HP, int _Price)
{
	strcpy_s(m_cItem_Name, sizeof(m_cItem_Name), _cName);
	m_iPlus_Attack = _Attack;
	m_iPlus_HP = _HP;
	m_iPrice = _Price;
}

const char * CItem::Get_Item_Name()
{
	return m_cItem_Name;
}

const int & CItem::Get_Plus_Attack()
{
	return m_iPlus_Attack;
}

const int & CItem::Get_Plus_HP()
{
	return m_iPlus_HP;
}

const int & CItem::Get_Price()
{
	return m_iPrice;
}
