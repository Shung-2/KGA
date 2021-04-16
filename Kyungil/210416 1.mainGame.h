#pragma once
/*
컴파일러에게 해당 헤더 파일이 한번만 빌드되도록 한다. 해당 헤더파일이 여러번 include 되는 것을 막아준다.
여러곳에서 include 되면 그때마가 각각 정의가 추가되어 중첩되는 경우가 생기기 때문이다.
즉 중복된 내용이 여러번 빌드되는 것을 막기 위해 #pragma once를 사용한다
*/
#include <iostream>
using namespace std;

class mainGame
{
public:
	mainGame();		// 생성자 : 생성됨과 동시에 자동 실행 된다
	~mainGame();	// 소멸자 : 클래스가 종료됨가 동시에 자동 실행 된다.
};