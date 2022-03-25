#pragma once
#include "Player.h"

class CShop
{
public:
	CShop();
	~CShop();

	void Set_Player(CPlayer* _player);
	void Show_Item();
	void CloseUp_Item(const int& _iItem) const;

	void Initialize();
	void Update();
	void Release();

private:
	CPlayer* m_Player;
	CItem m_Shop_Item[10];
};