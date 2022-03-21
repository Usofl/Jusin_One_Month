#pragma once

class CGrade
{
private:
	int m_iKuk;
	int m_iEng;
	int m_iMath;

public:
	void Print_Grade();
	
	void Set_Kuk(int _iKuk);
	void Set_Eng(int _iEng);
	void Set_Math(int _iMath);

	const int Get_Kuk();
	const int Get_Eng();
	const int Get_Math();
	const int Get_Sum();
	const double Get_Avg();
};