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

	int Get_Kuk();
	int Get_Eng();
	int Get_Math();
	int Get_Sum();
	double Get_Avg();
};