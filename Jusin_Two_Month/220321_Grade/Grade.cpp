#include "stdafx.h"
#include "Grade.h"

void CGrade::Print_Grade()
{
	cout << "±¹¾î : " << m_iKuk << endl;
	cout << "¿µ¾î : " << m_iEng << endl;
	cout << "¼öÇÐ : " << m_iMath << endl;
	cout << "ÃÑÇÕ : " << Get_Sum() << endl;
	cout << "Æò±Õ : " << Get_Avg() << endl;
}

void CGrade::Set_Kuk(int _iKuk)
{
	m_iKuk = _iKuk;
}

void CGrade::Set_Eng(int _iEng)
{
	m_iEng = _iEng;
}

void CGrade::Set_Math(int _iMath)
{
	m_iMath = _iMath;
}

int CGrade::Get_Kuk()
{
	return m_iKuk;
}

int CGrade::Get_Eng()
{
	return m_iEng;
}

int CGrade::Get_Math()
{
	return m_iMath;
}

int CGrade::Get_Sum()
{
	return m_iKuk + m_iEng + m_iMath;
}

double CGrade::Get_Avg()
{
	double dAvg = Get_Sum() / 3.0;

	return dAvg;
}
