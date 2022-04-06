#pragma once

#include "Item.h"

class CConsum final : public CItem
{
public:
	CConsum();
	CConsum(const char* _cName, const int& _Attack, const int& _HP, const int& _Price, const int& _Turn = 0);
	~CConsum();

	void Render();

	inline void Set_Turn(const int& _Turn) { m_iTurn = _Turn; }
	inline void Set_Count(const int& _Count) { m_iCount = _Count; }

	inline const int& Get_Turn() { return m_iTurn; }
	inline const int& Get_Count() { return m_iCount; }

private:
	int m_iCount;
	int m_iTurn;
};