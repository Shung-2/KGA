#include "stdafx.h"
#include "bullets.h"

HRESULT bullet::init(const char* imageName, int bulletMax, float range)
{
	_imageName = imageName;
	_bulletMax = bulletMax;
	_range = range;

	return S_OK;
}

void bullet::release()
{
}

void bullet::update()
{
	move();
}

void bullet::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->render(getMemDC(), _viBullet->rc.left, _viBullet->rc.top);
	}
}

void bullet::fire(float x, float y, float angle, float speed)
{
	if (_bulletMax < _vBullet.size()) return;

	// ?̱????̱⿡ SAFE_RELEASE, SAFE_DELETE?? ???????? ?ʴ´?.
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
	bullet.speed = speed;
	bullet.radius = bullet.bulletImage->getWidth() / 2;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.angle = angle;

	bullet.rc = RectMakeCenter(bullet.x, bullet.y, 
		bullet.bulletImage->getWidth(),	bullet.bulletImage->getHeight());

	_vBullet.push_back(bullet);
}

void bullet::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->x += cosf(_viBullet->angle) * _viBullet->speed;
		_viBullet->y += -sinf(_viBullet->angle) * _viBullet->speed;

		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());

		if (_range < getDistance(_viBullet->x, _viBullet->y, _viBullet->fireX, _viBullet->fireY))
		{
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void bullet::removeBullet(int arrNum)
{
	// ?????? ???? ???ﶩ erase();
	_vBullet.erase(_vBullet.begin() + arrNum);
}


HRESULT missile::init(int bulletMax, float range)
{
	_range = range;

	for (int i = 0; i < bulletMax; i++)
	{
		tagBullet bullet;
		ZeroMemory(&bullet, sizeof(bullet));
		bullet.bulletImage = new image;
		bullet.bulletImage->init("missile1.bmp", 26, 124, true, RGB(255, 0, 255));
		bullet.speed = 5.0f;
		bullet.isFire = false;

		// ???Ϳ? Ǫ?????ش?.
		_vBullet.push_back(bullet);
	}

	return S_OK;
}

void missile::release()
{
}

void missile::update()
{
	move();
}

void missile::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->isFire) continue;

		_viBullet->bulletImage->render(getMemDC(),
			_viBullet->rc.left,
			_viBullet->rc.top, 0, 0,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());
	}
}

void missile::fire(float x, float y)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (_viBullet->isFire) continue;

		_viBullet->isFire = true;
		_viBullet->x = _viBullet->fireX = x;
		_viBullet->y = _viBullet->fireY = y;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());
		
		break;
	}
}

void missile::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->isFire) continue;

		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());

		if (_range < getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y))
		{
			_viBullet->isFire = false;
		}
	}
}

//============================
// ## ?߻??Ҷ? ?????Ѵ? ##
//============================

HRESULT hyunMoo::init(int bulletMax, float range)
{
	_bulletMax = bulletMax;
	_range = range;

	return S_OK;
}

void hyunMoo::release()
{
}

void hyunMoo::update()
{
	move();
}

void hyunMoo::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->frameRender(getMemDC(),
			_viBullet->rc.left,
			_viBullet->rc.top,
			_viBullet->bulletImage->getFrameX(), 0);

		_viBullet->count++;

		if (_viBullet->count % 5 == 0)
		{
			_viBullet->bulletImage->setFrameX(_viBullet->bulletImage->getFrameX() + 1);

			//?ִ? ?????Ӻ??? Ŀ????
			if (_viBullet->bulletImage->getFrameX() >= _viBullet->bulletImage->getMaxFrameX())
			{
				_viBullet->bulletImage->setFrameX(0);
			}

			_viBullet->count = 0;
		}
	}
}

void hyunMoo::fire(float x, float y)
{
	//?ִ밹?????? ?? ?????Ƿ??? ?ϸ? ?????ʴ´?
	if (_bulletMax < _vBullet.size()) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = new image;
	bullet.bulletImage->init("missile.bmp", 0, 0, 416, 64, 13, 1,
		true, RGB(255, 0, 255));
	bullet.speed = 6.0f;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
		bullet.bulletImage->getFrameWidth(),
		bullet.bulletImage->getFrameHeight());

	_vBullet.push_back(bullet);
}

void hyunMoo::move()
{
	// ?? ???????? ???????? ???????
	// ó?? ?Ѿ??? ?????????? ???????°? ?ƴ? ?߰? ?Ѿ??? ?????? ???? ???? ???????ϱ? ??????
	// erase?? ?????ϰ? ?? ?????? ???? ?????? ?????ϰ? ???? for???? ???ƾ??ϴµ?
	// ?װ? ?ƴ϶? erase?? ?????? ??????ä for???? ???? ???? ?????? ?????? ?ȴ?.

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(),
			_viBullet->bulletImage->getFrameHeight());

		//???Ÿ????? ?? ?ָ? ??????(?)
		if (_range < getDistance(_viBullet->x, _viBullet->y, _viBullet->fireX, _viBullet->fireY))
		{
			// ??????, ????Ʈ?? ?޸??? ?????̹Ƿ? ?ſ? ?߿??ϴ?~
			SAFE_RELEASE(_viBullet->bulletImage);
			SAFE_DELETE(_viBullet->bulletImage);
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

// ???? ??ü?? ?? ??° ?̻????? ?????޶??? ??û?? ?Լ?
void hyunMoo::removeMissile(int arrNum)
{
	// ?????Ҵ? ?Ǿ? ?????Ǵ? ?̹????? ?????ش?.
	_vBullet[arrNum].bulletImage->release();
	_vBullet.erase(_vBullet.begin() + arrNum);
}
