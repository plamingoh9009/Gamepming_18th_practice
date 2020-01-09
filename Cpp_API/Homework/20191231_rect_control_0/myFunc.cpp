#include "stdafx.h"
#include "myFunc.h"

WPARAM isInRectEdge(RECT me, POINT pt)
{
	// 가운데보다 1/3 지점 우하단을 잡았을 경우
	LONG width = me.right - me.left;
	LONG height = me.bottom - me.top;

	LONG leftEdge = me.left + (width / 5);
	LONG rightEdge = me.right - (width / 5);
	LONG topEdge = me.top + (width / 5);
	LONG bottomEdge = me.bottom - (width / 5);

	if (isInRange(pt.x, me.left, leftEdge) == true)
	{
		return VK_LEFT;
	}//end of if: pt.x 가 사각형 왼쪽 가장자리에 있을 때
	else if (isInRange(pt.x, rightEdge, me.right) == true)
	{
		return VK_RIGHT;
	}//end of if: pt.x 가 사각형 오른쪽 가장자리에 있을 때
	else if (isInRange(pt.y, me.top, topEdge) == true)
	{
		return VK_UP;
	}//end of if: pt.y 가 사각형 위쪽 가장자리에 있을 때
	else if (isInRange(pt.y, bottomEdge, me.bottom) == true)
	{
		return VK_DOWN;
	}//end of if: pt.y 가 사각형 아래쪽 가장자리에 있을 때

	return NULL;
}

RECT controlRectSize(RECT me, POINT pt, WPARAM lo)
{
	if (lo == VK_LEFT)
	{
		me.left = pt.x;
	}//end of if: 왼쪽 엣지를 건드렸을 때
	else if (lo == VK_RIGHT)
	{
		me.right = pt.x;
	}
	else if (lo == VK_UP)
	{
		me.top = pt.y;
	}//end of if: 위쪽 엣지를 건드렸을 때
	else if (lo == VK_DOWN)
	{
		me.bottom = pt.y;
	}

	// 여기서 큰쪽, 작은쪽을 스왑한다.
	if (me.left > me.right)
	{
		std::swap(me.left, me.right);
	}
	if (me.top > me.bottom)
	{
		std::swap(me.top, me.bottom);
	}

	return me;
}

RECT setRectCenter(RECT me)
{
	RECT result = RectMakeCenter(
		(me.right + me.left) / 2,
		(me.bottom + me.top) / 2,
		((me.right - me.left) / 3) * 2,
		((me.bottom - me.top) / 3) * 2);
	return result;
}

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
		}//end of if: 네모의 위쪽, 아래쪽이 벽의 위~아래 범위에 닿을 때
	}//end of if: 네모의 왼쪽, 오른쪽이 벽의 왼쪽~오른쪽 범위에 닿거나

	return false;
}

bool isInWindow(RECT me, RECT window)
{
	if ((window.left <= me.left && me.left <= window.right) &&
		(window.left <= me.right && me.right <= window.right))
	{
		if ((window.top <= me.top && me.top <= window.bottom) &&
			(window.top <= me.bottom && me.bottom <= window.bottom))
		{
			return true;
		}//end of if: 네모의 위쪽, 아래쪽이 벽의 위쪽~아래쪽 범위 안에 있을 때
	}//end of if: 네모의 왼쪽, 오른쪽이 벽의 왼쪽~오른쪽 범위 안에 있고
	return false;
}

bool isInWindow(POINT pt, RECT window)
{
	if (window.left <= pt.x && pt.x <= window.right)
	{
		if (window.top <= pt.y && pt.y <= window.bottom)
		{
			return true;
		}//end of if: 포인트가 윈도우의 위쪽~아래쪽 범위 안에 있을 때
	}//end of if: 포인트가 윈도우의 왼쪽~오른쪽 범위 안에 있을 때
	return false;
}

bool isInRange(LONG target, LONG start, LONG end)
{
	if (start < target && target < end)
	{
		return true;
	}
	return false;
}

