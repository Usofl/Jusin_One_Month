#pragma once
#include <vector>

class CGrade
{
public:
	void Print_Grade();

	inline void Set_Kuk(int _iKuk) { m_Grade[0] = _iKuk; }
	inline void Set_Eng(int _iEng) { m_Grade[1] = _iEng; }
	inline void Set_Math(int _iMath) { m_Grade[2] = _iMath; }

	inline const int& Get_Kuk() { return m_Grade[0]; }
	inline const int& Get_Eng() { return m_Grade[1]; }
	inline const int& Get_Math() { return m_Grade[2]; }

	inline const int Get_Sum() { return Get_Kuk() + Get_Eng() + Get_Math(); }
	inline const double Get_Avg() { return static_cast<double>(Get_Sum()) / m_Grade.size(); }

public:
	CGrade();
	~CGrade();

private:
	std::vector<int> m_Grade;
};