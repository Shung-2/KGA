#pragma once
class image
{
public:
	//이미지를 불러올수 있는 종류
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE,		//리소스 파일로부터
		LOAD_FILE,			//이미지 파일로부터
		LOAD_EMPTY,			//빈 비트맵 이미지를 만들어야겠다
		LOAD_END
	};

	typedef struct tagImageInfo
	{
		DWORD resID;	//리소스를 통해서 이미지 처리할땐 얘를 쓴다
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
	CHAR*			_fileName;		//파일 이름
	BOOL			_trans;			//특정 픽셀값을 제거할지 유무
	COLORREF		_transColor;	//제거할 픽셀값

public:
	image();
	~image();

	HRESULT init(int width, int height);
	HRESULT init(const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);
	void release();
	void render(HDC hdc, int destX, int destY);
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//혹시나 런타임 도중에 제거할 픽셀값을 바꿔야한다면
	void setTransColor(BOOL trans, COLORREF transColor);

	//백버퍼에 대한 접근자
	inline HDC getMemDC() { return _imageInfo->hMemDC; }
};

