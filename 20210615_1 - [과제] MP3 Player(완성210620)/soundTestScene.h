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

	/* PlayMode 설정 */
	MODE _PlayMode;

	/* 앨범 커버 이미지 출력용 RECT, IMAGE */
	RECT _AlbumCover;
	image* _AlbumCoverImg;

	/* 노래 선택 할 수 있는 RECT 및 노래 리스트 생성 */
	RECT _Songrc[20];
	vector<PLAYLIST> _SongList;

	/* 선택한 뮤직의 INDEX 및 RECT */
	int _SelectMusicIdx;
	RECT _SelectRect;

	/* 노래 Play 여부 및 시작, 끝 시간*/
	bool _isPlay;
	int _MaxTime;
	int _StartTime;

	/* PlayBar와 네비게이션바(동그란거) */
	RECT _PlayBarBack;
	RECT _PlayBarFront;
	RECT _NavigationButton;

	/* 노래 재생 시 더블클릭 용 함수 */
	float _ClickTime;
	int _ClickIdx;

	/* 버튼 모음 */
	BUTTON _Before;
	BUTTON _Play;
	BUTTON _Pause;
	BUTTON _Next;
	BUTTON _Mode;
	
	/* _Mode 버튼 이미지 */
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

