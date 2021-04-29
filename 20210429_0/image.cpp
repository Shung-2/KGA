#include "stdafx.h"
#include "image.h"


image::image()
	: _backBuffer(NULL)
{
}


image::~image()
{
}

HRESULT image::init(int width, int height)
{
	if (_backBuffer != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_backBuffer = new IMAGE_INFO;
	_backBuffer->hMemDC = CreateCompatibleDC(hdc); //�� DC���� ��������
	_backBuffer->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_backBuffer->hOBit = (HBITMAP)SelectObject(_backBuffer->hMemDC, _backBuffer->hBit);
	_backBuffer->width = width;
	_backBuffer->height = height;

	//���� �ʱ�ȭ�� ������ߴµ� �� �ȵƴٸ�?
	if (_backBuffer == nullptr)
	{
		release();

		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

void image::release()
{
	if (_backBuffer)
	{
		SelectObject(_backBuffer->hMemDC, _backBuffer->hOBit);
		DeleteObject(_backBuffer->hBit);
		DeleteDC(_backBuffer->hMemDC);

		SAFE_DELETE(_backBuffer);
	}


}

void image::render(HDC hdc, int destX, int destY)
{
	//GdiTranparentBlt() -> ���ۿ��� ����Ÿ ���� �����ϰ� ���ִ� ��Ȱ�� �ϴ� �Լ�
	//StrachBlt() -> �̸������� �� �� �ֵ��� ��Ʈ��Ī, �̹����� ũ�⸦ �����ϴ� ���̶�� �� �� �ִ�.
	//

	//DC�������� ��Ӻ���
	BitBlt(
		hdc,					//������ DC	
		destX,					//������ ��ǥ(left)
		destY,					//������ ��ǥ(top)
		_backBuffer->width,		//������ ����ũ��
		_backBuffer->height,	//������ ����ũ��
		_backBuffer->hMemDC,	//����� DC
		0, 0,					//����� ������ǥ(left, top)
		SRCCOPY);				//�����Ҷ� ��������Ű�������~
	
}
