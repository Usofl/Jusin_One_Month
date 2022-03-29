#pragma once
#include "Item.h"

class CConsum : public CItem
{
public:
	CConsum();
	~CConsum();
	
	void Set_Turn(const int& _Turn);
	void Set_Count(const int& _Conut);

	const int& Get_Turn();
	const int& Get_Count();

	void Render_Consum();

private:
	int m_iCount;
	int m_iTurn;
};