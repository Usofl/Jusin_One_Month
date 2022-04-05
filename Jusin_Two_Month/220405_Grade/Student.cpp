#include "stdafx.h"
#include "Student.h"

CStudent::CStudent()
	: m_szName()
	, m_Grade()
{

}

CStudent::~CStudent()
{

}

void CStudent::Initialize()
{
	char cName[20];
	int iChoice = 0;

	cout << "�л��� �̸��� �Է��ϼ���." << endl;
	cout << "=============================" << endl;
	cin >> cName;

	Set_Name(cName);

	while (true)
	{
		cout << "���� ������ �Է��ϼ���.(0~100)" << endl;
		cout << "=============================" << endl;
		cin >> iChoice;
		if (0 <= iChoice && 100 >= iChoice)
		{
			break;
		}
		else
		{
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
		}
	}
	m_Grade.Set_Kuk(iChoice);

	while (true)
	{
		cout << "���� ������ �Է��ϼ���.(0~100)" << endl;
		cout << "=============================" << endl;
		cin >> iChoice;
		if (0 <= iChoice && 100 >= iChoice)
		{
			break;
		}
		else
		{
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
		}
	}
	m_Grade.Set_Eng(iChoice);

	while (true)
	{
		cout << "���� ������ �Է��ϼ���.(0~100)" << endl;
		cout << "=============================" << endl;
		cin >> iChoice;
		if (0 <= iChoice && 100 >= iChoice)
		{
			break;
		}
		else
		{
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
		}
	}
	m_Grade.Set_Math(iChoice);
}

void CStudent::Render()
{
	cout << "�л� �̸� : " << m_szName << endl;
	cout << "=============================" << endl;
	m_Grade.Print_Grade();
	cout << "=============================" << endl;
}