#pragma once
#include "image.h"

class gameNode
{
private:
	image* _backBuffer; //�� DC������ �� bitmap����
	void setBackBuffer();

public:
	gameNode();
	virtual ~gameNode();

	//HRESULT ���� ���� ��ȯ�����ε�
	//S_OK, E_FAIL, SUCCEDED
	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� �Լ�
	virtual void render(HDC hdc);	//�׸��� �Լ�

	//����� ������!g
	image* getBackBuffer() { return _backBuffer; }
	
	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);
};

