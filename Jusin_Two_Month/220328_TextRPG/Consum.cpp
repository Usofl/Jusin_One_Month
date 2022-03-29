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
	cout << "�̸� : [" << this->Get_Item_Name() << "]" << endl;
	cout << "ȿ��" << endl;
	cout << "----------------------" << endl;
	cout << "���� ";
	if (this->Get_Turn())
	{
		cout << this->Get_Turn() << "�� ����";
	}
	cout << endl;
	if (this->Get_Plus_Attack())
	{
		cout << "���ݷ� " << this->Get_Plus_Attack() << " ����" << endl;
	}
	else if (this->Get_Plus_HP())
	{
		cout << "ü�� " << this->Get_Plus_HP() << " ����" << endl;
	}
	cout << "=================================================" << endl;
}
