#pragma once

class CPlayer;
class CMonster;

class CFeild
{
public:
	CFeild();
	~CFeild();

	void Initialize();
	void Update();
	void Release();

	void Set_Player(CPlayer* _player);

	void Hunting_Monster();

private:
	CPlayer* m_player;
	CMonster* m_monster;
};