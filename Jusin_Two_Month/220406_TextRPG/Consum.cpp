#include "stdafx.h"
#include "Consum.h"

CConsum::CConsum()
	: CItem()
	, m_iCount(0)
	, m_iTurn()
{
}

CConsum::CConsum(const char* _cName, const int& _Attack, const int& _HP, const int& _Price, const int& _Turn)
	: CItem(_cName, _Attack, _HP, _Price)
	, m_iCount(0)
	, m_iTurn(_Turn)
{
}

CConsum::~CConsum()
{
}

void CConsum::Render()
{
	cout << "=================================================" << endl;
	cout << "이름 : [" << this->Get_Item_Name() << "]" << endl;
	cout << "효과" << endl;
	cout << "----------------------" << endl;
	cout << "사용시 ";
	if (this->Get_Turn())
	{
		cout << this->Get_Turn() << "턴 동안";
	}
	cout << endl;
	if (this->Get_Plus_Attack())
	{
		cout << "공격력 " << this->Get_Plus_Attack() << " 증가" << endl;
	}
	else if (this->Get_Plus_HP())
	{
		cout << "체력 " << this->Get_Plus_HP() << " 증가" << endl;
	}
	cout << "=================================================" << endl;
}