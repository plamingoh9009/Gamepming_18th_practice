#include "stdafx.h"
#include "playerControl.h"

void run_playerMove(RECT* player)
{
	int distance = 3;
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		player->left -= distance;
		player->right -= distance;
	}//end of if: ����Ű�� ������ �ִٸ�
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		player->left += distance;
		player->right += distance;
	}
}
