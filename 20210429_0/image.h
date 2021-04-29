#pragma once
class image
{
public:
	typedef struct tagImageInfo
	{
		HDC hMemDC;
		HBITMAP hBit;
		HBITMAP hOBit;
		int width;
		int height;

		tagImageInfo()
		{
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			width = 0;
			height = 0;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;
	// typedef 를 사용하면 두 개의 별칭(IMAGE_INFO, *LPIMAGE_INFO)을 사용할 수 있다.
private:
	LPIMAGE_INFO _backBuffer;

public:
	image();
	~image();

	HRESULT init(int width, int height);
	void release();
	void render(HDC hdc, int destX, int destY);

	//백버퍼에 대한 접근자
	inline HDC getMemDC() { return _backBuffer->hMemDC; }
};

