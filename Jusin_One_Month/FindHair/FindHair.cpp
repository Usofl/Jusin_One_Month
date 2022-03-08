#include <iostream>

using namespace std;

struct Bback
{
	char cNickName[20];
	int iHairCount, iBrave;
};

void InsultPlayer(Bback* player);
void Menu(Bback* player);

void main()
{
	Bback Player{};
	bool bExit = true;
	int iChoice = 0;

	InsultPlayer(&Player);

	while (bExit)
	{
		system("cls");
		Menu(&Player);
	}
}

void InsultPlayer(Bback* player)
{
	cout << "머리카락을 찾아서..." << endl;
	cout << "=======================================" << endl;
	cout << "닉네임을 입력하세요 (1~10자) " << endl;
	cin >> player->cNickName;
	player->iBrave = 100;
	system("cls");
	cout << player->cNickName << "님 환영합니다." << endl;
	system("pause");
}

void Menu(Bback* player)
{
	cout << "머리카락을 찾아서..." << endl;
	cout << "용사 " << player->cNickName << endl;
	cout << "머리카락 : " << player->iHairCount << "용기 : " << player->iBrave << endl;
	cout << "=======================================" << endl;
	cout << "1. 던전\t2. 상점\t3. 종료" << endl;
}