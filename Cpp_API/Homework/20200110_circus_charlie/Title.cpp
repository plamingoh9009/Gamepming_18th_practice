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
		}//end of if: �ε����� �ִ������Ӽ� ���� ũ�ų� ������
		else
		{
			_index++;
		}
	}

	

	// �ε��� ������ �������� �������� �����Ѵ�.
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
	_img = IMAGEMANAGER->addFrameImage("Ÿ��Ʋ", "images/��Ŀ��_Ÿ��Ʋ.bmp",
		1200, 180, 3, 1, true, COLOR_MAGENTA);

	_img->setX(WINSIZEX * 0.3);
	_img->setY(WINSIZEY * 0.1);
	_img->setFrameX(0);
	_img->setFrameY(0);

	_maxFrame = 3;
	_index = 0;

	// Ÿ��Ʋ ���� ����
	_fOffTitle = false;
	return S_OK;
}

void Title::release()
{
	// ���⼭ �̹��� ���� �����Ѵ�.
	IMAGEMANAGER->deleteImage("Ÿ��Ʋ");
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
	IMAGEMANAGER->frameRender("Ÿ��Ʋ", getMemDC(),
		_img->getX(), _img->getY(), _img->getFrameX(), _img->getFrameY());
	//IMAGEMANAGER->render("Ÿ��Ʋ", getMemDC());
}
