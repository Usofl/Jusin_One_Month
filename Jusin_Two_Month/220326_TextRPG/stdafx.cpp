// stdafx.cpp : ǥ�� ���� ���ϸ� ��� �ִ� �ҽ� �����Դϴ�.
// 220326_TextRPG.pch�� �̸� �����ϵ� ����� �˴ϴ�.
// stdafx.obj���� �̸� �����ϵ� ���� ������ ���Ե˴ϴ�.

#include "stdafx.h"

// TODO: �ʿ��� �߰� �����
// �� ������ �ƴ� STDAFX.H���� �����մϴ�.

int iChoice = 0;

int RandomNum(int _Min, int _Max)
{
	int iNum = 0;

	std::random_device rd;

	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(_Min, _Max);
	iNum = dis(gen);

	return iNum;
}