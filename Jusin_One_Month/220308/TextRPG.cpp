#include <iostream>

using namespace std;

enum Player_Class
{
	Warrior = 1, Magician, Sif, PC_Exit
};

enum Player_Position
{
	Lobby, Hunting_Ground, PP_Exit, Junior = 11, Senior, Major, PP_Back
};

struct Player
{
	char* cPlayerName;
	int iPlayer_HP , iPlayer_Lest_HP;
	int iAttackPoint;
	int iPlayer_Position;
	int iDead_Count;
	bool bGameExit;
};

struct Monster
{
	char* cMonsterName;
	int iMonster_HP;
	int iMonster_Lest_HP;
	int iAttackPoint;
	bool bAlive = false;
};

void MakePlayer(Player* player);
void Menu(Player* player, Monster* monster);
void CreateMonster(Monster* monster, const unsigned int Level);
void MonsterMenu(Monster* monster);
void HuntingMonster(Player* player, Monster* monster);

void main()
{
	// 1. textRPG
	// 직업선택 출력 전사 마법사 도적 종료 (전사 공 10 체 200, 공 100 체 100, 공 20 체 50)
	// 공격력 체력 출력
	// 사냥터, 종료 (초 5 30 , 50 60, 200 90)
	// 초급 중급 고급
	// 전투 도망
	// 몬스터 죽으면 사냥 성공
	// 플레이어 사망시 전단계로 이동
	// 도망시 전단계로 이동
	Player* MyCha = new Player;

	Monster* monster = new Monster;

	MakePlayer(MyCha);

	while (MyCha->bGameExit)
	{
		system("cls");

		Menu(MyCha, monster);
	}

	delete MyCha;
	delete monster;

	cout << "게임을 종료합니다." << endl;
}

void MakePlayer(Player* player)
{
	unsigned int iChoice = 0;

	cout << "======================================" << endl;
	cout << "직업을 선택하세요."<< endl;
	cout << "1. 전사 2. 마법사 3. 도적 4. 종료" << endl;
	cout << "======================================" << endl;
	cin >> iChoice;

	switch (iChoice)
	{
	case Warrior:
		player->cPlayerName = "전사";
		player->iPlayer_HP = 200;
		player->iPlayer_Lest_HP = 200;
		player->iAttackPoint = 10;
		break;
	case Magician:
		player->cPlayerName = "마법사";
		player->iPlayer_HP = 100;
		player->iPlayer_Lest_HP = 100;
		player->iAttackPoint = 100;
		break;
	case Sif:
		player->cPlayerName = "도적";
		player->iPlayer_HP = 50;
		player->iPlayer_Lest_HP = 50;
		player->iAttackPoint = 20;
		break;
	case PC_Exit:
		player->bGameExit = false;
		break;
	default:
		cout << "잘못입력하셨습니다." << endl;
		MakePlayer(player);
		break;
	}

	player->iDead_Count = 0;
	player->iPlayer_Position = 0;
	player->bGameExit = true;
}

void Menu(Player* player, Monster* monster)
{
	unsigned int iChoice = 0;

	cout << "======================================" << endl;
	cout << "직업 : " << player->cPlayerName << endl;
	cout << "공격력 : " << player->iAttackPoint << endl; 
	cout << "HP : " << player->iPlayer_Lest_HP << " / " << player->iPlayer_HP << endl;
	cout << "죽은 횟수 : " << player->iDead_Count << endl;
	cout << "======================================" << endl;

	

	switch (player->iPlayer_Position)
	{
	case Lobby:
		cout << "1. 사냥터 2. 종료" << endl;
		cin >> iChoice;

		player->iPlayer_Position = iChoice;

		break;
	case Hunting_Ground:
		cout << "1. 초급 2. 중급 3. 고급 4. 뒤로" << endl;
		cin >> iChoice;
		iChoice += 10;

		player->iPlayer_Position = iChoice;

		break;
	case PP_Exit:
		player->bGameExit = false;
		break;
	case PP_Back:
		player->iPlayer_Position = 0;
		break;
	default:
		if (player->iPlayer_Position > 10 && player->iPlayer_Position < 14)
		{
			if (!monster->bAlive)
			{
				CreateMonster(monster, player->iPlayer_Position);
			}
			else
			{
				MonsterMenu(monster);
				cin >> iChoice;
				if (iChoice == 1)
				{
					HuntingMonster(player, monster);
				}
				else if (iChoice == 2)
				{
					player->iPlayer_Position = 0;
					monster->bAlive = false;
				}
			}
		}
		break;
	}
}

void CreateMonster(Monster* monster, const unsigned int Level)
{
	switch (Level)
	{
	case Junior:
		monster->cMonsterName = "주황버섯";
		monster->iMonster_HP = 30;
		monster->iMonster_Lest_HP = 30;
		monster->iAttackPoint = 5;
		break;
	case Senior:
		monster->cMonsterName = "주니어 발록";
		monster->iMonster_HP = 60;
		monster->iMonster_Lest_HP = 60;
		monster->iAttackPoint = 50;
		break;
	case Major:
		monster->cMonsterName = "혼테일";
		monster->iMonster_HP = 90;
		monster->iMonster_Lest_HP = 90;
		monster->iAttackPoint = 200;
		break;
	default:
		break;
	}

	monster->bAlive = true;
}

void MonsterMenu(Monster* monster)
{
	cout << "몬스터 : " << monster->cMonsterName << endl;
	cout << "공격력 : " << monster->iAttackPoint << endl;
	cout << "HP : " << monster->iMonster_Lest_HP << " / " << monster->iMonster_HP << endl;
	cout << "======================================" << endl;
	cout << "1. 공격 2. 도망" << endl;
}

void HuntingMonster(Player* player, Monster* monster)
{
	cout << "공격!" << endl;

	player->iPlayer_Lest_HP -= monster->iAttackPoint;
	monster->iMonster_Lest_HP -= player->iAttackPoint;
	
	if (player->iPlayer_Lest_HP <= 0)
	{
		cout << "플레이어가 사망했습니다." << endl;
		player->iPlayer_Lest_HP = player->iPlayer_HP;
		player->iDead_Count++;
		player->iPlayer_Position = 0;
		monster->bAlive = false;
	}
	else if (monster->iMonster_Lest_HP <= 0)
	{
		cout << "사냥 성공." << endl;
		monster->bAlive = false;
		player->iPlayer_Position = 0;
	}

	system("pause");
}