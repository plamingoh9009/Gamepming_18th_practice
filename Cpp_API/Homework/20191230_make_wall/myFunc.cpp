#include "myFunc.h"
#include "stdafx.h"

bool isCrushWall(RECT me, RECT wall)
{
	// 언제 충돌상황인지 정의한다.
	// 네모의 오른쪽이 벽의 왼쪽과 닿으면서 
	if ((wall.left <= me.left && me.left <= wall.right) ||
		(wall.left <= me.right && me.right <= wall.right))
	{
		if ((wall.top <= me.top && me.top <= wall.bottom) ||
			(wall.top <= me.bottom && me.bottom <= wall.bottom))
		{
			return true;
		}//end of if: 네모의 위쪽, 아래쪽이 벽의 위~아래 범위 일때
	}//end of if: 네모의 오른쪽이 벽의 왼쪽을 넘어간다면

	

	return false;
}