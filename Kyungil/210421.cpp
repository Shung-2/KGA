#include <iostream>
#include "210421 1. ListTest.h"
#include "210421 2. MainGame.h"

int main()
{
	// ����Ʈ ����
	// ListTest lt;

	// ����, �κ��丮 ����
	// MainGame mg;

	int a = 1, sum = 0;
	while (a++ < 10)
		sum += a * 3 >= sum ? a : 1;
	printf("%d", sum);
}

// ��ȭ�н�
// C++ single Linked List
// C++ �̱۸�ũ�帮��Ʈ(SLL)
// ����, ť, circle queue, binary three

// vecotr<tagItemInfo>&
// vecotr<tagItemInfo>