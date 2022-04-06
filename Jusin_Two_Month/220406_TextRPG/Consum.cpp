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