#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

void output()
{
	cout << "12분 뒤면 쉬는 시간" << endl << endl;
}

void gugudan(int num)
{
	for (int i = 1; i < 10; i++)
	{
		cout << num << " X " << i << " = " << num * i << endl;
	}
	cout << endl;
}

// 반환형이 int형인 attack 이름을 가진 함수
int attack(int hp, int atk)
{
	hp -= atk;

	cout << atk << "의 피해를 입어 " << hp << "의 체력이 남아 있습니다." << endl;

	return hp;
}

int heal(int hp, int healRate)
{
	hp += healRate;

	cout << "회복! " << healRate << "만큼 회복을 하여 " << hp << "가 되었습니다." << endl << endl;

	return hp;
}

// 함수 전방 선언
void output2();

// call-by-value 타입
void damaged(int hp, int atk)
{
	hp -= atk;
	cout << "남은 체력 : " << hp << endl;
}

// call-by-reference 타입
void damaged(int& hp, int atk)
{
	hp -= atk;
	cout << "남은 체력 : " << hp << endl;
}

// call-by-reference 타입을 이용한 예
struct tagUnit
{
	const char* name;
	int hp;
	int atk;
};

void damaged(const char* name, int* hp, const char* name2, int atk)
{
	*hp -= atk;
	cout << name << "은(는) " << name2 << "에게 " << atk << "만큼의 데미지를 입어 체력이 " << *hp << " 되었습니다." << endl;
}

int main()
{
	// 함수.

	// 함수의 원형은 아래와 같다.
	// 반환형 함수 이름 (매개 변수)
	// 예) void Test ()
	// 예) int gugudan (int num)

	// output 함수 실행
	output();

	// 구구단 함수 실행
	gugudan(8);
	gugudan(2);

	// 개와 오리의 싸움
	int dogHp = 100;
	int dogAtk = 10;

	int duckHp = 80;
	int duckAtk = 15;

	duckHp = attack(duckHp, dogAtk);
	dogHp = attack(dogHp, duckAtk);

	duckHp = attack(duckHp, dogAtk);
	dogHp = attack(dogHp, duckAtk);

	duckHp = attack(duckHp, dogAtk);
	dogHp = attack(dogHp, duckAtk);
	cout << endl;

	// 힐링포션
	int healthPotion = 20;
	duckHp = heal(duckHp, healthPotion);

	// 함수 전방선언
	// 일단 실행해봐~ 있으니까!
	output2();

	// call-by-value
	// 원본 값은 건드리지 않는다
	// 매개 변수를 함수 내부에서 복사해서 사용하는 과정을 거치기 떄문에 안전하지만 느리다.

	// call-by-reference
	// 매개변수가 함수 내부에서 복사되는 과정 없이 원본 값을 바꾸기 떄문에 위험하다.

	// call-by-value, reference의 예제
	int orcHp = 100;
	int orcHtk = 10;

	int gganfHp = 80;
	int gganfAtk = 8;
	
	// 오버로드로 인한 주석처리
	// damaged(orcHp, gganfAtk);

	// 포인터, == 가리키는 것
	int a = 3;
	int b = 7;
	int* c;

	cout << "b의 값은 : " << b << endl;
	c = &b;

	cout << "b의 값은 : " << b << endl;
	*c = 9;

	cout << "b의 값은 : " << b << endl << endl;

	// 포인터를 이용한 별찍기
	const char* star = "*****";

	for (int i = 0; i < 5; i++)
		cout << star + i << endl;
	cout << endl;

	for (int i = 0; i < 5; i++)
		cout << star + 4 - i << endl;
	cout << endl;

	// call-by-reference 타입을 이용한 예
	tagUnit human;
	human.name = "우서";
	human.hp = 100;
	human.atk = 10;

	tagUnit orc;
	orc.name = "쓰랄";
	orc.hp = 150;
	orc.atk = 10;

	damaged(orc.name, &orc.hp, human.name, human.atk);
	damaged(human.name, &human.hp, orc.name, orc.atk);

	damaged(orc.name, &orc.hp, human.name, human.atk);
	damaged(human.name, &human.hp, orc.name, orc.atk);

	damaged(orc.name, &orc.hp, human.name, human.atk);
	damaged(human.name, &human.hp, orc.name, orc.atk);
}

void output2()
{
	cout << "전방 선언~!! 선언 멈춰!" << endl << endl;
}