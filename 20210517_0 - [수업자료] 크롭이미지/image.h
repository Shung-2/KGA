#pragma once
class image
{
public:
	//�̹����� �ҷ��ü� �ִ� ����
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE,		//���ҽ� ���Ϸκ���
		LOAD_FILE,			//�̹��� ���Ϸκ���
		LOAD_EMPTY,			//�� ��Ʈ�� �̹����� �����߰ڴ�
		LOAD_END
	};

	typedef struct tagImageInfo
	{
		DWORD resID;	//���ҽ��� ���ؼ� �̹��� ó���Ҷ� �긦 ����
		HDC hMemDC;
		HBITMAP hBit;
		HBITMAP hOBit;
		int width;
		int height;
		BYTE loadType;

		tagImageInfo()
		{
			resID = 0;
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			width = 0;
			height = 0;
			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;
private:
	LPIMAGE_INFO	_imageInfo;
	CHAR*			_fileName;		//���� �̸�
	BOOL			_trans;			//Ư�� �ȼ����� �������� ����
	COLORREF		_transColor;	//������ �ȼ���

public:
	image();
	~image();

	HRESULT init(int width, int height);
	HRESULT init(const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);
	void release();
	void render(HDC hdc, int destX, int destY);
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//Ȥ�ó� ��Ÿ�� ���߿� ������ �ȼ����� �ٲ���Ѵٸ�
	void setTransColor(BOOL trans, COLORREF transColor);

	//����ۿ� ���� ������
	inline HDC getMemDC() { return _imageInfo->hMemDC; }
};

