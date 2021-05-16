#pragma once
#include "gameNode.h"

#define PI 3.14156f
#define BULLETMAX 30
#define PREVIEWMAX 300

struct tagBullet
{
	float x, y;		//중점 좌표
	float speed;	//총알 속도
	float angle;	//총알 각도
	float radius;	//총알 붼지름
	bool isFire;	//발사했누?
	float gravity;
};

struct tagCannon
{
	POINT center;		//대포 중점
	POINT cannonEnd;	//대포 끝점
	int radius;			//대포 붼지름
	int cannon;			//포신(?)
	float angle;		//대포 각도
};

struct tagPreview
{
	float x, y;
	float radius;
	float gravity;
};

class playGround : public gameNode
{
private:
	tagCannon _cannon;
	tagBullet _bullet[BULLETMAX];
	tagPreview _preview[PREVIEWMAX];

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	
	void bulletFire();
	void bulletMove();

	void bulletPreview();
};

