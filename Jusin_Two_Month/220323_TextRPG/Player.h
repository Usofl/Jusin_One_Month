#pragma once

#include "Status.h"

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

	CStat* get_Status();

private:
	CStat m_Status;
};