void swapRect(RECT* me, RECT* other)
{
	LONG temp;
	// 왼쪽 스왑
	temp = me->left;
	me->left = other->left;
	other->left = temp;

	// 오른쪽 스왑
	temp = me->right;
	me->right = other->right;
	other->right = temp;

	// 탑 스왑
	temp = me->top;
	me->top = other->top;
	other->top = temp;

	// 바텀 스왑
	temp = me->bottom;
	me->bottom = other->bottom;
	other->bottom = temp;
}

void moveRect(RECT * me, WPARAM wParam, int distance)
{
	switch (wParam)
	{
	case VK_LEFT:
		me->left -= distance;
		me->right -= distance;
		break;
	case VK_RIGHT:
		me->left += distance;
		me->right += distance;
		break;
	case VK_UP:
		me->top -= distance;
		me->bottom -= distance;
		break;
	case VK_DOWN:
		me->top += distance;
		me->bottom += distance;
		break;
	}
}

void moveRect(RECT * me, POINT pt)
{
	RECT temp;
	LONG width = me->right - me->left;
	LONG height = me->bottom - me->top;
	temp = RectMakeCenter(pt.x, pt.y, width, height);

	me->left = temp.left;
	me->right = temp.right;
	me->top = temp.top;
	me->bottom = temp.bottom;
}

RECT makeLittleRect(const RECT me)
{
	return RectMakeCenter(
		(me.right + me.left) / 2,
		(me.bottom + me.top) / 2,
		(me.right - me.left) / 5,
		(me.bottom - me.top) / 5);
}

void runCrush(RECT me, RECT * other)
{
	if (isCrushWall(me, *other) == true)
	{
		// 4가지 방향을 정의한다.

		if (me.right <= other->left || me.right <= other->right)
		{
			if (isInRange(me.top, other->top, other->bottom) ||
				isInRange(me.bottom, other->top, other->bottom))
			{
				moveRect(other, VK_RIGHT, 5);
			}//end of if: 내 네모가 other의 top ~ bottom 범위에 존재할때
		}//end of if: 내 네모가 왼쪽에서 충돌했을 시

		if (me.left >= other->right || me.left >= other->left)
		{
			if (isInRange(me.top, other->top, other->bottom) ||
				isInRange(me.bottom, other->top, other->bottom))
			{
				moveRect(other, VK_LEFT, 5);
			}//end of if: 내 네모가 other의 top ~ bottom 범위에 존재할때
		}//end of if: 내 네모가 오른쪽에서 충돌했을 시

		if (me.bottom <= other->top || me.bottom <= other->bottom)
		{
			if (isInRange(me.left, other->left, other->right) ||
				isInRange(me.right, other->left, other->right))
			{
				moveRect(other, VK_DOWN, 5);
			}//end of if: 내 네모가 other의 left ~ right 범위에 존재할때
		}//end of if: 내 네모가 위에서 충돌했을 시

		if (me.top >= other->bottom || me.top >= other->top)
		{
			if (isInRange(me.left, other->left, other->right) ||
				isInRange(me.right, other->left, other->right))
			{
				moveRect(other, VK_UP, 5);
			}//end of if: 내 네모가 other의 left ~ right 범위에 존재할때
		}//end of if: 내 네모가 아래서 충돌했을 시
	}//end of if: 네모가 충돌했다면
}

void moveBackInWindow(RECT * me, RECT window)
{
	// 윈도우 안쪽으로 되돌리는 함수

	if (me->left <= window.left)
	{
		moveRect(me, VK_RIGHT, 20);
	}//end of if: 내 네모가 윈도우 왼쪽 밖으로 나갔다면
	if (me->right >= window.right)
	{
		moveRect(me, VK_LEFT, 20);
	}//end of if: 내 네모가 윈도우 오른쪽 밖으로 나갔다면
	if (me->top <= window.top)
	{
		moveRect(me, VK_DOWN, 20);
	}//end of if: 내 네모가 윈도우 위쪽 밖으로 나갔다면
	if (me->bottom >= window.bottom)
	{
		moveRect(me, VK_UP, 20);
	}//end of if: 내 네모가 윈도우 아래쪽으로 나갔다면
}
