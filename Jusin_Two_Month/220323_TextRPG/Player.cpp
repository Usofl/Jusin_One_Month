#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

CStat* CPlayer::get_Status()
{
	return &m_Status;
}