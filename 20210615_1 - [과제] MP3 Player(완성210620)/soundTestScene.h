#pragma once
#include "gameNode.h"

#include <commdlg.h>
#define	RECT_WIDTH 200
#define RECT_HEIGHT 30

class soundTestScene : public gameNode
{
private :
	typedef enum PLAYMODE
	{
		ALL,
		ONE,
		SHUFFLE
	} MODE;

	typedef struct tagButton
	{
		RECT rc;
		image* img;
	} BUTTON;

	typedef struct tagPlaylist
	{
		RECT _Song;
		string filename;
	} PLAYLIST;

	/* PlayMode ���� */
	MODE _PlayMode;

	/* �ٹ� Ŀ�� �̹��� ��¿� RECT, IMAGE */
	RECT _AlbumCover;
	image* _AlbumCoverImg;

	/* �뷡 ���� �� �� �ִ� RECT �� �뷡 ����Ʈ ���� */
	RECT _Songrc[20];
	vector<PLAYLIST> _SongList;

	/* ������ ������ INDEX �� RECT */
	int _SelectMusicIdx;
	RECT _SelectRect;

	/* �뷡 Play ���� �� ����, �� �ð�*/
	bool _isPlay;
	int _MaxTime;
	int _StartTime;

	/* PlayBar�� �׺���̼ǹ�(���׶���) */
	RECT _PlayBarBack;
	RECT _PlayBarFront;
	RECT _NavigationButton;

	/* �뷡 ��� �� ����Ŭ�� �� �Լ� */
	float _ClickTime;
	int _ClickIdx;

	/* ��ư ���� */
	BUTTON _Before;
	BUTTON _Play;
	BUTTON _Pause;
	BUTTON _Next;
	BUTTON _Mode;
	
	/* _Mode ��ư �̹��� */
	image* _ModeImg[3];

	bool _ImgCheck[20];

public:

	soundTestScene();
	~soundTestScene();

	HRESULT init();
	void release();
	void update();
	void render();

	/* Init */
	void _AddImage();
	void _AddSound();
	void _ButtonInit();

	/* Update */
	void _MouseHandle();
};

