#pragma once
#include "Feild.h"
#include "Monster.h"

class CHunting final : public CFeild
{
public:
	CHunting();
	~CHunting();

	void Initialize();
	void Update();
	void Release();

	bool Attack_Monster();

private:
	CStatus* m_Monster;
};