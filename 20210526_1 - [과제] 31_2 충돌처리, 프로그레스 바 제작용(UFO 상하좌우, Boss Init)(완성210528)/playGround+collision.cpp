#include "stdafx.h"
#include "playGround.h"

// ��� ������ �������� cpp ������ �Ŵ��� �� �ִ�.
// ���� ���� ȸ�翡�� �ڵ� ���� ����ϱ� ������
// ���� ���α׷���ó�� �������� �Ҵ�Ǵ� ������ ��� ó���� �� ���
// �ڵ� �� ���� �������� ���� ��ư� �ǹǷ�
// ����� �Լ��� ������ �� �Լ����� cpp�� ������ �����ؼ� �������� ���̴� ��쵵 �ִ�.

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