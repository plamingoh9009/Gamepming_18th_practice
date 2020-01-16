#include "stdafx.h"
#include "ObjectControl.h"


ObjectControl::ObjectControl()
{
}
ObjectControl::~ObjectControl()
{
}
HRESULT ObjectControl::init()
{
	_plant = new Plant;
	_plant->init();
	_plant->set_plant("SunFlower", 200, 200);
	return S_OK;
}
void ObjectControl::release()
{
	_plant->release();
	IMAGEMANAGER->deleteImage("SunFlower");
	IMAGEMANAGER->deleteImage("Wallnut");
	IMAGEMANAGER->deleteImage("PeaShooter");
}
void ObjectControl::update()
{
	_plant->update();
}
void ObjectControl::render()
{
	_plant->render();
}
