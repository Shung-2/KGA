#include <iostream>
#include <time.h>
#include <math.h>
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
	cout << "ĵ�� ���� �� ���� �� = " << Result << endl << endl;
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
	cout << "ȭ���µ� : " << f_temp << "�� �����µ� : " << c_temp << "�Դϴ�." << endl << endl;
}

void Problem55p()
{
	srand(time(NULL));
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	cout << "�� �ֻ����� �� = " << dice1 + dice2 << endl << endl;
}

void Problem59_1()
{
	string str1, str2, str3;
	cout << "�־� : ";
	cin >> str1;
	cout << "���� : ";
	cin >> str2;
	cout << "������ : ";
	cin >> str3;

	cout << str1 << ' ' << str2 << ' ' << 'a' << ' ' << str3 << endl << endl;
}

void Problem59_2()
{
	int age;
	cout << "���� : ";
	cin >> age;

	cout << "10�� �Ŀ��� " << age + 10 << "���� �˴ϴ�." << endl << endl;
}

void Problem59_3()
{
	int SideX, SideY, Hypotenuse;

	cout << "ù ��° �� : ";
	cin >> SideX;
	cout << "�� ��° �� : ";
	cin >> SideY;

	Hypotenuse = sqrt(SideX * SideX + SideY * SideY);
	cout << "���� ���� : " << Hypotenuse << endl << endl;
}

void Problem59_4()
{
	int l, w, h, Volume, surface_area;

	cout << "���� : ";
	cin >> l;
	cout << "�ʺ� : ";
	cin >> w;
	cout << "���� : ";
	cin >> h;

	Volume = l * w * h;
	surface_area = 2 * ((l * w) + (l * h) + (h * w));

	cout << "������ ���� : " << Volume << endl;
	cout << "������ ǥ�頬 : " << surface_area << endl << endl;
}

void Problem59_5()
{
	double PYEONG = 3.3058;
	int value;

	cout << "�� : ";
	cin >> value;
	cout << "������ : " << PYEONG * value << endl << endl;
}

void Problem59_6()
{
	int Hour, Minute, Second, Result;

	cout << "�� : ";
	cin >> Hour;
	cout << "�� : ";
	cin >> Minute;
	cout << "�� : ";
	cin >> Second;

	Result = Hour * 3600 + Minute * 60 + Second;
	cout << "��ü �� : " << Result << endl << endl;
}

void Problem59_7()
{
	const double pi = 3.141592;
	double radius, surface_area, volume;

	cout << "������ : ";
	cin >> radius;

	surface_area = 4 * pi * pow(radius, 2);
	volume = 4 / 3 * pi * pow(radius, 3);

	cout << "ǥ���� : " << surface_area << endl;
	cout << "���� : " << volume << endl << endl;
}

void Problem59_8()
{
	int quiz1, quiz2, quiz3, mid, final, result;
	cout << "����	#1 ���� : ";
	cin >> quiz1;
	cout << "����	#2 ���� : ";
	cin >> quiz2;
	cout << "����	#3 ���� : ";
	cin >> quiz3;
	cout << "�߰��� ���� : ";
	cin >> mid;
	cout << "�⸻��� ���� : ";
	cin >> final;

	result = quiz1 + quiz2 + quiz3 + mid + final;
	cout << "=======================" << endl;
	cout << "���� �� �� : " << result << endl;
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