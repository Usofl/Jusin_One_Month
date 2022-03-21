#include "stdafx.h"
#include "Student.h"

void CStudent::Print_Student_info()
{
	cout << "학생 이름 : " << m_cName << endl;
	cout << "=============================" << endl;
	m_grade.Print_Grade();
	cout << "=============================" << endl;
}

void CStudent::Set_Student_info()
{
	char cName[20] = {};
	int grade = 0;

	cout << "=============================" << endl;
	cout << "학생의 이름을 입력하세요(1~9자) : ";
	cin >> cName;
	Set_Student_Name(cName);

	cout << "학생의 국어 성적을 입력하세요(1~100) : ";
	cin >> grade;
	m_grade.Set_Kuk(grade);

	cout << "학생의 영어 성적을 입력하세요(1~100) : ";
	cin >> grade;
	m_grade.Set_Eng(grade);

	cout << "학생의 수학 성적을 입력하세요(1~100) : ";
	cin >> grade;
	m_grade.Set_Math(grade);
}

void CStudent::Set_Student_Name(char * _cName)
{
	strcpy_s(m_cName, sizeof(m_cName), _cName);
}

char * CStudent::Get_Student_Name()
{
	return m_cName;
}
