#pragma once

#include "Item.h"

class CEquipment final : public CItem
{
public:
	CEquipment();
	CEquipment(const char* _cName, const int& _Attack, const int& _HP, const int& _Price);
	~CEquipment();

	void Render();

	inline void Set_Wear() { m_bWear = !m_bWear; }
	inline const bool& Get_Wear() {	return m_bWear; }

private:
	bool m_bWear;
};