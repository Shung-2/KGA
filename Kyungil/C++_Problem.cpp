#include <iostream>
using namespace std;

void Problem51p()
{
	int Money = 1000;
	int Candy_Price = 300;
	int Result = 0;

	cout << "���� ������ �ִ� �� : " << Money << endl;
	cout << "ĵ���� ���� : " << Candy_Price << endl;

	Result = Money / Candy_Price;
	cout << "�ִ�� �� �� �ִ� ĵ���� ���� = " << Result << endl;

	Result = Money % Candy_Price;
	cout << "ĵ�� ���� �� ���� �� = " << Result << endl;
}

void Problem53p()
{
	// ȭ���µ� (�̱�)
	double f_temp = 0;
	// �����µ� (�ѱ�)
	double c_temp = 0;

	cout << "ȭ�� �µ��� �Է��ϼ��� : ";
	cin >> f_temp;

	c_temp = (5.0 / 9.0) * (f_temp - 32);
	cout << "ȭ���µ� : " << f_temp << "�� �����µ� : " << c_temp << "�Դϴ�.";
}

int main()
{
	// Problem51p();
	Problem53p();
	return 0;
}