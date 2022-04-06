#pragma once
#include "Status.h"

#include "Equipment.h"
#include "Consum.h"

class CPlayer final : public CStatus
{
public:
	CPlayer();
	virtual ~CPlayer();

	virtual void Render();
	virtual void Init_Stat(const int& _iChoice);

	void Level_Up_Cheak(const int& _Exp);

	inline void Set_Plus_HP(const int& _iPlus_HP) { m_iPlus_HP = _iPlus_HP; }
	inline void Set_Plus_Attack(const int& _iPlus_Attack) { m_iPlus_Attack = _iPlus_Attack; }

	inline const int& Get_Plus_Attack() { return m_iPlus_Attack; }
	inline const int& Get_Plus_HP() { return m_iPlus_HP; }

	void Show_Inventory();

	void Inventory_Render();
	void Set_Equipment(const int& _index);
	void Using_Consum(const int& _index);

	void Add_Item(const CConsum* _Consum, const CEquipment* _Equipment);

private:
	int m_iLevel;
	int m_iMax_Exp;
	int m_iPlus_HP;
	int m_iPlus_Attack;

	vector<CEquipment> m_vecEquipment;
	vector<CConsum> m_vecConsum;
};