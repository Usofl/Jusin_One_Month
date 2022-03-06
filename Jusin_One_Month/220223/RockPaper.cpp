#include <iostream>
#include <ctime>

using namespace std;

int computer();
int game(int _iChoice, int _iCom);
void trans(int _iCom);

void main()
{
	// 1. 가위바위보 게임 
	// 0~2까지 중 하나를 생성. (1. 가위 2. 바위 3. 보 4. 종료)
	// 입력한 값과 난수를 비교해서 가위바위보 승, 무, 패를 판별
	// 5라운드 실행수 승 무 패 출력 (자유)

	int iCom = 0, iPlayer = 0, iRound = 0, iWin = 0, iDraw = 0;
	bool bExit = true;

	while (bExit)
	{
		if (iRound == 5)
		{
			break;
		}

		system("cls");
		cout << "라운드 " << iRound + 1 << endl;
		cout << "=========================================" << endl;

		iCom = computer();

		trans(iCom);

		cout << "1. 가위\t2. 바위\t3. 보\t4. 종료" << endl;
		cin >> iPlayer;

		switch (game(iPlayer, iCom))
		{
		case 1:
			iWin++;
			cout << "승리" << endl;
			break;
		case 2:
			cout << "패배" << endl;
			break;
		case 3:
			iDraw++;
			cout << "무승부" << endl;
			break;
		case 4:
			bExit = false;
			break;
		default:
			iRound--;
			cout << "잘못입력하셨습니다." << endl;
			break;
		}

		iRound++;

		system("pause");
	}

	cout << iWin << "승 " << iDraw << "무 " << (iRound - iWin - iDraw) << "패 하셨습니다." << endl;
}

int computer()
{
	srand(unsigned(time(NULL)));

	return rand() % 3 + 1;
}

int game(int _iChoice, int _iCom)
{
	int iNum = 0;

	if (_iChoice == _iCom)
	{
		iNum = 3;
		return iNum;
	}

	if (1 == _iChoice)
	{
		if (3 == _iCom)
		{
			iNum = 1;
		}
		else
		{
			iNum = 2;
		}
	}
	else if (2 == _iChoice)
	{
		if (1 == _iCom)
		{
			iNum = 1;
		}
		else
		{
			iNum = 2;
		}
	}
	else if (3 == _iChoice)
	{
		if (2 == _iCom)
		{
			iNum = 1;
		}
		else
		{
			iNum = 2;
		}
	}
	else if (4 == _iChoice)
	{
		iNum = 4;
	}

	return iNum;
}

void trans(int _iCom)
{
	if (1 == _iCom)
	{
		cout << "가위" << endl;
	}
	else if (2 == _iCom)
	{
		cout << "바위" << endl;
	}
	else if (3 == _iCom)
	{
		cout << "보" << endl;
	}
}