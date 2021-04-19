#pragma once
#include <iostream>
using namespace std;

class mainGame2
{
private:
	// private == 개인적인, 개인의
	// 해당 클래스에서 사용할 변수는 여기에 선언
	// 해당 클래스 외부에서는 접근되지 않는다.

protected:
	// 어 뭔가 보호받고 있나?!
	// 상속관계에서만 접근이 가능하다.


public:
	// public == 공공의
	// 아무렇게나 접근 가능하다.
	// 보통 이곳에 함수를 선언한다.

	mainGame2();
	~mainGame2();
};

