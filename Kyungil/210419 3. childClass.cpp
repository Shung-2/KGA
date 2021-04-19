#include "210419 3. childClass.h"

childClass::childClass()
{
	/* 
	_motherMoney = 50; 
	*/
	// 접근되지 않는다. 왜? 어머니 클래스에서 프라이빗으로 선언했기 때문에!
	_familyMoney = 100;
	_freeMoney = 10;
}

childClass::~childClass()
{

}