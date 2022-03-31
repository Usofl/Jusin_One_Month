#pragma once

class CMyString
{
public:
	CMyString();
	CMyString(char* _szStr);
	CMyString(CMyString& _rObj);
	~CMyString();

	CMyString& operator =(CMyString& rObj);

	void Str_Cpy(char* _szStr);
	const size_t& Str_Len(char* _szStr);
	const size_t& Get_Str_Size();

	CMyString& operator +(CMyString& rObj);
	bool operator == (const CMyString& _rObj);

	friend ostream& operator << (ostream &out, const CMyString& _rObj)
	{
		out << _rObj.m_CStr;

		return out;
	}

	void Release();

private:
	char* m_CStr;
	size_t m_Str_Size;
};

