// stdafx.cpp : 표준 포함 파일만 들어 있는 소스 파일입니다.
// 220326_TextRPG.pch는 미리 컴파일된 헤더가 됩니다.
// stdafx.obj에는 미리 컴파일된 형식 정보가 포함됩니다.

#include "stdafx.h"

// TODO: 필요한 추가 헤더는
// 이 파일이 아닌 STDAFX.H에서 참조합니다.

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