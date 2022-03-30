#pragma once
#include "Feild.h"
#include "Monster.h"

class CHunting : public CFeild
{
public:
	CHunting();
	~CHunting();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

private:
	CStatus* m_Monster;
};