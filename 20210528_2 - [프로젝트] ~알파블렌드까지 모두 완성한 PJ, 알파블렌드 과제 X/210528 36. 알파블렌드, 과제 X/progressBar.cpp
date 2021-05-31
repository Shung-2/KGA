#include "stdafx.h"
#include "progressBar.h"

HRESULT progressBar::init(const char* barName, int x, int y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);
	// �������� ���α׷�����
	//_progressBarTop = IMAGEMANAGER->addImage("frontBar", "hpBarTop.bmp", width, height, true, RGB(255, 0, 255));
	//_progressBarBottom = IMAGEMANAGER->addImage("backBar", "hpBarBottom.bmp", width, height, true, RGB(255, 0, 255));

	// ## 210528 Unique progreessBar ##
	sprintf_s(_frontBarName, "%sFrontBar", barName);
	sprintf_s(_backBarName, "%sBackBar", barName);
	_progressBarTop = IMAGEMANAGER->addImage(_frontBarName, "hpBarTop.bmp", width, height, true, RGB(255, 0, 255));
	_progressBarBottom = IMAGEMANAGER->addImage(_backBarName, "hpBarBottom.bmp", width, height, true, RGB(255, 0, 255));

	// �������� ����ũ��� ��ø�� ������ �̹��� �߿��� �տ� ������ ������ ����ũ���!
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
	/* �������� ���α׷����� */
	//IMAGEMANAGER->render("backBar", getMemDC(),
	//	_rcProgress.left + _progressBarBottom->getWidth() / 2,
	//	_y + _progressBarBottom->getHeight() / 2, 0, 0,
	//	_progressBarBottom->getWidth(), _progressBarBottom->getHeight());
	//
	//// ��� ������ ũ�Ⱑ �����Ǿ���ϱ� ������ ����ũ��(sourWidth)�� _width ������ ���ش�.
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
	// �ۼ��������� ������ָ� ���� ���� ����.
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();
}
