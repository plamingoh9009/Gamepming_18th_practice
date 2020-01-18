#include "stdafx.h"
#include "Stage.h"
void Stage::update_uiToObjControl()
{
	//시드카드의 렉트 맵을 오브젝트컨트롤로 넘긴다.
	_objControl->set_cardRects(_ui->get_cardRects());
	_objControl->set_itCardRects(_ui->get_itCardRects());
	// 맵의 공간 렉트 벡터를 오브젝트컨트롤로 넘긴다.
	_objControl->set_mapSpaces(_ui->get_mapSpaces());
	_objControl->set_itMapSpaces(_ui->get_itMapSpaces());
}
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
	update_uiToObjControl();
	_objControl->update();
}
void Stage::render()
{
	_ui->render();
	_objControl->render();	
}
