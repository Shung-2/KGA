#include <iostream>
using namespace std;

int main()
{
	// 배열이란?
	// 같은 변수, 자료형의 연속적인 나열
	
	int num1[5];
						// sizeof(int) == 4
	num1[0] = 1;		// 1000 + 4 * 0
	num1[1] = 2;		// 1000 + 4 * 1
	num1[2] = 3;		// 1000 + 4 * 2
	num1[3] = 4;		// 1000 + 4 * 3
	num1[4] = 5;		// 1000 + 4 * 4

	int num2[30];
	for (int i = 0; i < 30; i++)
	{
		num2[i] = i + 1;
	}

	for (int i = 0; i < 30; i++)
	{
		cout << num2[i] << endl;
	}

	return 0;
}