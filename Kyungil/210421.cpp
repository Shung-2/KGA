#include <iostream>
#include "210421 1. ListTest.h"
#include "210421 2. MainGame.h"

int main()
{
	// 리스트 구현
	// ListTest lt;

	// 상점, 인벤토리 구현
	// MainGame mg;

	int a = 1, sum = 0;
	while (a++ < 10)
		sum += a * 3 >= sum ? a : 1;
	printf("%d", sum);
}

// 심화학습
// C++ single Linked List
// C++ 싱글링크드리스트(SLL)
// 스택, 큐, circle queue, binary three

// vecotr<tagItemInfo>&
// vecotr<tagItemInfo>