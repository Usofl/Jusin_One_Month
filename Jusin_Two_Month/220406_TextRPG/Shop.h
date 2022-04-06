#pragma once

#include "Feild.h"

#include "Equipment.h"
#include "Consum.h"

class CShop final : public CFeild
{
public:
	CShop();
	~CShop();

	void Initialize();
	void Update();
	void Release();

	void Shop_Render();
	void Buy_Item(int & _iChoice);

private:
	vector<CEquipment> m_vecEquipment;
	vector<CConsum> m_vecConsum;
};