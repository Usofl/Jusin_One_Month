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
	// �������� ��� ���� ������ ���� ���� (���� �� 10 ü 200, �� 100 ü 100, �� 20 ü 50)
	// ���ݷ� ü�� ���
	// �����, ���� (�� 5 30 , 50 60, 200 90)
	// �ʱ� �߱� ���
	// ���� ����
	// ���� ������ ��� ����
	// �÷��̾� ����� ���ܰ�� �̵�
	// ������ ���ܰ�� �̵�
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

	cout << "������ �����մϴ�." << endl;
}

void MakePlayer(Player* player)
{
	unsigned int iChoice = 0;

	cout << "======================================" << endl;
	cout << "������ �����ϼ���."<< endl;
	cout << "1. ���� 2. ������ 3. ���� 4. ����" << endl;
	cout << "======================================" << endl;
	cin >> iChoice;

	switch (iChoice)
	{
	case Warrior:
		player->cPlayerName = "����";
		player->iPlayer_HP = 200;
		player->iPlayer_Lest_HP = 200;
		player->iAttackPoint = 10;
		break;
	case Magician:
		player->cPlayerName = "������";
		player->iPlayer_HP = 100;
		player->iPlayer_Lest_HP = 100;
		player->iAttackPoint = 100;
		break;
	case Sif:
		player->cPlayerName = "����";
		player->iPlayer_HP = 50;
		player->iPlayer_Lest_HP = 50;
		player->iAttackPoint = 20;
		break;
	case PC_Exit:
		player->bGameExit = false;
		break;
	default:
		cout << "�߸��Է��ϼ̽��ϴ�." << endl;
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
	cout << "���� : " << player->cPlayerName << endl;
	cout << "���ݷ� : " << player->iAttackPoint << endl; 
	cout << "HP : " << player->iPlayer_Lest_HP << " / " << player->iPlayer_HP << endl;
	cout << "���� Ƚ�� : " << player->iDead_Count << endl;
	cout << "======================================" << endl;

	

	switch (player->iPlayer_Position)
	{
	case Lobby:
		cout << "1. ����� 2. ����" << endl;
		cin >> iChoice;

		player->iPlayer_Position = iChoice;

		break;
	case Hunting_Ground:
		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �ڷ�" << endl;
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
		monster->cMonsterName = "��Ȳ����";
		monster->iMonster_HP = 30;
		monster->iMonster_Lest_HP = 30;
		monster->iAttackPoint = 5;
		break;
	case Senior:
		monster->cMonsterName = "�ִϾ� �߷�";
		monster->iMonster_HP = 60;
		monster->iMonster_Lest_HP = 60;
		monster->iAttackPoint = 50;
		break;
	case Major:
		monster->cMonsterName = "ȥ����";
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
	cout << "���� : " << monster->cMonsterName << endl;
	cout << "���ݷ� : " << monster->iAttackPoint << endl;
	cout << "HP : " << monster->iMonster_Lest_HP << " / " << monster->iMonster_HP << endl;
	cout << "======================================" << endl;
	cout << "1. ���� 2. ����" << endl;
}

void HuntingMonster(Player* player, Monster* monster)
{
	cout << "����!" << endl;

	player->iPlayer_Lest_HP -= monster->iAttackPoint;
	monster->iMonster_Lest_HP -= player->iAttackPoint;
	
	if (player->iPlayer_Lest_HP <= 0)
	{
		cout << "�÷��̾ ����߽��ϴ�." << endl;
		player->iPlayer_Lest_HP = player->iPlayer_HP;
		player->iDead_Count++;
		player->iPlayer_Position = 0;
		monster->bAlive = false;
	}
	else if (monster->iMonster_Lest_HP <= 0)
	{
		cout << "��� ����." << endl;
		monster->bAlive = false;
		player->iPlayer_Position = 0;
	}

	system("pause");
}