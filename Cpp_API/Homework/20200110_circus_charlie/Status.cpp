#include "stdafx.h"
#include "Status.h"


Status::Status()
{
}
Status::~Status()
{
}

HRESULT Status::init()
{
	_img = IMAGEMANAGER->addImage("����â", "images/��Ŀ��_����â_��������.bmp",
		_sizeStat.x, _sizeStat.y, false, COLOR_MAGENTA);

	_img->setX(WINSIZEX / 6);
	_img->setY(15);

	return S_OK;
}

void Status::release()
{
	IMAGEMANAGER->deleteImage("����â");
	SAFE_DELETE(_img);
}

void Status::update()
{
}

void Status::render()
{
	IMAGEMANAGER->render("����â", getMemDC(), _img->getX(), _img->getY());
}
