#include "stdafx.h"
#include "myFunc.h"

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
	if ( (window.left <= me.left && me.left <= window.right) &&
		(window.left <= me.right && me.right <= window.right) )
	{
		if ((window.top <= me.top && me.top <= window.bottom) &&
			(window.top <= me.bottom && me.bottom <= window.bottom))
		{
			return true;
		}//end of if: �׸��� ����, �Ʒ����� ���� ����~�Ʒ��� ���� �ȿ� ���� ��
	}//end of if: �׸��� ����, �������� ���� ����~������ ���� �ȿ� �ְ�
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

void moveRect(RECT * me, WPARAM wParam)
{
	switch (wParam)
	{
	case VK_LEFT:
		me->left -= 10;
		me->right -= 10;
		break;
	case VK_RIGHT:
		me->left += 10;
		me->right += 10;
		break;
	case VK_UP:
		me->top -= 10;
		me->bottom -= 10;
		break;
	case VK_DOWN:
		me->top += 10;
		me->bottom += 10;
		break;
	}
}

RECT makeLittleRect(const RECT me)
{
	return RectMakeCenter(
		(me.right + me.left) / 2,
		(me.bottom + me.top) / 2,
		(me.right - me.left) / 5,
		(me.bottom - me.top) / 5);
}
