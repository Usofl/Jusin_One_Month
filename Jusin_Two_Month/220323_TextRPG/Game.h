#pragma once

class CPlayer;
class CFeild;

class CGame
{
public:
	CGame();
	~CGame();

	void Initialize();
	void Update();
	void Release();

private:
	CPlayer* m_player;
	CFeild* m_feild;
};