// Jusin_Two_Month.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <set>
#include <string>

class A
{
	int i;
public:
	A(int ii = 0) : i(ii) {}
	void show() { cout << i << endl; }
};

class B
{
	int x;
public:
	B(int xx) : x(xx) {}
	operator A() const { return A(x); }
};

void g(A a)
{
	a.show();
}

int main()
{
	string ss = "fadsfas";

	if ('s' == ss[ss.size() - 1]);
	set<int> s;
	B b(10);
	g(b);
	g(20);
	return 0;
}
