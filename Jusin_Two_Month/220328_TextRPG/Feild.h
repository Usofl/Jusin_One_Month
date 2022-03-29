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

private:
	CPlayer* m_Player;
	CMonster* m_Monster;
};