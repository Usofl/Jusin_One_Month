#include "stdafx.h"
#include "School.h"

enum School_Manage
{
	School_Insert = 1, School_Print_All, School_Search, School_Delete, School_Exit 
};

CSchool::CSchool()
{

}

CSchool::~CSchool()
{
	Release();
}

void CSchool::Initialize()
{
	int iChoice = 0;
	system("cls");
	cout << "등록할 학생의 수를 입력하세요." << endl;
	cout << "=============================" << endl;
	cin >> iChoice;

	for (int i = 0; i < iChoice; ++i)
	{
		system("cls");
		CStudent* New_Student = new CStudent;

		New_Student->Initialize();
		m_Student.push_back(New_Student);
	}
}

void CSchool::Update()
{
	int iChoice = 0;
	while (true)
	{
		system("cls");
		cout << "1. 학생 추가 입력\t2. 전체 학생 출력\t3.검색 출력\t4. 학생 삭제\t5.종료" << endl;
		cout << "===============================================================" << endl;
		cin >> iChoice;

		switch (iChoice)
		{
		case School_Insert:
			Initialize();
			break;

		case School_Print_All:
			Render();
			break;

		case School_Search:
			Serach_Student();
			break;

		case School_Delete:
			Delete_Student();
			break;

		case School_Exit:
			cout << "종료 합니다." << endl;
			return;
			break;

		default:
			continue;
		}

		system("pause");
	}
}

void CSchool::Release()
{
	for (auto iter = m_Student.begin(); iter != m_Student.end(); ++iter)
	{
		if (*iter != nullptr)
		{
			delete *iter;
			*iter = nullptr;
		}
	}
}

void CSchool::Render()
{
	system("cls");
	cout << "=============================" << endl;
	for (auto iter = m_Student.begin(); iter != m_Student.end(); ++iter)
	{
		(*iter)->Render();
	}
}

void CSchool::Serach_Student()
{
	system("cls");
	char cName[20];
	bool success = false;

	cout << "검색할 학생의 이름을 입력하시오." << endl;
	cout << "=============================" << endl;
	cin >> cName;

	for (auto iter = m_Student.begin(); iter != m_Student.end(); ++iter)
	{
		if (!strcmp((*iter)->Get_Name(), cName))
		{
			success = true;
			(*iter)->Render();
		}
	}

	if (!success)
	{
		cout << "검색한 학생이 없습니다." << endl;
	}
}
	
void CSchool::Delete_Student()
{
	system("cls");
	char cName[20];
	bool success = false;
	int iChoice = 0;

	cout << "삭제할 학생의 이름을 입력하시오." << endl;
	cout << "=============================" << endl;
	cin >> cName;

	for (auto iter = m_Student.begin(); iter != m_Student.end(); ++iter)
	{
		if (!strcmp((*iter)->Get_Name(), cName))
		{
			system("cls");
			success = true;
			(*iter)->Render();
			cout << "정말 삭제하시겠습니까?" << endl;
			cout << "1. 예 2. 아니오" << endl;
			cin >> iChoice;
			if (1 == iChoice)
			{
				delete *iter;
				m_Student.erase(iter);
				break;
			}
			else if (2 == iChoice)
			{
				return;
			}
			else
			{
				cout << "잘못입력하셨습니다." << endl;
				--iter;
			}
		}
	}

	if (success)
	{
		cout << "삭제 성공" << endl;
	}
	else
	{
		cout << "검색한 학생이 없습니다." << endl;
	}
}