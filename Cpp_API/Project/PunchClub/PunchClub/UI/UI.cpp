#include "stdafx.h"
#include "UI.h"

MAPICON::TYPE UI::_mapIcon_on = MAPICON::ICN_EMPTY;
POINT UI::_playerIcon_center = {0, 0};
bool UI::_fplayerIcon_move = false;
HRESULT UI::init()
{
	return S_OK;
}
void UI::release()
{
}
void UI::update()
{
}
void UI::render()
{
}
UI::UI()
{
	_obj = new Object;
}
UI::~UI()
{
	_obj->release();
	_obj = nullptr;
}
