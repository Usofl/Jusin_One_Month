// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include <iostream>
#include <assert.h>
#define SAFE_DELETE(p) {if (p != nullptr){delete p;} p = nullptr;}
#define SAFE_DELETE_ARRAY(p) {if (p != nullptr){delete[] p;} p = nullptr;}

extern int iChoice;

using namespace std;