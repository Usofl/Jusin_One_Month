// 220330.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

class cc
{
public:
	virtual void Render() { cout << "cccc" << endl; }
};

// virtual �پ� ������ ������ �������ε�

// ���������Լ�

// �ڹٴ� �� ��������

// �߰��� �ν��Ͻ�ȭ �ҰŸ� �־���ϰ�, ���ҰŸ� ���������Լ� �ص� ����

class bb : public cc
{
public:
	void Render() { cout << "bbbb" << endl; }
};

class aa : public bb
{
public:
	void Render() { cout << "aaaa" << endl; }
};

int main()
{
	cc* c = new aa;

	c->Render();

    return 0;
}

