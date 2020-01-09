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

	// 땅에 닿은게 아니면 내려간다.
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
		// 미사일이 움직이는 거리는 모든 미사일이 다르다.
		distance = rand() % distance + 1;
		
		if (missles[i].rc.bottom < HEIGHT_GROUND)
		{
			missles[i].rc.top += distance;
			missles[i].rc.bottom += distance;
		}//end of if: 땅에 닿은게 아니면 내려간다.
		else
		{
			score++;
			// 땅에 닿은 미사일의 위치를 초기화 한다.
			initOneMissle(&missles[i]);
		}//end of else: 땅에 닿았다면
	}//end of for: 미사일 갯수만큼 반복문

	return score;
}
