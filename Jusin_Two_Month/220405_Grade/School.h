#pragma once
#include "Student.h"

class CSchool
{
public:
	void Initialize();
	void Update();
	void Release();

	void Render();
	void Serach_Student();
	void Delete_Student();

public:
	CSchool();
	~CSchool();

private:
	std::vector<CStudent*> m_Student;
};