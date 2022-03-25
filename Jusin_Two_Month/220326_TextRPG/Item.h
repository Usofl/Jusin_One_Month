#pragma once
#include "define.h"

class CItem
{
public:
	CItem();
	~CItem();

	void Init_Info(const char* _cName, int _iPlus_HP, int _iPlus_Attack, bool _bConsume, int _iPrice);

	void Render() const;

	void Set_Count(int _iCount);
	void Set_Wear(bool _bWear);

	const char* Get_Name() const;
	const int& Get_Count() const;
	const int & Get_Price() const;
	const int & Get_Plus_HP() const;
	const int & Get_Plus_Attack() const;
	const bool & Get_Consume() const;
	const bool & Get_Wear() const;

private:
	char m_cItem_Name[15];

	int m_iPrice;

	bool m_bConsume;
	bool m_bWear;

	int m_iCount;

	int m_iPlus_HP;
	int m_iPlus_Attack;
};