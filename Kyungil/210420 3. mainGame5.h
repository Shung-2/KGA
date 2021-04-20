#pragma once
#include <iostream>
using namespace std;

class mainGame5
{
public:
	mainGame5();
	~mainGame5();

	template<typename T>
	void output(T t);
};

template<typename T>
inline void mainGame5::output(T t)
{
	cout << t << endl;
}
