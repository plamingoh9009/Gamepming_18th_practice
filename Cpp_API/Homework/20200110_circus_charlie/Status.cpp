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
	_img = IMAGEMANAGER->addImage("½ºÅÈÃ¢", "images/¼­Ä¿½º_½ºÅÈÃ¢_¸®»çÀÌÁî.bmp",
		_sizeStat.x, _sizeStat.y, false, COLOR_MAGENTA);

	_img->setX(WINSIZEX / 6);
	_img->setY(15);

	return S_OK;
}

void Status::release()
{
	IMAGEMANAGER->deleteImage("½ºÅÈÃ¢");
	SAFE_DELETE(_img);
}

void Status::update()
{
}

void Status::render()
{
	IMAGEMANAGER->render("½ºÅÈÃ¢", getMemDC(), _img->getX(), _img->getY());
}
