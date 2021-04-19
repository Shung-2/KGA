#pragma once
class motherclass
{
private:
	// 어머니 비상금
	int _motherMoney;

protected:
	// 생활비
	int _familyMoney;

public:
	// 오다 주운 돈
	int _freeMoney;

	motherclass();	//생성자
	~motherclass();	//소멸자
};

