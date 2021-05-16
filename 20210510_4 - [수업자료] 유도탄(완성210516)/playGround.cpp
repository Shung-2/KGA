#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}

playGround::~playGround()
{
}

//�ʱ�ȭ�� ����� �ϼ��� ����
HRESULT playGround::init()
{
	gameNode::init();

	_enemy.x = RND->getFromFloatTo(50, WINSIZEX - 50);	// enemy�� X�� ���� (����)
	_enemy.y = RND->getFromFloatTo(50, WINSIZEY - 50);	// enemy�� Y�� ���� (����)
	_enemy.radius = 30;									// enemy�� ������ ����
	_enemy.angle = 0;									// enemy�� ���� ���� 
	_enemy.speed = 3;									// enemy�� �ӵ� ����

	return S_OK;
}

//�޸� ������ ����� �ϼ��� ����
void playGround::release()
{
	gameNode::release();
}

//���⿡�� �����ϼ��� ������
void playGround::update()
{
	// _ptMouseX, Y�� �̿��Ͽ� �÷��̾��� X, Y�� ����
	_player.x = _ptMouse.x;
	_player.y = _ptMouse.y;

	// ���� �÷��̾ �i�� ���� ��Ȳ
	// enemy�� ������ getAngle�� �̿��Ͽ� ����
	//_enemy.angle = getAngle(_enemy.x, _enemy.y, _player.x, _player.y);

	// �÷��̾ ���� �i�� ���� ��Ȳ
	// enemy�� ������ getAngle�� �̿��Ͽ� ���� (���� �� ����)
	_enemy.angle = getAngle(_player.x, _player.y, _enemy.x, _enemy.y);

	// enemy�� X, Y�� ����
	_enemy.x += cosf(_enemy.angle) * _enemy.speed;
	_enemy.y += -sinf(_enemy.angle) * _enemy.speed;

	gameNode::update();
}

//���⿡�� �׷��� ��! ��!
void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================

	EllipseMakeCenter(backDC, _player.x, _player.y, 100, 100);
	EllipseMakeCenter(backDC, _enemy.x, _enemy.y, 100, 100);

	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(hdc, 0, 0);
}