#include "stdafx.h"
#include "boss.h"

HRESULT boss::init()
{
	enemy::init();
	return S_OK;
}

HRESULT boss::init(const char* imageName, POINT position)
{
	enemy::init(imageName, position);
	return S_OK;
}

void boss::relase()
{
	enemy::relase();
}

void boss::update()
{
	enemy::update();
	if (_y <= 100)
		_y += 1;
}

void boss::render()
{
	enemy::render();
}
