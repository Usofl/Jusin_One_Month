#pragma once

class CItem abstract
{
public:
	CItem()
		: m_cItem_Name("")
		, m_iPlus_Attack(0)
		, m_iPlus_HP(0)
		, m_iPrice(0)
	{
		
	}

	CItem(const char* _cName, const int& _Attack, const int& _HP, const int& _Price)
		: m_iPlus_Attack(_Attack)
		, m_iPlus_HP(_HP)
		, m_iPrice(_Price)
	{
		strcpy_s(m_cItem_Name, sizeof(m_cItem_Name), _cName);
	}

	virtual ~CItem() {}

	virtual void Render() = 0;

	inline const char* Get_Item_Name() const { return m_cItem_Name; }
	inline const int& Get_Plus_Attack() { return m_iPlus_Attack; }
	inline const int& Get_Plus_HP() { return m_iPlus_HP; }
	inline const int& Get_Price() { return m_iPrice; }

	inline bool operator==(const CItem& _rObj)
	{
		return !(strcmp(this->Get_Item_Name(), _rObj.Get_Item_Name()));
	}

private:
	char m_cItem_Name[20];
	int m_iPlus_Attack;
	int m_iPlus_HP;
	int m_iPrice;
};