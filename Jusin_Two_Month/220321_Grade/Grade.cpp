#include "stdafx.h"
#include "Grade.h"

void CGrade::Print_Grade()
{
	cout << "���� : " << m_iKuk << endl;
	cout << "���� : " << m_iEng << endl;
	cout << "���� : " << m_iMath << endl;
	cout << "���� : " << Get_Sum() << endl;
	cout << "��� : " << Get_Avg() << endl;
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

const int CGrade::Get_Kuk()
{
	return m_iKuk;
}

const int CGrade::Get_Eng()
{
	return m_iEng;
}

const int CGrade::Get_Math()
{
	return m_iMath;
}

const int CGrade::Get_Sum()
{
	return m_iKuk + m_iEng + m_iMath;
}

const double CGrade::Get_Avg()
{
	double dAvg = Get_Sum() / 3.0;

	return dAvg;
}
