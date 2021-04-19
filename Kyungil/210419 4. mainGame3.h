#pragma once
#include <iostream>
using namespace std;

class mainGame3
{
private	:

public	:
	mainGame3();
	~mainGame3();

	// 공격함수
	void attack();

	// mp를 소모하는 공격함수
	void attack(int mp);

	// 오버로드
	// 해당 객체 자체에서 함수를 재정의해서 쓰는 것
	// 함수를 구성하는 형태가 달라야한다.
};

