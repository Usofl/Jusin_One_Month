#include <iostream>

using namespace std;

const int iStudentCount = 3;
const int iNameCount = 20;
const int iGradeCount = 3;

struct Student
{
	char cName[iNameCount];
	int iKuk = 0, iEng = 0, iMath = 0;
};

void Menu();
int getSum(Student std);
double getAvg(Student std);
void InputStudent(Student stdArray[], int* iStdCount);
void PrintStudent(Student stdArray[], int* iStdCount);
void SearchStudent(Student stdArray[], int* iStdCount);

void main()
{
	// 4. 3���� �Է� ������ ����ǥ ���α׷� ����� (�̸�, ����, ����, ����, ����, ���) (����ü ��� ����)
	//  - 1. �Է� 2. ��ü ��� 3. �˻� ��� 4. ����
	int iChoice = 0, iInputStudent = 0;

	Student stdArray[iStudentCount] = {};

	void(*stdFun[3])(Student*, int*) = {InputStudent, PrintStudent, SearchStudent};

	while (iChoice != 4)
	{
		system("cls");
		Menu();

		cin >> iChoice;

		if (4 > iChoice && 0 < iChoice)
		{
			stdFun[iChoice - 1](stdArray, &iInputStudent);
		}
		else
		{
			continue;
		}

		system("pause");
	}
}

void Menu()
{
	cout << "============================================" << endl;
	cout << "1. �Է�\t2. ��ü ���\t3. �˻� ���\t4. ����" << endl;
	cout << "============================================" << endl;
}

int getSum(Student std)
{
	int iSum = std.iKuk + std.iEng + std.iMath;

	return iSum;
}

double getAvg(Student std)
{
	double dAvg = getSum(std) / iGradeCount;

	return dAvg;
}

void InputStudent(Student stdArray[], int* iStdCount)
{
	if (iStudentCount > *iStdCount)
	{
		cout << "�л��� �̸��� �Է��ϼ��� : ";
		cin >> stdArray[*iStdCount].cName;

		cout << "���� ������ �Է��ϼ��� : ";
		cin >> stdArray[*iStdCount].iKuk;

		cout << "���� ������ �Է��ϼ��� : ";
		cin >> stdArray[*iStdCount].iEng;

		cout << "���� ������ �Է��ϼ��� : ";
		cin >> stdArray[*iStdCount].iMath;

		(*iStdCount)++;
		cout << *iStdCount;
	}
	else
	{
		cout << "�Է°����� �л��� ���� �ʰ��Ǿ����ϴ�." << endl;
	}
	
}

void PrintStudent(Student stdArray[], int* iStdCount)
{
	for (int i = 0; i < *iStdCount; ++i)
	{
		Student std = stdArray[i];

		cout << "�̸� : " << std.cName << endl;
		cout << "���� : " << std.iKuk << endl;
		cout << "���� : " << std.iEng << endl;
		cout << "���� : " << std.iMath << endl;
		cout << "���� : " << getSum(std) << endl;
		cout << "��� : " << getAvg(std) << endl;
		cout << "============================================" << endl;
	}
}

void SearchStudent(Student stdArray[], int* iStdCount)
{
	char cSearchName[iNameCount] = {};
	cout << "�˻��� �л��� �̸��� �Է��Ͻÿ�." << endl;
	cin >> cSearchName;

	for (int i = 0; i < *iStdCount; ++i)
	{
		Student std = stdArray[i];

		if (!strcmp(std.cName, cSearchName))
		{
			cout << "�̸� : " << std.cName << endl;
			cout << "���� : " << std.iKuk << endl;
			cout << "���� : " << std.iEng << endl;
			cout << "���� : " << std.iMath << endl;
			cout << "���� : " << getSum(std) << endl;
			cout << "��� : " << getAvg(std) << endl;
			cout << "============================================" << endl;
		}
		else if (i == *iStdCount - 1)
		{
			cout << "�˻��� �л��� �����ϴ�." << endl;
		}
	}
}