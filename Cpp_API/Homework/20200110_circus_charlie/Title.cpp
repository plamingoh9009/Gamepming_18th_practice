#include "stdafx.h"
#include "Title.h"


bool Title::get_fOffTitle()
{
	return _fOffTitle;
}

void Title::run_title()
{
	_count++;

	if (_count > _SPEED_FRAME)
	{
		_count = 0;

		if (_index >= _maxFrame)
		{
			_index = 0;
		}//end of if: 인덱스가 최대프레임수 보다 크거나 같으면
		else
		{
			_index++;
		}
	}

	

	// 인덱스 셋팅이 끝났으면 프레임을 셋팅한다.
	_img->setFrameX(_index);
}

Title::Title()
{
}
Title::~Title()
{
}

HRESULT Title::init()
{
	_img = IMAGEMANAGER->addFrameImage("타이틀", "images/서커스_타이틀.bmp",
		1200, 180, 3, 1, true, COLOR_MAGENTA);

	_img->setX(WINSIZEX * 0.3);
	_img->setY(WINSIZEY * 0.1);
	_img->setFrameX(0);
	_img->setFrameY(0);

	_maxFrame = 3;
	_index = 0;

	// 타이틀 종료 변수
	_fOffTitle = false;
	return S_OK;
}

void Title::release()
{
	// 여기서 이미지 전부 해제한다.
	IMAGEMANAGER->deleteImage("타이틀");
	SAFE_DELETE(_img);
}

void Title::update()
{
	run_title();

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_fOffTitle = true;
	}
}

void Title::render()
{
	IMAGEMANAGER->frameRender("타이틀", getMemDC(),
		_img->getX(), _img->getY(), _img->getFrameX(), _img->getFrameY());
	//IMAGEMANAGER->render("타이틀", getMemDC());
}
