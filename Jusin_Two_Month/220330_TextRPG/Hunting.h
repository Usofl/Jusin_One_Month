#pragma once
#include "Feild.h"
#include "Monster.h"

class CHunting  final : public CFeild
{
public:
	CHunting();
	virtual ~CHunting();

	virtual void Initialize();
	virtual void Update();
	virtual void Release();

private:
	CStatus* m_Monster;
};