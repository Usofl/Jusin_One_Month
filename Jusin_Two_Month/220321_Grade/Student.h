#pragma once
#include "Grade.h"

class CStudent
{
private:
	char m_cName[20];
	CGrade m_grade;
public:
	void Print_Student_info();

	void Set_Student_info();

	void Set_Student_Name(char* _cName);

	char* Get_Student_Name();
};