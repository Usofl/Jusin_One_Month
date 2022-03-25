#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
{

}

CPlayer::~CPlayer()
{

}

CStatus* CPlayer::Get_Status()
{
	return &m_status;
}