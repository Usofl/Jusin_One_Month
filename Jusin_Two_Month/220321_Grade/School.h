#pragma once
#include "Student.h"

class CSchool
{
private:
	CStudent* m_student = nullptr;
	size_t m_Student_Size = 0;
public:
	int Menu();

	void Init_Student();
	void Add_Student();
	void Print_All_Student();
	void Print_Search_Student();

	void Delete_Student();

	size_t Get_Student_Size();
};