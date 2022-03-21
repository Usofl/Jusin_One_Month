#include "stdafx.h"
#include "Student.h"

void CStudent::Print_Student_info()
{
	cout << "�л� �̸� : " << m_cName << endl;
	cout << "=============================" << endl;
	m_grade.Print_Grade();
	cout << "=============================" << endl;
}

void CStudent::Set_Student_info()
{
	char cName[20] = {};
	int grade = 0;

	cout << "=============================" << endl;
	cout << "�л��� �̸��� �Է��ϼ���(1~9��) : ";
	cin >> cName;
	Set_Student_Name(cName);

	cout << "�л��� ���� ������ �Է��ϼ���(1~100) : ";
	cin >> grade;
	m_grade.Set_Kuk(grade);

	cout << "�л��� ���� ������ �Է��ϼ���(1~100) : ";
	cin >> grade;
	m_grade.Set_Eng(grade);

	cout << "�л��� ���� ������ �Է��ϼ���(1~100) : ";
	cin >> grade;
	m_grade.Set_Math(grade);
}

void CStudent::Set_Student_Name(char * _cName)
{
	strcpy_s(m_cName, sizeof(m_cName), _cName);
}

const char * CStudent::Get_Student_Name()
{
	return m_cName;
}
