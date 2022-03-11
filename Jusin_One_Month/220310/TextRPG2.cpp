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

int RandomNum(int MaxNum);
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
	// 1. 동적할당으로 textRPG 만들기
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

	puts("직업을 선택하시오.");
	puts("===================================");
	puts("1. 전사 2. 마법사 3. 도적 4. 종료");

	cin >> iChoice;

	switch (iChoice)
	{
	case 1:
		player->cNickName = "전사";
		player->iPlayer_AttakPoint = 10;
		player->iPlayer_Max_HP = 200;
		player->iPlayer_Lest_HP = player->iPlayer_Max_HP;
		break;

	case 2:
		player->cNickName = "마법사";
		player->iPlayer_AttakPoint = 100;
		player->iPlayer_Max_HP = 100;
		player->iPlayer_Lest_HP = player->iPlayer_Max_HP;
		break;

	case 3:
		player->cNickName = "도적";
		player->iPlayer_AttakPoint = 50;
		player->iPlayer_Max_HP = 150;
		player->iPlayer_Lest_HP = player->iPlayer_Max_HP;
		break;

	case 4:
		player->bMaking_Player = false;
		break;

	default:
		puts("잘못입력하셨습니다.");

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
		temp->cMonster_Name = "맛동산";
		temp->iMonster_AttakPoint = 5;
		temp->iMonster_Max_HP = 30;
		temp->iMonster_Lest_HP = temp->iMonster_Max_HP;
		break;
	case 2:
		temp->cMonster_Name = "치토스";
		temp->iMonster_AttakPoint = 30;
		temp->iMonster_Max_HP = 80;
		temp->iMonster_Lest_HP = temp->iMonster_Max_HP;

		break;
	case 3:
		temp->cMonster_Name = "새우깡";
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
	cout << "직업 : " << player->cNickName << endl;
	cout << "공격력 : " << player->iPlayer_AttakPoint << endl;
	cout << "HP : " << player->iPlayer_Lest_HP << " / " << player->iPlayer_Max_HP << endl;
	puts("===================================");
}

void PrintMonster(Monster* monster)
{
	cout << "몬스터 : " << monster->cMonster_Name << endl;
	cout << "공격력 : " << monster->iMonster_AttakPoint << endl;
	cout << "HP : " << monster->iMonster_Lest_HP << " / " << monster->iMonster_Max_HP << endl;
	puts("===================================");
}

void SelectMove(Player* player)
{
	int iChoice = 0;

	puts("1. 사냥터 2. 종료");

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

	puts("1. 초급 2. 중급 3. 고급 4. 뒤로가기");

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
		puts("잘못입력하셨습니다.");

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

		puts("1. 공격 2. 도망");
		cin >> iChoice;

		switch (iChoice)
		{

		case 1:
			puts("공격!");

			monster->iMonster_Lest_HP -= player->iPlayer_AttakPoint;

			if (0 >= monster->iMonster_Lest_HP)
			{
				puts("사냥 성공!");
				bHunting_Check = false;
			}

			player->iPlayer_Lest_HP -= monster->iMonster_AttakPoint;

			if (0 >= player->iPlayer_Lest_HP)
			{
				puts("사망..");
				bHunting_Check = false;
				player->iPlayer_Lest_HP = player->iPlayer_Max_HP;
			}
			break;
		case 2:
			puts("도망..");
			bHunting_Check = false;
			break;
		default:
			puts("잘못입력하셨습니다.");

			system("pause");
			break;
		}
	}

	system("pause");
}