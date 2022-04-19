// Jusin_Two_Month.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
