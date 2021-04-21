#pragma once
#include <iostream>
#include <list>
using namespace std;

class ListTest
{
private:
	// List는 데이터가 1만개 이상일때 빠르다.
	// 더블링크드 리스트로 구성되어 있다.
	list<int>			_lNum;
	list<int>::iterator _liNum;

public:
	ListTest();
	~ListTest();
};

