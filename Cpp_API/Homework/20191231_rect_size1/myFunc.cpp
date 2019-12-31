#include "stdafx.h"
#include "myFunc.h"

WPARAM isInRectEdge(RECT me, POINT pt)
{
	// ������� 1/3 ���� ���ϴ��� ����� ���
	LONG width = me.right - me.left;
	LONG height = me.bottom - me.top;

	LONG leftEdge = me.left + (width / 5);
	LONG rightEdge = me.right - (width / 5);
	LONG topEdge = me.top + (width / 5);
	LONG bottomEdge = me.bottom - (width / 5);

	if (isInRange(pt.x, me.left, leftEdge) == true)
	{
		return VK_LEFT;
	}//end of if: pt.x �� �簢�� ���� �����ڸ��� ���� ��
	else if (isInRange(pt.x, rightEdge, me.right) == true)
	{
		return VK_RIGHT;
	}//end of if: pt.x �� �簢�� ������ �����ڸ��� ���� ��
	else if (isInRange(pt.y, me.top, topEdge) == true)
	{
		return VK_UP;
	}//end of if: pt.y �� �簢�� ���� �����ڸ��� ���� ��
	else if (isInRange(pt.y, bottomEdge, me.bottom) == true)
	{
		return VK_DOWN;
	}//end of if: pt.y �� �簢�� �Ʒ��� �����ڸ��� ���� ��

	return NULL;
}

RECT controlRectSize(RECT me, POINT pt, WPARAM lo)
{
	if (lo == VK_LEFT)
	{
		me.left = pt.x;
	}//end of if: ���� ������ �ǵ���� ��
	else if (lo == VK_RIGHT)
	{
		me.right = pt.x;
	}
	else if (lo == VK_UP)
	{
		me.top = pt.y;
	}//end of if: ���� ������ �ǵ���� ��
	else if (lo == VK_DOWN)
	{
		me.bottom = pt.y;
	}

	// ���⼭ ū��, �������� �����Ѵ�.
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
	// ���� �浹��Ȳ���� �����Ѵ�.
	// �׸��� �������� ���� ���ʰ� �����鼭 
	if ((wall.left <= me.left && me.left <= wall.right) ||
		(wall.left <= me.right && me.right <= wall.right))
	{
		if ((wall.top <= me.top && me.top <= wall.bottom) ||
			(wall.top <= me.bottom && me.bottom <= wall.bottom))
		{
			return true;
		}//end of if: �׸��� ����, �Ʒ����� ���� ��~�Ʒ� ������ ���� ��
	}//end of if: �׸��� ����, �������� ���� ����~������ ������ ��ų�

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
		}//end of if: �׸��� ����, �Ʒ����� ���� ����~�Ʒ��� ���� �ȿ� ���� ��
	}//end of if: �׸��� ����, �������� ���� ����~������ ���� �ȿ� �ְ�
	return false;
}

bool isInWindow(POINT pt, RECT window)
{
	if (window.left <= pt.x && pt.x <= window.right)
	{
		if (window.top <= pt.y && pt.y <= window.bottom)
		{
			return true;
		}//end of if: ����Ʈ�� �������� ����~�Ʒ��� ���� �ȿ� ���� ��
	}//end of if: ����Ʈ�� �������� ����~������ ���� �ȿ� ���� ��
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
	// ���� ����
	temp = me->left;
	me->left = other->left;
	other->left = temp;

	// ������ ����
	temp = me->right;
	me->right = other->right;
	other->right = temp;

	// ž ����
	temp = me->top;
	me->top = other->top;
	other->top = temp;

	// ���� ����
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
		// 4���� ������ �����Ѵ�.

		if (me.right <= other->left || me.right <= other->right)
		{
			if (isInRange(me.top, other->top, other->bottom) ||
				isInRange(me.bottom, other->top, other->bottom))
			{
				moveRect(other, VK_RIGHT, 5);
			}//end of if: �� �׸� other�� top ~ bottom ������ �����Ҷ�
		}//end of if: �� �׸� ���ʿ��� �浹���� ��

		if (me.left >= other->right || me.left >= other->left)
		{
			if (isInRange(me.top, other->top, other->bottom) ||
				isInRange(me.bottom, other->top, other->bottom))
			{
				moveRect(other, VK_LEFT, 5);
			}//end of if: �� �׸� other�� top ~ bottom ������ �����Ҷ�
		}//end of if: �� �׸� �����ʿ��� �浹���� ��

		if (me.bottom <= other->top || me.bottom <= other->bottom)
		{
			if (isInRange(me.left, other->left, other->right) ||
				isInRange(me.right, other->left, other->right))
			{
				moveRect(other, VK_DOWN, 5);
			}//end of if: �� �׸� other�� left ~ right ������ �����Ҷ�
		}//end of if: �� �׸� ������ �浹���� ��

		if (me.top >= other->bottom || me.top >= other->top)
		{
			if (isInRange(me.left, other->left, other->right) ||
				isInRange(me.right, other->left, other->right))
			{
				moveRect(other, VK_UP, 5);
			}//end of if: �� �׸� other�� left ~ right ������ �����Ҷ�
		}//end of if: �� �׸� �Ʒ��� �浹���� ��
	}//end of if: �׸� �浹�ߴٸ�
}

void moveBackInWindow(RECT * me, RECT window)
{
	// ������ �������� �ǵ����� �Լ�

	if (me->left <= window.left)
	{
		moveRect(me, VK_RIGHT, 20);
	}//end of if: �� �׸� ������ ���� ������ �����ٸ�
	if (me->right >= window.right)
	{
		moveRect(me, VK_LEFT, 20);
	}//end of if: �� �׸� ������ ������ ������ �����ٸ�
	if (me->top <= window.top)
	{
		moveRect(me, VK_DOWN, 20);
	}//end of if: �� �׸� ������ ���� ������ �����ٸ�
	if (me->bottom >= window.bottom)
	{
		moveRect(me, VK_UP, 20);
	}//end of if: �� �׸� ������ �Ʒ������� �����ٸ�
}
