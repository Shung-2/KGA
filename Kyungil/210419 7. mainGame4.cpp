#include "210419 7. mainGame4.h"

mainGame4::mainGame4()
{
	_hp = 100;
	_mp = 30;
}

mainGame4::mainGame4(int hp, int mp) : _hp(hp), _mp(mp) // ��� �̴ϼȶ�����
// �� ����ϴ�? -> const �Ӽ��� �� �ѹ� �ʱ�ȭ �ϱ� ����
{
	cout << _hp << endl;
	cout << _mp << endl;
}

mainGame4::~mainGame4()
{

}