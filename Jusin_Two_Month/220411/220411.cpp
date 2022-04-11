// 220411.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	/*
		c89, c99, c11
		auto

		범위기반 for :: 간단하고 배열의 범위를 넘어가는 행동을 못함
		for(int i : iArray)
			cout << i << endl;

		for(auto& iter : vec)
			cout << iter << endl;

		유니폼 초기화
		int iArray[5]{0,0,0,0,0};

		tagInfo tInfo{10,20};

		그래서 unordered <- 정렬 안하니까

		매미 *****
		
		array : 기존에 사용하던 배열을 객체화 시킴
				생성자, 소멸자 등등 가지고있음;
				정적인 배열이라 벡터에 비해 메모리를 절약할 수 있드아.

				array.data(); : 배열의 첫번째 주소 반환;
				.fill(123);   : 배열의 모든값을 매개변수로 채운다.

		람다 표현식(lambda)
			[= , &] = 캡쳐블록
			() = 매개변수
			{} = 구현부
	*/
	
    return 0;
}

