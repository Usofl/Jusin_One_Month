#pragma once

enum Job
{
	Job_Start, Job_Warrior, Job_Magician, Job_Thief, Job_End
};

enum Feild
{
	Feild_Start, Feild_Hunting, Feild_Shop, Feild_Inventory, Feild_End
};

enum Monster
{
	Monster_Start, Monster_Junior, Monster_Sinior, Monster_Major, Monster_End
};

enum Combat
{
	Combat_Start, Combat_Attack, Combat_Item, Combat_End
};

template<typename T>
class CDelete
{
public:
	inline void operator()(T& _p)
	{
		if (nullptr != _p)
		{
			delete _p;
			_p = nullptr;
		}
	}
};