#include <iostream>
#include <time.h>
#include <math.h>
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
	cout << "캔디 구입 후 남은 돈 = " << Result << endl << endl;
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
	cout << "화씨온도 : " << f_temp << "는 섭씨온도 : " << c_temp << "입니다." << endl << endl;
}

void Problem55p()
{
	srand(time(NULL));
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	cout << "두 주사위의 합 = " << dice1 + dice2 << endl << endl;
}

void Problem59_1()
{
	string str1, str2, str3;
	cout << "주어 : ";
	cin >> str1;
	cout << "동사 : ";
	cin >> str2;
	cout << "목적어 : ";
	cin >> str3;

	cout << str1 << ' ' << str2 << ' ' << 'a' << ' ' << str3 << endl << endl;
}

void Problem59_2()
{
	int age;
	cout << "나이 : ";
	cin >> age;

	cout << "10년 후에는 " << age + 10 << "살이 됩니다." << endl << endl;
}

void Problem59_3()
{
	int SideX, SideY, Hypotenuse;

	cout << "첫 번째 변 : ";
	cin >> SideX;
	cout << "두 번째 변 : ";
	cin >> SideY;

	Hypotenuse = sqrt(SideX * SideX + SideY * SideY);
	cout << "빗변 길이 : " << Hypotenuse << endl << endl;
}

void Problem59_4()
{
	int l, w, h, Volume, surface_area;

	cout << "길이 : ";
	cin >> l;
	cout << "너비 : ";
	cin >> w;
	cout << "높이 : ";
	cin >> h;

	Volume = l * w * h;
	surface_area = 2 * ((l * w) + (l * h) + (h * w));

	cout << "상자의 부피 : " << Volume << endl;
	cout << "상자의 표면젹 : " << surface_area << endl << endl;
}

void Problem59_5()
{
	double PYEONG = 3.3058;
	int value;

	cout << "평 : ";
	cin >> value;
	cout << "평방미터 : " << PYEONG * value << endl << endl;
}

void Problem59_6()
{
	int Hour, Minute, Second, Result;

	cout << "시 : ";
	cin >> Hour;
	cout << "분 : ";
	cin >> Minute;
	cout << "초 : ";
	cin >> Second;

	Result = Hour * 3600 + Minute * 60 + Second;
	cout << "전체 초 : " << Result << endl << endl;
}

void Problem59_7()
{
	const double pi = 3.141592;
	double radius, surface_area, volume;

	cout << "반지름 : ";
	cin >> radius;

	surface_area = 4 * pi * pow(radius, 2);
	volume = 4 / 3 * pi * pow(radius, 3);

	cout << "표면적 : " << surface_area << endl;
	cout << "부피 : " << volume << endl << endl;
}

void Problem59_8()
{
	int quiz1, quiz2, quiz3, mid, final, result;
	cout << "퀴즈	#1 성적 : ";
	cin >> quiz1;
	cout << "퀴즈	#2 성적 : ";
	cin >> quiz2;
	cout << "퀴즈	#3 성적 : ";
	cin >> quiz3;
	cout << "중간고서 성적 : ";
	cin >> mid;
	cout << "기말고사 성적 : ";
	cin >> final;

	result = quiz1 + quiz2 + quiz3 + mid + final;
	cout << "=======================" << endl;
	cout << "성적 총 합 : " << result << endl;
	cout << "=======================" << endl;
}

int main()
{
	Problem51p();
	Problem53p();
	Problem55p();
	Problem59_1();
	Problem59_2();
	Problem59_3();
	Problem59_4();
	Problem59_5();
	Problem59_6();
	Problem59_7();
	Problem59_8();

	return 0;
}