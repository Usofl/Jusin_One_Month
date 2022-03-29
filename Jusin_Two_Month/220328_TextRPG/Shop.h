#pragma once

class CPlayer;
class CEquipment;
class CConsum;

class CShop
{
public:
	CShop();
	~CShop();

	void Initialize();
	void Update();
	void Release();

	void Set_Player(CPlayer* _player);
	void Shop_Render();

	void Buy_Item(int& _iChoice);

private:
	CPlayer* m_Player;
	CConsum* m_Consum;
	CEquipment* m_Equip;
};