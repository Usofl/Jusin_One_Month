#pragma once
#include "AbstractFactory.h"
#include "Obj.h"
#include "Player.h"
#include "Monster.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void Initialize(void);
	void Update(void);
	void Late_Update(void);
	void Render(void);
	void Release(void);

private:
	void Key_Input(void);

private:
	HDC m_hDC;
	std::list<CObj*> m_ObjList[OBJ_END];
};

