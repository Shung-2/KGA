#pragma once
#include "gameNode.h"
#define PI 3.14156f
#define BULLETMAX 30

struct tagObj
{
	POINT center;	// 대포 중점 좌표 초기화
	POINT endPoint;	// 대포 끝점 좌표 초기화
	int radius;		// 대포 반지름 초기화
	int length;		// 대포 길이 초기화
	float angle;	// 대포 각도 초기화
};

struct tagBullet
{
	float x, y;		// 총알 중점 좌표 초기회
	float speed;	// 총알 속도 초기화
	float angle;	// 총알 각도 초기화
	float radius;	// 총알 반지름 초기화
	bool isFire;	// 총알 발사 여부 초기화
};					   

class playGround : public gameNode
{
private:
	tagObj _obj;					// 대포를 객체로(obj)라는 별명으로 설정
	tagBullet _bullet[BULLETMAX];	// 미사일을 bullet라는 별명으로 설정
	
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void bulletFire();
	void bulletMove();
};