#include "stdafx.h"
#include "UI.h"

UI::UI()
{
}
UI::~UI()
{
}
HRESULT UI::init()
{
	_map = new Map;
	_map->init();
	_bank = new SeedBank;
	_bank->init();
	_flagMeter = new FlagMeter;
	_flagMeter->init();
	return S_OK;
}
void UI::release()
{
	_map->release();
	_bank->release();
	_flagMeter->release();
}
void UI::update()
{
	_map->update();
	_bank->update();
	_flagMeter->update();
}
void UI::render()
{
	_map->render();
	_bank->render();
	_flagMeter->render();
}