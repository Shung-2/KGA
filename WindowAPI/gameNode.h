#pragma once
class gameNode
{
public:
	gameNode();
	virtual ~gameNode();

	//HRESULT ���� ���� ��ȯ�����ε�
	//S_OK, E_FAIL, SUCCEDED
	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� �Լ�
	virtual void render(HDC hdc);	//�׸��� �Լ�

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);
};

