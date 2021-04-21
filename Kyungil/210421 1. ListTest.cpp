#include "210421 1. ListTest.h"

ListTest::ListTest()
{
	_lNum.push_back(100);
	_lNum.push_front(50);

	for (int i = 0; i < 3; i++)
	{
		_lNum.push_back(i + 1);
	}

	/* 
	for (int i = 0; i < _lNum.size(); i++)
	{
		cout << _lNum[i] << endl;
		// 왜 안될까? 벡터는 배열이므로 쓸 수 있다.
		// 그렇지만 리스트는 배열이 아니므로 쓸수 없다
	}
	*/

	for (_liNum = _lNum.begin(); _liNum != _lNum.end(); ++_liNum)
	{
		cout << *_liNum << endl;
	}
	// ++_liNum 이터레이터는 무겁기 때문에 전치를 사용한다

	_lNum.insert(_lNum.begin(), 500);

	// pop_front(), pop_back()
	// 와 같은 함수들도 당연히 존재한다.
}

ListTest::~ListTest()
{

}