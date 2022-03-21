#include "stdafx.h"
#include "School.h"

int CSchool::Menu()
{
	if (m_student == nullptr)
	{
		Init_Student();
	}

	system("cls");

	int iChoice = 0;

	cout << "1. �л� ��ü ��� 2. �л� �˻� 3. �л� �߰� 4. ����" << endl;

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

	cout << "�б� �ο����� �Է��Ͻÿ� : " << endl;

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

	cout << "�߰��� �б� �ο����� �Է��Ͻÿ� : " << endl;

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

	cout << "�˻��� �л��� �̸��� �Է��ϼ���(1~9��) : ";

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
		cout << "�˻��� �л��� �����ϴ�." << endl;
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
