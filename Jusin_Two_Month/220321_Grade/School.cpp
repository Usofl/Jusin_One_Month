#include "stdafx.h"
#include "School.h"

bool CSchool::Menu()
{
	if (m_student == nullptr)
	{
		Init_Student();
	}

	system("cls");

	int iChoice = 0;

	cout << "1. 학생 전체 출력 2. 학생 검색 3. 학생 추가 4. 종료" << endl;

	cin >> iChoice;

	switch (iChoice)
	{
	case 1:
		Print_All_Student();
		break;

	case 2:
		Print_Search_Student();
		break;

	case 3:
		Add_Student();
		break;
	
	case 4:
		Delete_Student();
		return false;
		break;
	
	default:
		break;
	}

	system("pause");

	return true;
}

void CSchool::Init_Student()
{
	int iChoice = 0;

	cout << "학급 인원수를 입력하시오 : " << endl;

	cin >> iChoice;

	m_Student_Size = iChoice;

	m_student = new CStudent[m_Student_Size];

	for (unsigned int i = 0; i < m_Student_Size; ++i)
	{
		m_student[i].Set_Student_info();
	}
}

void CSchool::Add_Student()
{
	int iChoice = 0;

	cout << "추가할 학급 인원수를 입력하시오 : " << endl;

	cin >> iChoice;

	CStudent* iTemp = new CStudent[m_Student_Size + iChoice];

	memcpy_s(iTemp, sizeof(iTemp[0]) * m_Student_Size, m_student, sizeof(iTemp[0]) * m_Student_Size);

	for (int i = 0; i < iChoice; ++i)
	{
		iTemp[m_Student_Size + i].Set_Student_info();
	}

	delete[] m_student;

	m_student = iTemp;
	m_Student_Size += iChoice;
}

void CSchool::Print_All_Student()
{
	for (unsigned int i = 0; i < m_Student_Size; ++i)
	{
		m_student[i].Print_Student_info();
	}
}

void CSchool::Print_Search_Student()
{
	char cName[20] = {};
	bool bSuccess = false;

	cout << "검색할 학생의 이름을 입력하세요(1~9자) : ";

	cin >> cName;


	for (unsigned int i = 0; i < m_Student_Size; ++i)
	{
		if (!strcmp(m_student[i].Get_Student_Name(), cName))
		{
			m_student[i].Print_Student_info();
			bSuccess = true;
		}
	}

	if (!bSuccess)
	{
		cout << "검색한 학생이 없습니다." << endl;
	}
}

void CSchool::Delete_Student()
{
	delete[] m_student;

	m_student = nullptr;
	m_Student_Size = 0;
}

size_t CSchool::Get_Student_Size()
{
	return m_Student_Size;
}
