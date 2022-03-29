#include "stdafx.h"
#include "Consum.h"

CConsum::CConsum()
	: CItem()
	, m_iCount(0)
	, m_iTurn(0)
{
}

CConsum::~CConsum()
{
}

void CConsum::Set_Turn(const int& _Turn)
{
	m_iTurn = _Turn;
}

void CConsum::Set_Count(const int& _Conut)
{
	m_iCount = _Conut;
}

const int& CConsum::Get_Turn()
{
	return m_iTurn;
}

const int& CConsum::Get_Count()
{
	return m_iCount;
}

void CConsum::Render_Consum()
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
