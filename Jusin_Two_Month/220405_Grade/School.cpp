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
	cout << "����� �л��� ���� �Է��ϼ���." << endl;
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
		cout << "1. �л� �߰� �Է�\t2. ��ü �л� ���\t3.�˻� ���\t4. �л� ����\t5.����" << endl;
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
			cout << "���� �մϴ�." << endl;
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

	cout << "�˻��� �л��� �̸��� �Է��Ͻÿ�." << endl;
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
		cout << "�˻��� �л��� �����ϴ�." << endl;
	}
}
	
void CSchool::Delete_Student()
{
	system("cls");
	char cName[20];
	bool success = false;
	int iChoice = 0;

	cout << "������ �л��� �̸��� �Է��Ͻÿ�." << endl;
	cout << "=============================" << endl;
	cin >> cName;

	for (auto iter = m_Student.begin(); iter != m_Student.end(); ++iter)
	{
		if (!strcmp((*iter)->Get_Name(), cName))
		{
			system("cls");
			success = true;
			(*iter)->Render();
			cout << "���� �����Ͻðڽ��ϱ�?" << endl;
			cout << "1. �� 2. �ƴϿ�" << endl;
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
				cout << "�߸��Է��ϼ̽��ϴ�." << endl;
				--iter;
			}
		}
	}

	if (success)
	{
		cout << "���� ����" << endl;
	}
	else
	{
		cout << "�˻��� �л��� �����ϴ�." << endl;
	}
}