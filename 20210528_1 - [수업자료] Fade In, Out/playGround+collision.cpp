#include "stdafx.h"
#include "playGround.h"

//헤더파일은 여러개의 cpp파일을 거느릴수 있다.
//보통 게임회사에서 코드양이 상당하기 때문에
//현재 플그처럼 메인으로 할당되는 곳에서 어떠한 처리를 할 경우
//코드 줄수가 많아져서 보기어렵게 되므로
//헤더에 함수를 선언한뒤 함수별로  cpp를 별도로 제작해서 가독성을 높이는 경우도 있다

void playGround::collision()
{
	for (int i = 0; i < _ship->getHyunMoo()->getVHyunMoo().size(); i++)
	{
		for (int j = 0; j < _em->getVMinion().size(); j++)
		{
			RECT temp;
			RECT rc = _em->getVMinion()[j]->getRect();
			if (IntersectRect(&temp, &_ship->getHyunMoo()->getVHyunMoo()[i].rc,
				&rc))
			{
				_ship->getHyunMoo()->removeMissile(i);
				_em->removeMinion(j);
				break;
			}

		}
	}

}
