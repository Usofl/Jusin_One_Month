#pragma once
#define SAFE_DELETE(p) if(p) {delete p; p = nullptr;}

enum Job
{
	Job_Start, Job_Warrior, Job_Magician, Job_Thief, Job_Exit
};

enum Feild
{
	Feild_Start, Feild_Hunting, Feild_Shop, Feild_Inventory, Feild_Exit
};

enum Monster
{
	Monster_Start, Monster_Junior, Monster_Middle, Monster_High, Monster_Exit
};

enum Combat
{
	Combat_Start, Combat_Attack, Combat_Item, Combat_Run, Combat_Exit
};