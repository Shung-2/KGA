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
		// �� �ȵɱ�? ���ʹ� �迭�̹Ƿ� �� �� �ִ�.
		// �׷����� ����Ʈ�� �迭�� �ƴϹǷ� ���� ����
	}
	*/

	for (_liNum = _lNum.begin(); _liNum != _lNum.end(); ++_liNum)
	{
		cout << *_liNum << endl;
	}
	// ++_liNum ���ͷ����ʹ� ���̱� ������ ��ġ�� ����Ѵ�

	_lNum.insert(_lNum.begin(), 500);

	// pop_front(), pop_back()
	// �� ���� �Լ��鵵 �翬�� �����Ѵ�.
}

ListTest::~ListTest()
{

}