#pragma once

#include "Base.h"

class CMainApp : public CBase
{
private:
	CMainApp();
	virtual ~CMainApp();

public:
	static CMainApp* Create();
	virtual void Free() override;
};

