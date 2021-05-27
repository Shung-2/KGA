#include "stdafx.h"
#include "playGround.h"

// 헤더 파일은 여러개의 cpp 파일을 거느릴 수 있다.
// 보통 게임 회사에서 코드 양이 상당하기 때문에
// 현재 프로그래밍처럼 메인으로 할당되는 곳에서 어떠헌 처리를 할 경우
// 코드 줄 수가 많아져서 보기 어렵게 되므로
// 헤더에 함수를 선언한 뒤 함수별로 cpp를 별도로 제작해서 가독성을 높이는 경우도 있다.

void playGround::collision()
{
	for (int i = 0; i < _ship->getHyunMoo()->getVHyunMoo().size(); i++)
	{
		for (int j = 0; j < _em->getVMinion().size(); j++)
		{
			RECT temp;
			RECT rc = _em->getVMinion()[j]->getRect();
			if (IntersectRect(&temp, &_ship->getHyunMoo()->getVHyunMoo()[i].rc, &rc))
			{
				_ship->getHyunMoo()->removeMissile(i);
				_em->removeMinion(j);
					break;
			}
		}
	}
}