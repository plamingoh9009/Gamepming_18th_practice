#include "myFunc.h"
#include "stdafx.h"

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
		}//end of if: �׸��� ����, �Ʒ����� ���� ��~�Ʒ� ���� �϶�
	}//end of if: �׸��� �������� ���� ������ �Ѿ�ٸ�

	

	return false;
}