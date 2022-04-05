#pragma once
#include "Grade.h"

class CStudent
{
public:
	void Initialize();

	void Render();

	inline void Set_Name(const char* _szName) { strcpy_s(m_szName, sizeof(m_szName), _szName); }
	inline const char* Get_Name() { return m_szName; }
public:
	CStudent();
	~CStudent();

private:
	char m_szName[20];
	CGrade m_Grade;
};