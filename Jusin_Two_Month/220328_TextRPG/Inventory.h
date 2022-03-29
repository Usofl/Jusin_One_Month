#pragma once
#include "Equipment.h"
#include "Consum.h"

class CConsum;

class CInventory
{
public:
	CInventory();
	~CInventory();

	void Add_Item(CConsum* _Consum, CEquipment* _Equip);
	CConsum * My_Inventory();
	void Render();

	void Wear_Equiq(int _iChoice);
	CEquipment* Get_Equiq();
	size_t Get_Equiq_size();
	CConsum* Use_Consum(int _iChoice);

private:
	CConsum m_Consum[5];
	size_t m_Consum_Size;

	CEquipment m_Equip[5];
	size_t m_Equip_Size;
};