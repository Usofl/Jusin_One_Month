#pragma once

class CItem
{
public:
	CItem();
	~CItem();

	void Render();
	void Init_Item_Set(const char* _cName, int _Attack, int _HP, int _Price);

	const char* Get_Item_Name();
	const int& Get_Plus_Attack();
	const int& Get_Plus_HP();
	const int& Get_Price();

private:
	char m_cItem_Name[20];
	int m_iPlus_Attack;
	int m_iPlus_HP;
	int m_iPrice;
};