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
	cout << "�Ӹ�ī���� ã�Ƽ�..." << endl;
	cout << "=======================================" << endl;
	cout << "�г����� �Է��ϼ��� (1~10��) " << endl;
	cin >> player->cNickName;
	player->iBrave = 100;
	system("cls");
	cout << player->cNickName << "�� ȯ���մϴ�." << endl;
	system("pause");
}

void Menu(Bback* player)
{
	cout << "�Ӹ�ī���� ã�Ƽ�..." << endl;
	cout << "��� " << player->cNickName << endl;
	cout << "�Ӹ�ī�� : " << player->iHairCount << "��� : " << player->iBrave << endl;
	cout << "=======================================" << endl;
	cout << "1. ����\t2. ����\t3. ����" << endl;
}