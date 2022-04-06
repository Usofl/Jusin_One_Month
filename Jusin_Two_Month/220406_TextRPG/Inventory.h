#pragma once

#include "Equipment.h"
#include "Consum.h"

class CStatus;

class CInventory final
{
public:
	CInventory();
	~CInventory();

	void Initialize();
	void Update();
	void Release();

	inline void Set_Player(CStatus*& _player) { m_Player = _player; }

private:
	CStatus* m_Player;

};