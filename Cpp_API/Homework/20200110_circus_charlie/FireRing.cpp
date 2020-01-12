#include "stdafx.h"
#include "FireRing.h"


void FireRing::moveLeft()
{
	_count++;

	if (_count >= _SPEED_RING)
	{
		_count = 0;
		_img[0]->setX(_img[0]->getX() - _TICK_RINGMOVE);
		_img[1]->setX(_img[1]->getX() - _TICK_RINGMOVE);
	}
}

void FireRing::reinit_ring()
{
	int x = _img[1]->getX();
	int w = _sizeRing.x;

	if (x + w < 0)
	{
		_img[0]->setX(WINSIZEX);
		_img[0]->setY(WINSIZEY * 0.382);
		_img[1]->setX(_img[0]->getX() + _sizeRing.x);
		_img[1]->setY(WINSIZEY * 0.382);
	}//if: ���� right�� ���� ���� ������
}

FireRing::FireRing()
{
}
FireRing::~FireRing()
{
}

HRESULT FireRing::init()
{
	_img[0] = IMAGEMANAGER->addImage("��1", "images/Big_firering1_1_Re.bmp",
		_sizeRing.x, _sizeRing.y, true, COLOR_MAGENTA);
	_img[1] = IMAGEMANAGER->addImage("��2", "images/Big_firering1_2_Re.bmp",
		_sizeRing.x, _sizeRing.y, true, COLOR_MAGENTA);

	_img[0]->setX(WINSIZEX);
	_img[0]->setY(WINSIZEY * 0.382);
	_img[1]->setX(_img[0]->getX() + _sizeRing.x);
	_img[1]->setY(WINSIZEY * 0.382);

	return S_OK;
}

void FireRing::release()
{
	IMAGEMANAGER->deleteImage("��1");
	IMAGEMANAGER->deleteImage("��2");

	SAFE_DELETE(_img[0]);
	SAFE_DELETE(_img[1]);
}

void FireRing::update()
{
	moveLeft();

	reinit_ring();
}

void FireRing::render()
{
	IMAGEMANAGER->render("��1", getMemDC(), _img[0]->getX(), _img[0]->getY());
	IMAGEMANAGER->render("��2", getMemDC(), _img[1]->getX(), _img[1]->getY());
}

void FireRing::render(indexRing index)
{
	switch (index)
	{
	case ID_BACK:
		IMAGEMANAGER->render("��1", getMemDC(), _img[0]->getX(), _img[0]->getY());
		break;
	case ID_FRONT:
		IMAGEMANAGER->render("��2", getMemDC(), _img[1]->getX(), _img[1]->getY());
		break;
	}
}
