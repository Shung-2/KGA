#pragma once
#include "gameNode.h"

class playGround : public gameNode
{
private:
	
	// 초기화
	RECT _user_Ellipse;				// 사용자 원
	float _user_radius;				// 사용자 원 반지름

	RECT _center_Ellipse;			// 가운데 원
	float _center_Ellipse_x;		// 가운데 원 X축 중점 좌표
	float _center_Ellipse_y;		// 가운데 원 Y축 중점 좌표
	float _center_Ellipse_radius;	// 가운데 원 반지름

	float _distance_x;				// 가운데 원 중점 X 좌표 - 사용자 원 중점 X 좌표 값
	float _distance_y;				// 가운데 원 중점 Y 좌표 - 사용자 원 중점 Y 좌표 값
	float _hypo;					// 빗변

	bool _iscrash;					// 충돌여부

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};