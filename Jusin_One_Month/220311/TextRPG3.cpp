#include <iostream>
#include <random>

using namespace std;

struct Player
{
	char cNickName[20];
	char cClass_Name[20];

	int iPlayer_Min_AttakPoint;
	int iPlayer_Max_AttakPoint;
	int iPlayer_Plus_AttakPoint;

	int iPlayer_Max_HP;
	int iPlayer_Lest_HP;

	int iPlayer_Level;
	int iPlayer_Max_Exp;
	int iPlayer_Have_Exp;

	int iHave_Money;

	bool bMaking_Player;
};

struct Monster
{
	char* cMonster_Name;

	int iMonster_Min_AttakPoint;
	int iMonster_Max_AttakPoint;

	int iMonster_Max_HP;
	int iMonster_Lest_HP;
};

int RandomNum(int MinNum, int MaxNum);
void Menu();
void MakePlayer(Player* player);
void LodePlayer(Player** player);
void SavePlayer(Player* player);
void PrintPlayer(Player* player);
void PrintMonster(Monster* monster);
void Lobby(Player* player);
void Hunting_Ground(Player* player);
void Hunting_Monster(Player* player, Monster* monster, int iLevel);
void Make_Monster(Monster* monster, int iLevel);
void Level_UP(Player* player, int iExp);
void Clear_Input();

void main()
{
	Menu();

	Player* player = new Player;

	MakePlayer(player);

	while (player->bMaking_Player)
	{
		Lobby(player);
	}

	cout << "게임을 종료합니다." << endl;
}

int RandomNum(int MinNum, int MaxNum)
{
	int iNum = 0;

	std::random_device rd;

	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(MinNum, MaxNum);
	iNum = dis(gen);

	return iNum;
}

void Menu()
{
	cout << "TextRPG에 오신것을 환영합니다." << endl;
	cout << "========================================" << endl;
	cout << "1. 전사 2. 마법사 3.도적 4. 불러오기 5. 종료" << endl;
}

void MakePlayer(Player* player)
{
	int iChoice = 0;
	char* cNick = new char;

	cin >> iChoice;
	Clear_Input();

	switch (iChoice)
	{
	case 1:
		strcpy_s(player->cClass_Name, sizeof(player->cClass_Name),"전사");
		player->iPlayer_Min_AttakPoint = 25;
		player->iPlayer_Max_AttakPoint = 30;
		player->iPlayer_Max_HP = 200;
		break;

	case 2:
		strcpy_s(player->cClass_Name, sizeof(player->cClass_Name), "마법사");
		player->iPlayer_Min_AttakPoint = 50;
		player->iPlayer_Max_AttakPoint = 70;
		player->iPlayer_Max_HP = 100;
		break;

	case 3:
		strcpy_s(player->cClass_Name, sizeof(player->cClass_Name), "도적");
		player->iPlayer_Min_AttakPoint = 40;
		player->iPlayer_Max_AttakPoint = 50;
		player->iPlayer_Max_HP = 150;
		break;

	case 4:
		cout << "저장한 캐릭터를 불러옵니다." << endl;
		LodePlayer(&player);
		return;
		break;

	case 5:
		player->bMaking_Player = false;
		return;
		break;

	default:
		break;
	}

	cout << "닉네임을 입력하시오. (한글 1~5자 이내)" << endl;
	cin >> cNick;
	Clear_Input();

	strcpy_s(player->cNickName, sizeof(player->cNickName), cNick);
	player->iPlayer_Lest_HP = player->iPlayer_Max_HP;
	player->iPlayer_Plus_AttakPoint = 0; 

	player->iPlayer_Level = 1;
	player->iPlayer_Max_Exp = 15;
	player->iPlayer_Have_Exp = 0;

	player->iHave_Money = 0;

	player->bMaking_Player = true;

	cout << "새로운 캐릭터를 생성하셨습니다." << endl;
}

