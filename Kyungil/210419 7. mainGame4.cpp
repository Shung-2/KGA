#include "210419 7. mainGame4.h"

mainGame4::mainGame4()
{
	_hp = 100;
	_mp = 30;
}

mainGame4::mainGame4(int hp, int mp) : _hp(hp), _mp(mp) // 멤버 이니셜라이즈
// 왜 사용하니? -> const 속성을 딱 한번 초기화 하기 윟서
{
	cout << _hp << endl;
	cout << _mp << endl;
}

mainGame4::~mainGame4()
{

}