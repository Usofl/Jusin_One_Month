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
	// 4. 3명의 입력 가능한 성적표 프로그램 만들기 (이름, 국어, 영어, 수학, 총점, 평균) (구조체 사용 금지)
	//  - 1. 입력 2. 전체 출력 3. 검색 출력 4. 종료
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
				cout << "입력 가능한 학생의 수가 초과했습니다." << endl;
			}
		}
		else if (2 == iChoice)
		{
			PrintStudent(cStudentArray, iGradeArray, iInputStudent);
		}
		else if (3 == iChoice)
		{
			char cName[20] = {};
			cout << "검색할 학생의 이름을 출력하시오." << endl;
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
	cout << "1. 입력\t2. 전체 출력\t3. 검색 출력\t4. 종료" << endl;
	cout << "============================================" << endl;
}

void InputStudent(char cArray[], int iArray[])
{
	cout << "학생의 이름을 입력하세요 : ";
	cin >> cArray;

	cout << "국어 성적을 입력하세요 : ";
	cin >> iArray[0];

	cout << "영어 성적을 입력하세요 : ";
	cin >> iArray[1];

	cout << "수학 성적을 입력하세요 : ";
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
		cout << "이름 : " << cArray[i] << endl;
		cout << "국어 : " << iArray[i][0] << endl;
		cout << "영어 : " << iArray[i][1] << endl;
		cout << "수학 : " << iArray[i][2] << endl;
		cout << "총점 : " << getSum(iArray[i]) << endl;
		cout << "평균 : " << getAvg(getSum(iArray[i])) << endl;
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

	cout << "이름 : " << cArray[iIndex] << endl;
	cout << "국어 : " << iArray[iIndex][0] << endl;
	cout << "영어 : " << iArray[iIndex][1] << endl;
	cout << "수학 : " << iArray[iIndex][2] << endl;
	cout << "총점 : " << getSum(iArray[iIndex]) << endl;
	cout << "평균 : " << getAvg(getSum(iArray[iIndex])) << endl;
	cout << "============================================" << endl;
}