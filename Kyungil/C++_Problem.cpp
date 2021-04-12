#include <iostream>
using namespace std;

void Problem51p()
{
	int Money = 1000;
	int Candy_Price = 300;
	int Result = 0;

	cout << "현재 가지고 있는 돈 : " << Money << endl;
	cout << "캔디의 가격 : " << Candy_Price << endl;

	Result = Money / Candy_Price;
	cout << "최대로 살 수 있는 캔디의 개수 = " << Result << endl;

	Result = Money % Candy_Price;
	cout << "캔디 구입 후 남은 돈 = " << Result << endl;
}

void Problem53p()
{
	// 화씨온도 (미국)
	double f_temp = 0;
	// 섭씨온도 (한국)
	double c_temp = 0;

	cout << "화씨 온도를 입력하세요 : ";
	cin >> f_temp;

	c_temp = (5.0 / 9.0) * (f_temp - 32);
	cout << "화씨온도 : " << f_temp << "는 섭씨온도 : " << c_temp << "입니다.";
}

int main()
{
	// Problem51p();
	Problem53p();
	return 0;
}