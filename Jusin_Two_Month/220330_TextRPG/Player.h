#pragma once
#include "Status.h"

class CPlayer final : public CStatus
{
public:
	CPlayer();
	virtual ~CPlayer();

	virtual void Initialize(const int& _iChoice);

	virtual void Render();

	void Level_Cheak(const int& _iExp);

private:
	int m_iLevel;
	int m_iMax_Exp;
};