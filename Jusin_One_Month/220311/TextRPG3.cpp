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

	cout << "������ �����մϴ�." << endl;
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
	cout << "TextRPG�� ���Ű��� ȯ���մϴ�." << endl;
	cout << "========================================" << endl;
	cout << "1. ���� 2. ������ 3.���� 4. �ҷ����� 5. ����" << endl;
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
		strcpy_s(player->cClass_Name, sizeof(player->cClass_Name),"����");
		player->iPlayer_Min_AttakPoint = 25;
		player->iPlayer_Max_AttakPoint = 30;
		player->iPlayer_Max_HP = 200;
		break;

	case 2:
		strcpy_s(player->cClass_Name, sizeof(player->cClass_Name), "������");
		player->iPlayer_Min_AttakPoint = 50;
		player->iPlayer_Max_AttakPoint = 70;
		player->iPlayer_Max_HP = 100;
		break;

	case 3:
		strcpy_s(player->cClass_Name, sizeof(player->cClass_Name), "����");
		player->iPlayer_Min_AttakPoint = 40;
		player->iPlayer_Max_AttakPoint = 50;
		player->iPlayer_Max_HP = 150;
		break;

	case 4:
		cout << "������ ĳ���͸� �ҷ��ɴϴ�." << endl;
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

	cout << "�г����� �Է��Ͻÿ�. (�ѱ� 1~5�� �̳�)" << endl;
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

	cout << "���ο� ĳ���͸� �����ϼ̽��ϴ�." << endl;
}

void LodePlayer(Player** player)
{
	FILE* player_File = nullptr;

	errno_t err = fopen_s(&player_File, "./Data/Save_Player.txt", "rb");

	if (0 == err)
	{
		cout << "�ҷ����� ����" << endl;

		fread(*player, sizeof(Player), 1, player_File);

		fclose(player_File);
	}
	else
	{
		cout << "�ҷ����� ����" << endl;
	}
}

void SavePlayer(Player* player)
{
	FILE* player_File = nullptr;

	errno_t err = fopen_s(&player_File, "./Data/Save_Player.txt", "wb");

	if (0 == err)
	{
		cout << "���� ����" << endl;

		fwrite(player, sizeof(Player), 1, player_File);

		fclose(player_File);
	}
	else
	{
		cout << "���� ����" << endl;
	}
}

void PrintPlayer(Player* player)
{
	puts("===================================");
	cout << "�̸� : " << player->cNickName << " / ���� : " << player->iPlayer_Level << endl;
	cout << "���� : " << player->cClass_Name << " / ������ �� : " << player->iHave_Money << endl;
	cout << "���ݷ� : " << player->iPlayer_Min_AttakPoint + player->iPlayer_Plus_AttakPoint;
	cout << " ~ " << player->iPlayer_Max_AttakPoint + player->iPlayer_Plus_AttakPoint << endl;
	cout << "HP : " << player->iPlayer_Lest_HP << " / " << player->iPlayer_Max_HP << endl;
	cout << "EXP : " << player->iPlayer_Have_Exp << " / " << player->iPlayer_Max_Exp << endl;
	puts("===================================");
}

void PrintMonster(Monster* monster)
{
	cout << "���� : " << monster->cMonster_Name << endl;
	cout << "���ݷ� : " << monster->iMonster_Min_AttakPoint << "~" << monster->iMonster_Max_AttakPoint << endl;
	cout << "HP : " << monster->iMonster_Lest_HP << " / " << monster->iMonster_Max_HP << endl;
	puts("===================================");
}

void Lobby(Player* player)
{
	system("cls");
	PrintPlayer(player);
	cout << "1. ����� 2. ���� 3. ���� 4. ����" << endl;

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
		cout << "���ݱ����� �����͸� �����Ͻðڽ��ϱ�?" << endl;
		cout << "========================================" << endl;
		cout << "1. �� 2. �ƴϿ�" << endl;

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
		cout << "�����Ͻ��� ���� �����ʹ� ���ư� �� �ֽ��ϴ�." << endl;
		cout << "�׷��� ���� �Ͻðڽ��ϱ�?" << endl;
		cout << "========================================" << endl;
		cout << "1. �� 2. �ƴϿ�" << endl;

		cin >> iChoice;
		Clear_Input();

		if (1 == iChoice)
		{
			player->bMaking_Player = false;
		}
		break;

	default:
		cout << "�߸��Է��ϼ̽��ϴ�." << endl;
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
	cout << "1. �ʱ� 2. �߱� 3. ��� 4. �ڷΰ���" << endl;

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
		cout << "�߸��Է��ϼ̽��ϴ�." << endl;
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
		cout << "1. ���� 2. ������ 3. ����" << endl;
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

				cout << "óġ ����" << endl;
				cout << "ȹ���� ��� " << Money << endl;
				player->iHave_Money += Money;
				cout << "ȹ���� ����ġ " << Exp << endl;
				Level_UP(player, Exp);

				system("pause");
				return;
			}

			player->iPlayer_Lest_HP -= RandomNum(monster->iMonster_Min_AttakPoint, monster->iMonster_Max_AttakPoint);

			if (player->iPlayer_Lest_HP <= 0)
			{
				Money = RandomNum(50 * iLevel, 100 * iLevel);
				Exp = RandomNum(5 * iLevel, 10 * iLevel);
				cout << "���.." << endl;
				cout << "�н��� ��� " << Money << endl;

				if (Money <= player->iHave_Money)
				{
					player->iHave_Money -= Money;
				}
				else
				{
					player->iHave_Money = 0;
				}
				
				cout << "�н��� ����ġ " << Exp << endl;

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
				cout << "��������" << endl;
			}
			else
			{
				cout << "��������" << endl;
				system("pause");
				return;
			}

			break;
		default:
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
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
		monster->cMonster_Name = "���̽�";
		monster->iMonster_Min_AttakPoint = 5;
		monster->iMonster_Max_AttakPoint = 7;
		monster->iMonster_Max_HP = 30;
		break;

	case 2:
		monster->cMonster_Name = "�ڹ�";
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
		cout << "������!" << endl;
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