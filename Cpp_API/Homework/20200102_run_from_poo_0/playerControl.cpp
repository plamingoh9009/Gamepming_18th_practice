#include "stdafx.h"
#include "playerControl.h"

void run_playerMove(RECT* player)
{
	int distance = 3;
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		player->left -= distance;
		player->right -= distance;
	}//end of if: 왼쪽키를 누르고 있다면
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		player->left += distance;
		player->right += distance;
	}
}
