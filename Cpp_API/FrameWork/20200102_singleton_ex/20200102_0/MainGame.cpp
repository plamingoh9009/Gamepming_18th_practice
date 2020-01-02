#include "stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init()
{
	GameNode::init();
	//rc = RectMake(30, 30, 100, 100);

	for (int i = 0; i < 5; i++)
	{
		box[i].rc = RectMake(30 + 150 * i , 30, 100, 100);
		box[i].touch = false;
	}
	return S_OK;
}

void MainGame::release()
{
	GameNode::release();
}

void MainGame::update()
{
	GameNode::update();

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		for (int i = 0; i < 5; i++)
		{
			if (PtInRect(&box[i].rc, m_ptMouse))
			{
				box[i].touch = true;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (box[i].touch)
		{
			box[i].rc.top += 5;
			box[i].rc.bottom += 5;
		}

		if (box[i].rc.bottom > WINSIZEY)
		{
			box[i].touch = false;
			box[i].rc = RectMakeCenter(30*i, 30*i, 100, 100);
		}
	}
}

void MainGame::render(HDC hdc)
{
	//Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	
	for (int i = 0; i < 5; i++)
	{
		Rectangle(hdc, box[i].rc.left, box[i].rc.top, 
			box[i].rc.right, box[i].rc.bottom);
	}
}

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}
