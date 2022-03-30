#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
	: m_iLevel(1)
	, m_iMax_Exp(100)
{

}

CPlayer::~CPlayer()
{

}

void CPlayer::Initialize(const int& _iChoice)
{
	switch (_iChoice)
	{
	case Job_Warrior:
		Set_Name("����");
		Set_Attack(10);
		Set_Max_HP(100);
		break;
	case Job_Magician:
		Set_Name("������");
		Set_Attack(30);
		Set_Max_HP(60);
		break;
	case Job_Thief:
		Set_Name("����");
		Set_Attack(20);
		Set_Max_HP(80);
		break;
	default:
		break;
	}
	Set_Lest_HP(Get_Max_HP());
}

void CPlayer::Render()
{
	cout << "���� : " << m_iLevel << " < " << Get_Exp() << " / " << m_iMax_Exp << " >" << endl;
	cout << "������ : " << Get_Money() << "��" << endl;
	cout << "=================================================" << endl;
	cout << "���� : " << Get_Name() << endl;
	cout << "���ݷ� : " << Get_Attack() << endl;
	cout << "ü�� : <" << Get_Lest_HP() << " / " << Get_Max_HP() << ">" << endl;
	cout << "=================================================" << endl;
}

void CPlayer::Level_Cheak(const int& _iExp)
{
	Set_Exp(Get_Exp() + _iExp);

	if (m_iMax_Exp <= Get_Exp())
	{
		++m_iLevel;
		Set_Exp(Get_Exp() - m_iMax_Exp);
		m_iMax_Exp += 10;
		Set_Attack(Get_Attack() + 10);
		Set_Max_HP(Get_Max_HP() + 20);
		Set_Lest_HP(Get_Max_HP());
	}
}
