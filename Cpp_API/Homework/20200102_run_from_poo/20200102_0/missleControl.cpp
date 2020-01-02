#include "stdafx.h"

void initOneMissle(missle * missle)
{
	POINT ptMissle;

	ptMissle.x = rand() % WINSIZEX;
	ptMissle.y = rand() % (WINSIZEY / 5);

	missle->rc = RectMake(ptMissle.x, ptMissle.y, SIZE_MISSLE, SIZE_MISSLE);
	missle->touch = false;
}

void moveOneMissle(RECT * missle)
{
	int distance = 15;
	distance = rand() % distance + 1;

	// ���� ������ �ƴϸ� ��������.
	if (missle->bottom < HEIGHT_GROUND)
	{
		missle->top += distance;
		missle->bottom += distance;
	}
}

int moveMissles(missle * missles)
{
	int distance = 3;
	int score = 0;

	for (int i = 0; i < MAX_MISSLE; i++)
	{
		// �̻����� �����̴� �Ÿ��� ��� �̻����� �ٸ���.
		distance = rand() % distance + 1;
		
		if (missles[i].rc.bottom < HEIGHT_GROUND)
		{
			missles[i].rc.top += distance;
			missles[i].rc.bottom += distance;
		}//end of if: ���� ������ �ƴϸ� ��������.
		else
		{
			score++;
			// ���� ���� �̻����� ��ġ�� �ʱ�ȭ �Ѵ�.
			initOneMissle(&missles[i]);
		}//end of else: ���� ��Ҵٸ�
	}//end of for: �̻��� ������ŭ �ݺ���

	return score;
}
