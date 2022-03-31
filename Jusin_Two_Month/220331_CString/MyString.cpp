#include "stdafx.h"
#include "MyString.h"


CMyString::CMyString()
	: m_CStr(nullptr)
	, m_Str_Size(0)
{
}


CMyString::CMyString(char * _szStr)
{
	Str_Cpy(_szStr);
}

CMyString::CMyString(CMyString & _rObj)
{
	if (this != &_rObj)
	{
		Str_Cpy(_rObj.m_CStr);
	}
}

CMyString::~CMyString()
{
	Release();
}

CMyString & CMyString::operator=(CMyString & _rObj)
{
	if (this != &_rObj)
	{
		this->Str_Cpy(_rObj.m_CStr);
	}

	return *this;
}

CMyString & CMyString::operator=(char * _szStr)
{
	this->Str_Cpy(_szStr);

	return *this;
}

void CMyString::Str_Cpy(char * _szStr)
{
	Release();

	m_Str_Size = Str_Len(_szStr);

	m_CStr = new char[m_Str_Size + 1];

	for (int i = 0; i <= m_Str_Size; ++i)
	{
		m_CStr[i] = _szStr[i];
	}
}

const size_t & CMyString::Str_Len(char * _szStr)
{
	char* str = _szStr;
	m_Str_Size = 0;

	while (*(str++) != '\0')
	{
		++m_Str_Size;
	}

	return m_Str_Size;
}

const size_t & CMyString::Get_Str_Size()
{
	return m_Str_Size;
}

CMyString & CMyString::operator+(CMyString & rObj)
{
	size_t new_Size = this->m_Str_Size + rObj.m_Str_Size;

	char* Str = new char[new_Size + 1];

	for (unsigned int i = 0; i < m_Str_Size; ++i)
	{
		Str[i] = m_CStr[i];
	}

	for (unsigned int i = 0; i <= rObj.m_Str_Size; ++i)
	{
		Str[m_Str_Size + i] = rObj.m_CStr[i];
	}

	Str_Cpy(Str);
	delete Str;

	return *this;
}

CMyString & CMyString::operator+(char * _szStr)
{
	size_t new_Size = this->m_Str_Size + Str_Len(_szStr);
	char* Str = new char[new_Size + 1];

	for (unsigned int i = 0; i < m_Str_Size; ++i)
	{
		Str[i] = m_CStr[i];
	}

	for (unsigned int i = 0; i <= Str_Len(_szStr); ++i)
	{
		Str[m_Str_Size + i] = _szStr[i];
	}

	Str_Cpy(Str);

	delete Str;

	return *this;
}

bool CMyString::operator==(const CMyString & _rObj)
{
	if (m_Str_Size != _rObj.m_Str_Size)
	{
		return false;
	}

	for (int i = 0; i <= m_Str_Size; ++i)
	{
		if (m_CStr[i] != _rObj.m_CStr[i])
		{
			return false;
		}
	}

	return true;
}

void CMyString::Release()
{
	if (m_CStr != nullptr)
	{
		delete m_CStr;
	}
	m_CStr = nullptr;
	m_Str_Size = 0;
}
