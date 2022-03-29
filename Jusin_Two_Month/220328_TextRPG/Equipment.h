#pragma once
#include "Item.h"

class CEquipment : public CItem
{
public:
	CEquipment();
	~CEquipment();

	void Set_Wear();
	const bool& Get_Wear();

	void Render_Equipment();

private:
	bool m_bWear;
};