void LodePlayer(Player** player)
{
	FILE* player_File = nullptr;

	errno_t err = fopen_s(&player_File, "./Data/Save_Player.txt", "rb");

	if (0 == err)
	{
		cout << "불러오기 성공" << endl;

		fread(*player, sizeof(Player), 1, player_File);

		fclose(player_File);
	}
	else
	{
		cout << "불러오기 실패" << endl;
	}
}

void SavePlayer(Player* player)
{
	FILE* player_File = nullptr;

	errno_t err = fopen_s(&player_File, "./Data/Save_Player.txt", "wb");

	if (0 == err)
	{
		cout << "저장 성공" << endl;

		fwrite(player, sizeof(Player), 1, player_File);

		fclose(player_File);
	}
	else
	{
		cout << "저장 실패" << endl;
	}
}

void PrintPlayer(Player* player)
{
	puts("===================================");
	cout << "이름 : " << player->cNickName << " / 레벨 : " << player->iPlayer_Level << endl;
	cout << "직업 : " << player->cClass_Name << " / 보유한 돈 : " << player->iHave_Money << endl;
	cout << "공격력 : " << player->iPlayer_Min_AttakPoint + player->iPlayer_Plus_AttakPoint;
	cout << " ~ " << player->iPlayer_Max_AttakPoint + player->iPlayer_Plus_AttakPoint << endl;
	cout << "HP : " << player->iPlayer_Lest_HP << " / " << player->iPlayer_Max_HP << endl;
	cout << "EXP : " << player->iPlayer_Have_Exp << " / " << player->iPlayer_Max_Exp << endl;
	puts("===================================");
}

void PrintMonster(Monster* monster)
{
	cout << "몬스터 : " << monster->cMonster_Name << endl;
	cout << "공격력 : " << monster->iMonster_Min_AttakPoint << "~" << monster->iMonster_Max_AttakPoint << endl;
	cout << "HP : " << monster->iMonster_Lest_HP << " / " << monster->iMonster_Max_HP << endl;
	puts("===================================");
}

void Lobby(Player* player)
{
	system("cls");
	PrintPlayer(player);
	cout << "1. 사냥터 2. 상점 3. 저장 4. 종료" << endl;

	int iChoice = 0;

	cin >> iChoice;
	Clear_Input();

	switch (iChoice)
	{
	case 1:
		Hunting_Ground(player);
		break;

	case 2:
		break;

	case 3:
		cout << "지금까지의 데이터를 저장하시겠습니까?" << endl;
		cout << "========================================" << endl;
		cout << "1. 예 2. 아니오" << endl;

		cin >> iChoice;
		Clear_Input();

		if (1 == iChoice)
		{
			SavePlayer(player);
		}
		else if (2 == iChoice)
		{
			return;
		}

		break;

	case 4:
		cout << "저장하시지 않은 데이터는 날아갈 수 있습니다." << endl;
		cout << "그래도 종료 하시겠습니까?" << endl;
		cout << "========================================" << endl;
		cout << "1. 예 2. 아니오" << endl;

		cin >> iChoice;
		Clear_Input();

		if (1 == iChoice)
		{
			player->bMaking_Player = false;
		}
		break;

	default:
		cout << "잘못입력하셨습니다." << endl;
		system("pause");
		return;
		break;
	}
}

void Hunting_Ground(Player* player)
{
	int iChoice = 0;

	system("cls");
	PrintPlayer(player);
	cout << "1. 초급 2. 중급 3. 고급 4. 뒤로가기" << endl;

	cin >> iChoice;
	Clear_Input();

	if (1 <= iChoice && 3 >= iChoice)
	{
		Monster* monster = new Monster;

		Make_Monster(monster, iChoice);
		Hunting_Monster(player, monster, iChoice);
	}
	else if (4 == iChoice)
	{
		return;
	}
	else
	{
		cout << "잘못입력하셨습니다." << endl;
		system("pause");
		Hunting_Ground(player);
		return;
	}
}

