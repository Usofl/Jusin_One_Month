#include "stdafx.h"
#include "Grade.h"

CGrade::CGrade()
	: m_Grade({0,0,0})
{
}

CGrade::~CGrade()
{
}

void CGrade::Print_Grade()
{
	cout << "���� : " << m_Grade[0] << endl;
	cout << "���� : " << m_Grade[1] << endl;
	cout << "���� : " << m_Grade[2] << endl;
	cout << "���� : " << Get_Sum() << endl;
	cout << "��� : " << Get_Avg() << endl;
}