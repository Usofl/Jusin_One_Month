#pragma once

// �Լ� ���ø�

template<typename T>
void		Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

template<typename T>
void		Safe_Delete_Array(T& Temp)
{
	if (Temp)
	{
		delete[] Temp;
		Temp = nullptr;
	}
}


// �Լ� ��ü

class CDeleteObj
{
public:
	template<typename T>
	void		operator()(T& Temp)
	{
		if (Temp)
		{
			delete Temp;
			Temp = nullptr;
		}
	}
};

class CDeleteMap
{
public:
	template<typename T>
	void		operator()(T& Pair)
	{
		if (Pair.second)
		{
			delete Pair.second;
			Pair.second = nullptr;
		}
	}
};

class CTag_Finder
{
public:
	CTag_Finder(char* pTag) : m_pTag(pTag) {}

public:
	template<typename T>
	bool operator()(T& Pair)
	{
		return !strcmp(Pair.first, m_pTag);
	}

private:
	char*		m_pTag;
};

static D3DXVECTOR3		Get_Mouse(void)
{
	POINT	Pt{};

	GetCursorPos(&Pt);
	ScreenToClient(g_hWnd, &Pt);

	return D3DXVECTOR3((float)Pt.x, (float)Pt.y, 0.f);
}