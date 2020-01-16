#include "stdafx.h"
#include "Stage.h"
Stage::Stage()
{
}
Stage::~Stage()
{
}
HRESULT Stage::init()
{
	_objControl = new ObjectControl;
	_objControl->init();
	_ui = new UI;
	_ui->init();
	return S_OK;
}
void Stage::release()
{
	_ui->release();
	_objControl->release();
}
void Stage::update()
{
	_ui->update();
	_objControl->update();
}
void Stage::render()
{
	_ui->render();
	_objControl->render();
}
