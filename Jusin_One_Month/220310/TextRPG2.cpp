#include <iostream>

using namespace std;

struct Player
{
	char* cNickName;
	int iPlayer_AttakPoint;
	int iPlus_AttakPoint;
	int iPlayer_Lest_HP;
	int iPlayer_Max_HP;
	bool bMaking_Player;
};

struct Monster
{
	char* cMonster_Name;
	int iMonster_AttakPoint;
	int iMonster_Lest_HP;
	int iMonster_Max_HP;
};

void Menu();
void MakePlayer(Player* player);
Monster* MakeMonster(int iLevel);
void SelectMove(Player* player);
void SelectHunting_Point(Player* player);
void PrintPlayer(Player* player);
void PrintMonster(Monster* monster);
void Hunting_Monster(Player* player, Monster* monster);

void main()
{
	// 1. �����Ҵ����� textRPG �����
	Player* player = new Player;
	
	puts("Hello, TextRPG");
	
	MakePlayer(player);

	while(player->bMaking_Player)
	{
		system("cls");
		PrintPlayer(player);

		SelectMove(player);
	}

	delete player;
}

void MakePlayer(Player* player)
{
	int iChoice = 0;

	puts("������ �����Ͻÿ�.");
	puts("===================================");
	puts("1. ���� 2. ������ 3. ���� 4. ����");

	cin >> iChoice;

	switch (iChoice)
	{
	case 1:
		player->cNickName = "����";
		player->iPlayer_AttakPoint = 10;
		player->iPlayer_Max_HP = 200;
		player->iPlayer_Lest_HP = player->iPlayer_Max_HP;
		break;

	case 2:
		player->cNickName = "������";
		player->iPlayer_AttakPoint = 100;
		player->iPlayer_Max_HP = 100;
		player->iPlayer_Lest_HP = player->iPlayer_Max_HP;
		break;

	case 3:
		player->cNickName = "����";
		player->iPlayer_AttakPoint = 50;
		player->iPlayer_Max_HP = 150;
		break;

	case 4:
		player->bMaking_Player = false;
		break;

	default:
		puts("�߸��Է��ϼ̽��ϴ�.");

		system("pause");

		MakePlayer(player);
		return;
		break;
	}

	player->bMaking_Player = true;
}

Monster* MakeMonster(int iLevel)
{
	Monster* temp = new Monster;

	switch (iLevel)
	{
	case 1:
		temp->cMonster_Name = "������";
		temp->iMonster_AttakPoint = 5;
		temp->iMonster_Max_HP = 30;
		temp->iMonster_Lest_HP = temp->iMonster_Max_HP;
		break;
	case 2:
		temp->cMonster_Name = "ġ�佺";
		temp->iMonster_AttakPoint = 30;
		temp->iMonster_Max_HP = 80;
		temp->iMonster_Lest_HP = temp->iMonster_Max_HP;

		break;
	case 3:
		temp->cMonster_Name = "�����";
		temp->iMonster_AttakPoint = 80;
		temp->iMonster_Max_HP = 150;
		temp->iMonster_Lest_HP = temp->iMonster_Max_HP;
		break;
	default:
		break;
	}

	return temp;
}

void PrintPlayer(Player* player)
{
	puts("===================================");
	cout << "���� : " << player->cNickName << endl;
	cout << "���ݷ� : " << player->iPlayer_AttakPoint << endl;
	cout << "HP : " << player->iPlayer_Lest_HP << " / " << player->iPlayer_Max_HP << endl;
	puts("===================================");
}

void PrintMonster(Monster* monster)
{
	cout << "���� : " << monster->cMonster_Name << endl;
	cout << "���ݷ� : " << monster->iMonster_AttakPoint << endl;
	cout << "HP : " << monster->iMonster_Lest_HP << " / " << monster->iMonster_Max_HP << endl;
	puts("===================================");
}

void SelectMove(Player* player)
{
	int iChoice = 0;

	puts("1. ����� 2. ����");

	cin >> iChoice;

	switch (iChoice)
	{
	case 1:
		SelectHunting_Point(player);
		break;
	case 2:
		player->bMaking_Player = false;
		break;
	default:
		break;
	}
}

void SelectHunting_Point(Player* player)
{
	system("cls");
	PrintPlayer(player);

	int iChoice = 0;
	Monster* monster = nullptr;

	puts("1. �ʱ� 2. �߱� 3. ��� 4. �ڷΰ���");

	cin >> iChoice;

	if (4 > iChoice && 1 <= iChoice)
	{
		monster = MakeMonster(iChoice);
		Hunting_Monster(player, monster);
		delete monster;
	}
	else if (4 == iChoice)
	{
		return;
	}
	else
	{
		puts("�߸��Է��ϼ̽��ϴ�.");

		system("pause");

		SelectHunting_Point(player);
		return;
	}
}

void Hunting_Monster(Player* player, Monster* monster)
{
	bool bHunting_Check = true;
	int iChoice = 0;

	while (bHunting_Check)
	{
		system("cls");

		PrintPlayer(player);
		PrintMonster(monster);

		puts("1. ���� 2. ����");
		cin >> iChoice;

		switch (iChoice)
		{

		case 1:
			puts("����!");

			monster->iMonster_Lest_HP -= player->iPlayer_AttakPoint;

			if (0 >= monster->iMonster_Lest_HP)
			{
				puts("��� ����!");
				bHunting_Check = false;
			}

			player->iPlayer_Lest_HP -= monster->iMonster_AttakPoint;

			if (0 >= player->iPlayer_Lest_HP)
			{
				puts("���..");
				bHunting_Check = false;
				player->iPlayer_Lest_HP = player->iPlayer_Max_HP;
			}
			break;
		case 2:
			puts("����..");
			bHunting_Check = false;
			break;
		default:
			puts("�߸��Է��ϼ̽��ϴ�.");

			system("pause");
			break;
		}
	}

	system("pause");
}