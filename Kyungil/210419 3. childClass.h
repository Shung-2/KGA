#pragma once
#include "210419 2. motherclass.h"

// 상속하는법 ( : 접근제어자 상속하고자 하는 클래스) 
// 예제로는 아래와 같다.
class childClass : public motherclass
{
public:
	childClass();
	~childClass();
};

