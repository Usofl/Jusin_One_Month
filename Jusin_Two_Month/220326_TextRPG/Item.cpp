#include "stdafx.h"
#include "Item.h"

CItem::CItem()
	: m_cItem_Name()
	, m_bConsume(false)
	, m_bWear(false)
	, m_iCount(0)
	, m_iPlus_HP(0)
	, m_iPlus_Attack(0)
	, m_iPrice(0)
{
	
}

CItem::~CItem()
{
}

void CItem::Init_Info(const char* _cName, int _iPlus_HP, int _iPlus_Attack, bool _bConsume, int _iPrice)
{
	strcpy_s(m_cItem_Name, sizeof(m_cItem_Name), _cName);

	m_iPlus_HP = _iPlus_HP;
	m_iPlus_Attack = _iPlus_Attack;
	
	m_bConsume = _bConsume;

	m_iPrice = _iPrice;
}

void CItem::Render() const
{
	cout << "=================================" << endl;
	cout << "아이템 이름 : " << m_cItem_Name << endl;
	
	if (m_bConsume)
	{
		cout << "사용시 ";
	}
	else
	{
		cout << "착용시 ";
	}

	if (m_iPlus_Attack)
	{
		cout << "공격력 " << m_iPlus_Attack << "증가" << endl;
	}
	else
	{
		cout << "체력 " << m_iPlus_HP << "증가" << endl;
	}

	if (m_bWear)
	{
		cout << "[착용중]" << endl;
	}
	if (m_iCount)
	{
		cout << m_iCount << "개 소지중" << endl;
	}
	cout << "=================================" << endl;
}

void CItem::Set_Count(int _iCount)
{
	m_iCount = _iCount;
}

void CItem::Set_Wear(bool _bWear)
{
	m_bWear = _bWear;
}

const char* CItem::Get_Name() const
{
	return m_cItem_Name;
}

const int & CItem::Get_Count() const
{
	return m_iCount;
}

const int & CItem::Get_Price() const
{
	return m_iPrice;
}

const int & CItem::Get_Plus_HP() const
{
	return m_iPlus_HP;
}

const int & CItem::Get_Plus_Attack() const
{
	return m_iPlus_Attack;
}

const bool & CItem::Get_Consume() const
{
	return m_bConsume;
}

const bool & CItem::Get_Wear() const
{
	return m_bWear;
}
