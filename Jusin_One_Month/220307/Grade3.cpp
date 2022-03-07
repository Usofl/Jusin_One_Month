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
	// 4. 3명의 입력 가능한 성적표 프로그램 만들기 (이름, 국어, 영어, 수학, 총점, 평균) (구조체 사용 금지)
	//  - 1. 입력 2. 전체 출력 3. 검색 출력 4. 종료
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
	cout << "1. 입력\t2. 전체 출력\t3. 검색 출력\t4. 종료" << endl;
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
		cout << "학생의 이름을 입력하세요 : ";
		cin >> stdArray[*iStdCount].cName;

		cout << "국어 성적을 입력하세요 : ";
		cin >> stdArray[*iStdCount].iKuk;

		cout << "영어 성적을 입력하세요 : ";
		cin >> stdArray[*iStdCount].iEng;

		cout << "수학 성적을 입력하세요 : ";
		cin >> stdArray[*iStdCount].iMath;

		(*iStdCount)++;
		cout << *iStdCount;
	}
	else
	{
		cout << "입력가능한 학생의 수가 초과되었습니다." << endl;
	}
	
}

void PrintStudent(Student stdArray[], int* iStdCount)
{
	for (int i = 0; i < *iStdCount; ++i)
	{
		Student std = stdArray[i];

		cout << "이름 : " << std.cName << endl;
		cout << "국어 : " << std.iKuk << endl;
		cout << "영어 : " << std.iEng << endl;
		cout << "수학 : " << std.iMath << endl;
		cout << "총점 : " << getSum(std) << endl;
		cout << "평균 : " << getAvg(std) << endl;
		cout << "============================================" << endl;
	}
}

void SearchStudent(Student stdArray[], int* iStdCount)
{
	char cSearchName[iNameCount] = {};
	cout << "검색할 학생의 이름을 입력하시오." << endl;
	cin >> cSearchName;

	for (int i = 0; i < *iStdCount; ++i)
	{
		Student std = stdArray[i];

		if (!strcmp(std.cName, cSearchName))
		{
			cout << "이름 : " << std.cName << endl;
			cout << "국어 : " << std.iKuk << endl;
			cout << "영어 : " << std.iEng << endl;
			cout << "수학 : " << std.iMath << endl;
			cout << "총점 : " << getSum(std) << endl;
			cout << "평균 : " << getAvg(std) << endl;
			cout << "============================================" << endl;
		}
		else if (i == *iStdCount - 1)
		{
			cout << "검색한 학생이 없습니다." << endl;
		}
	}
}