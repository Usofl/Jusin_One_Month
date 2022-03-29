// 220328_TextRPG.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Game.h"


int main()
{
	CGame game;

	game.Initialize();
	game.Update();

    return 0;
}

