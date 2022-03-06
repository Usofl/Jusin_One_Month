#include <iostream>
#include <ctime>

using namespace std;

void main()
{
	// 홀짝 게임 (난수를 뽑아서 그 숫자가 홀인지 짝인지 판별, 난수는 1~10까지 중 하나를 생성, 1. 홀수 2. 짝수 3. 종료
	// 총 5라운드 실시 라운드 종료시 몇 승 몇 패를 출력 매 라운드마다 난수를 새로 뽑음
	int iChoice = 0, iNum = 0, iWin = 0, iLose = 0, iRound = 0;

	while (5 > iRound)
	{
		system("cls");
		cout << "라운드 " << iRound + 1 << endl;
		cout << "=========================================" << endl;

		srand(unsigned(time(NULL)));

		iNum = rand() % 10;

		cout << iNum << endl;
		cout << "1. 홀수\t2. 짝수\t3. 종료" << endl;
		cin >> iChoice;

		if (1 == iChoice)
		{
			if (1 == iNum % 2)
			{
				iWin++;
				//				cout << "승리" << endl;
			}
			else
			{
				iLose++;
				//				cout << "패배" << endl;
			}
		}
		else if (2 == iChoice)
		{
			if (0 == iNum % 2)
			{
				iWin++;
				//				cout << "승리" << endl;
			}
			else
			{
				iLose++;
				//				cout << "패배" << endl;
			}
		}
		else if (3 == iChoice)
		{
			break;
		}
		else
		{
			cout << "잘못된 입력입니다." << endl;
			iRound--;
		}

		iRound++;
	}

	cout << iWin << "승 " << iLose << "패 하셨습니다." << endl;
}