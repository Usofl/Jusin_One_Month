#pragma once
#include "Status.h"
#include "Item.h"

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

	void Render() const;
	void Set_Money(int _iMoney);

	bool Buy_Item(CItem _Item);
	void My_Inventory();
	void Use_Item(int _Item);
	void Wear_Item(int _Item);
	void Consume_Item(int _Item);

	const int& Get_Money() const;
	CStatus* Get_pStatus();
	const int Get_Attack_Point() const;

private:
	CStatus m_Status;
	int m_iMoney;

	CItem m_MyItem[10];
	int m_Item_Count;
};