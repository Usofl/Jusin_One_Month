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

	cout << "학생의 이름을 입력하세요." << endl;
	cout << "=============================" << endl;
	cin >> cName;

	Set_Name(cName);

	while (true)
	{
		cout << "국어 성적을 입력하세요.(0~100)" << endl;
		cout << "=============================" << endl;
		cin >> iChoice;
		if (0 <= iChoice && 100 >= iChoice)
		{
			break;
		}
		else
		{
			cout << "잘못입력하셨습니다." << endl;
		}
	}
	m_Grade.Set_Kuk(iChoice);

	while (true)
	{
		cout << "영어 성적을 입력하세요.(0~100)" << endl;
		cout << "=============================" << endl;
		cin >> iChoice;
		if (0 <= iChoice && 100 >= iChoice)
		{
			break;
		}
		else
		{
			cout << "잘못입력하셨습니다." << endl;
		}
	}
	m_Grade.Set_Eng(iChoice);

	while (true)
	{
		cout << "수학 성적을 입력하세요.(0~100)" << endl;
		cout << "=============================" << endl;
		cin >> iChoice;
		if (0 <= iChoice && 100 >= iChoice)
		{
			break;
		}
		else
		{
			cout << "잘못입력하셨습니다." << endl;
		}
	}
	m_Grade.Set_Math(iChoice);
}

void CStudent::Render()
{
	cout << "학생 이름 : " << m_szName << endl;
	cout << "=============================" << endl;
	m_Grade.Print_Grade();
	cout << "=============================" << endl;
}