#pragma once
#include <iostream>
#include <list>
using namespace std;

class ListTest
{
private:
	// List�� �����Ͱ� 1���� �̻��϶� ������.
	// ����ũ�� ����Ʈ�� �����Ǿ� �ִ�.
	list<int>			_lNum;
	list<int>::iterator _liNum;

public:
	ListTest();
	~ListTest();
};

