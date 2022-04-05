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
	cout << "±¹¾î : " << m_Grade[0] << endl;
	cout << "¿µ¾î : " << m_Grade[1] << endl;
	cout << "¼öÇÐ : " << m_Grade[2] << endl;
	cout << "ÃÑÇÕ : " << Get_Sum() << endl;
	cout << "Æò±Õ : " << Get_Avg() << endl;
}