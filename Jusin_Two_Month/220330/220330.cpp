// 220330.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class cc
{
public:
	virtual void Render() { cout << "cccc" << endl; }
};

// virtual 붙어 있으면 무조건 동적바인딩

// 순수가상함수

// 자바는 꼭 붙혀야함

// 중간걸 인스턴스화 할거면 있어야하고, 안할거면 순수가상함수 해도 되지

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