void Hunting_Monster(Player* player, Monster* monster, int iLevel)
{
	int iChoice = 0;
	int Min = 0, Max = 0, Money = 0, Exp = 0, iAway;
	while(true)
	{
		system("cls");
		PrintPlayer(player);
		PrintMonster(monster);
		cout << "1. 공격 2. 아이템 3. 도망" << endl;
		cout << "========================================" << endl;
		cin >> iChoice;

		Clear_Input();

		Min = player->iPlayer_Min_AttakPoint + player->iPlayer_Plus_AttakPoint;
		Max = player->iPlayer_Max_AttakPoint + player->iPlayer_Plus_AttakPoint;

		switch (iChoice)
		{
		case 1:
			monster->iMonster_Lest_HP -= RandomNum(Min, Max);

			if (monster->iMonster_Lest_HP <= 0)
			{
				Money = RandomNum(50 * iLevel, 100 * iLevel);
				Exp = RandomNum(5 * iLevel, 10 * iLevel);

				cout << "처치 성공" << endl;
				cout << "획득한 골드 " << Money << endl;
				player->iHave_Money += Money;
				cout << "획득한 경험치 " << Exp << endl;
				Level_UP(player, Exp);

				system("pause");
				return;
			}

			player->iPlayer_Lest_HP -= RandomNum(monster->iMonster_Min_AttakPoint, monster->iMonster_Max_AttakPoint);

			if (player->iPlayer_Lest_HP <= 0)
			{
				Money = RandomNum(50 * iLevel, 100 * iLevel);
				Exp = RandomNum(5 * iLevel, 10 * iLevel);
				cout << "사망.." << endl;
				cout << "분실한 골드 " << Money << endl;

				if (Money <= player->iHave_Money)
				{
					player->iHave_Money -= Money;
				}
				else
				{
					player->iHave_Money = 0;
				}
				
				cout << "분실한 경험치 " << Exp << endl;

				player->iPlayer_Lest_HP = player->iPlayer_Max_HP;

				if (Exp <= player->iPlayer_Have_Exp)
				{
					player->iPlayer_Have_Exp -= Exp;
				}
				else
				{
					player->iPlayer_Have_Exp = 0;
				}

				system("pause");
				return;
			}

			break;
		case 2:

			break;
		case 3:
			iAway = RandomNum(0, 5 - iLevel);

			if (iAway == 0)
			{
				cout << "도망실패" << endl;
			}
			else
			{
				cout << "도망성공" << endl;
				system("pause");
				return;
			}

			break;
		default:
			cout << "잘못입력하셨습니다." << endl;
			break;
		}

		system("pause");
	}
}

void Make_Monster(Monster* monster, int iLevel)
{
	switch (iLevel)
	{
	case 1:
		monster->cMonster_Name = "파이썬";
		monster->iMonster_Min_AttakPoint = 5;
		monster->iMonster_Max_AttakPoint = 7;
		monster->iMonster_Max_HP = 30;
		break;

	case 2:
		monster->cMonster_Name = "자바";
		monster->iMonster_Min_AttakPoint = 25;
		monster->iMonster_Max_AttakPoint = 35;
		monster->iMonster_Max_HP = 70;
		break;

	case 3:
		monster->cMonster_Name = "C++";
		monster->iMonster_Min_AttakPoint = 40;
		monster->iMonster_Max_AttakPoint = 60;
		monster->iMonster_Max_HP = 100;
		break;

	default:
		break;
	}

	monster->iMonster_Lest_HP = monster->iMonster_Max_HP;
}

void Level_UP(Player* player, int iExp)
{
	player->iPlayer_Have_Exp += iExp;

	if (player->iPlayer_Have_Exp >= player->iPlayer_Max_Exp)
	{
		cout << "레벨업!" << endl;
		player->iPlayer_Level += 1;

		player->iPlayer_Have_Exp = player->iPlayer_Have_Exp - player->iPlayer_Max_Exp;
		player->iPlayer_Max_Exp += 20;

		player->iPlayer_Min_AttakPoint += 5;
		player->iPlayer_Max_AttakPoint += 5;

		player->iPlayer_Max_HP += 10;
		player->iPlayer_Lest_HP = player->iPlayer_Max_HP;

		system("pause");
	}
}

void Clear_Input()
{
	while ('\n' != putchar(getchar()))
	{

	}
}