#pragma once

class CObj;

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Release(void);

private:
	HDC m_hDC;
	RECT m_rcArea;
	CObj* m_pPlayer;
	std::list<CObj*> m_Bullet_List;
};