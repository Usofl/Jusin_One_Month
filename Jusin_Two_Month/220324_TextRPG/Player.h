#pragma once
#include "Status.h"

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

	CStatus* Get_Status();

private:
	CStatus m_status;
};