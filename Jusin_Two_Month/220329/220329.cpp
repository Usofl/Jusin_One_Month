// 220329.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class cc
{
private:
public:
	virtual ~cc() { cout << "cc" << endl; }
	virtual void Render1() { cout << "1" << endl; }
	virtual void Render2() { cout << "2" << endl; }
	virtual void Render3() { cout << "3" << endl; }
};

class bb : public cc
{
private:
public:
	~bb() { cout << "bb" << endl; }
	virtual void Render2() { cout << "11" << endl; }
	virtual void Render3() { cout << "222" << endl; }
	virtual void Render1() { cout << "3333" << endl; }
};

class aa : public bb
{
private:
public:
	~aa() { cout << "aa" << endl; }
	virtual void Render2() { cout << "11" << endl; }
	virtual void Render3() { cout << "222" << endl; }
	virtual void Render1() { cout << "3333" << endl; }
};

int main()
{
	// 다형성
	// 오버라이딩 (! 핵심)
	// 캐스팅

	cc* c = new aa;

	c->Render1();

	cout << sizeof(cc) << endl;
	cout << sizeof(c) << endl;

	delete c;

    return 0;
}

