#include "stdafx.h"
#include "progressBar.h"

HRESULT progressBar::init(const char* barName, int x, int y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);
	// 수업내용 프로그레스바
	//_progressBarTop = IMAGEMANAGER->addImage("frontBar", "hpBarTop.bmp", width, height, true, RGB(255, 0, 255));
	//_progressBarBottom = IMAGEMANAGER->addImage("backBar", "hpBarBottom.bmp", width, height, true, RGB(255, 0, 255));

	// ## 210528 Unique progreessBar ##
	sprintf_s(_frontBarName, "%sFrontBar", barName);
	sprintf_s(_backBarName, "%sBackBar", barName);
	_progressBarTop = IMAGEMANAGER->addImage(_frontBarName, "hpBarTop.bmp", width, height, true, RGB(255, 0, 255));
	_progressBarBottom = IMAGEMANAGER->addImage(_backBarName, "hpBarBottom.bmp", width, height, true, RGB(255, 0, 255));

	// 게이지의 가로크기는 중첩된 게이지 이미지 중에서 앞에 실제로 조정될 가로크기로!
	_width = _progressBarTop->getWidth();

	return S_OK;
}

void progressBar::release()
{
}

void progressBar::update()
{
	_rcProgress = RectMakeCenter(_x, _y, _progressBarTop->getWidth(),
		_progressBarBottom->getHeight());
}

void progressBar::render()
{
	/* 수업내용 프로그레스바 */
	//IMAGEMANAGER->render("backBar", getMemDC(),
	//	_rcProgress.left + _progressBarBottom->getWidth() / 2,
	//	_y + _progressBarBottom->getHeight() / 2, 0, 0,
	//	_progressBarBottom->getWidth(), _progressBarBottom->getHeight());
	//
	//// 얘는 게이지 크기가 조절되어야하기 때문에 가로크기(sourWidth)에 _width 변수를 써준다.
	//IMAGEMANAGER->render("frontBar", getMemDC(),
	//	_rcProgress.left + _progressBarBottom->getWidth() / 2,
	//	_y + _progressBarBottom->getHeight() / 2, 0, 0,
	//	_width, _progressBarBottom->getHeight());

	// ## 210528 Unique progreessBar ##
	IMAGEMANAGER->render(_backBarName, getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2, 0, 0,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	IMAGEMANAGER->render(_frontBarName, getMemDC(),
		_rcProgress.left + _progressBarBottom->getWidth() / 2,
		_y + _progressBarBottom->getHeight() / 2, 0, 0,
		_width, _progressBarBottom->getHeight());
}

void progressBar::setGauge(float currentGauge, float maxGauge)
{
	// 퍼센테이지로 계산해주면 더욱 쉽고 좋다.
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();
}
