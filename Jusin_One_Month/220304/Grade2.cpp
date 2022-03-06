#include <iostream>

using namespace std;

const int iStudentCount = 3;
const int iNameCount = 20;
const int iGradeCount = 3;

void Menu();
void InputStudent(char cArray[], int iArray[]);
int getSum(int iArray[]);
double getAvg(int iSum);
void PrintStudent(char(*cArray)[iNameCount], int(*iArray)[iGradeCount], int iStudent);
void SearchStudent(char(*cArray)[iNameCount], int(*iArray)[iGradeCount], char* cName);

void main()
{
	// 4. 3���� �Է� ������ ����ǥ ���α׷� ����� (�̸�, ����, ����, ����, ����, ���) (����ü ��� ����)
	//  - 1. �Է� 2. ��ü ��� 3. �˻� ��� 4. ����
	int iChoice = 0, iInputStudent = 0;

	char cStudentArray[iStudentCount][iNameCount] = {};
	int iGradeArray[iStudentCount][iGradeCount] = {};

	while (iChoice != 4)
	{
		system("cls");
		Menu();

		cin >> iChoice;

		if (1 == iChoice)
		{
			if (iInputStudent < 3)
			{
				InputStudent(cStudentArray[iInputStudent], iGradeArray[iInputStudent]);
				iInputStudent++;
			}
			else
			{
				cout << "�Է� ������ �л��� ���� �ʰ��߽��ϴ�." << endl;
			}
		}
		else if (2 == iChoice)
		{
			PrintStudent(cStudentArray, iGradeArray, iInputStudent);
		}
		else if (3 == iChoice)
		{
			char cName[20] = {};
			cout << "�˻��� �л��� �̸��� ����Ͻÿ�." << endl;
			cin >> cName;

			SearchStudent(cStudentArray, iGradeArray, cName);
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

void InputStudent(char cArray[], int iArray[])
{
	cout << "�л��� �̸��� �Է��ϼ��� : ";
	cin >> cArray;

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iArray[0];

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iArray[1];

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> iArray[2];
}

int getSum(int iArray[])
{
	int iSum = 0;

	for (int i = 0; i < iGradeCount; ++i)
	{
		iSum += iArray[i];
	}

	return iSum;
}

double getAvg(int iSum)
{
	double dSum = iSum;

	return dSum / iGradeCount;
}

void PrintStudent(char(*cArray)[iNameCount], int(*iArray)[iGradeCount], int iStudent)
{
	for (int i = 0; i < iStudent; ++i)
	{
		cout << "�̸� : " << cArray[i] << endl;
		cout << "���� : " << iArray[i][0] << endl;
		cout << "���� : " << iArray[i][1] << endl;
		cout << "���� : " << iArray[i][2] << endl;
		cout << "���� : " << getSum(iArray[i]) << endl;
		cout << "��� : " << getAvg(getSum(iArray[i])) << endl;
		cout << "============================================" << endl;
	}
}

void SearchStudent(char(*cArray)[iNameCount], int(*iArray)[iGradeCount], char* cName)
{
	int iIndex = 0;
	for (int i = 0; i < iStudentCount; ++i)
	{
		if (cArray[i] == cName)
		{
			iIndex = i;
		}
	}

	cout << "�̸� : " << cArray[iIndex] << endl;
	cout << "���� : " << iArray[iIndex][0] << endl;
	cout << "���� : " << iArray[iIndex][1] << endl;
	cout << "���� : " << iArray[iIndex][2] << endl;
	cout << "���� : " << getSum(iArray[iIndex]) << endl;
	cout << "��� : " << getAvg(getSum(iArray[iIndex])) << endl;
	cout << "============================================" << endl;
}