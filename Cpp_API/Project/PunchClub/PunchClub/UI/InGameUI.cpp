#include "stdafx.h"
#include "InGameUI.h"

HRESULT InGameUI::init()
{
	_icons = new Icon;
	_icons->init();
	_hud_back = new HudBack;
	_hud_back->init();
	_red_button = new RedButton;
	_red_button->init();
	return S_OK;
}
void InGameUI::release()
{
	_icons->release();
	_hud_back->release();
	_red_button->release();
	_icons = nullptr;
	_hud_back = nullptr;
	_red_button = nullptr;
}
void InGameUI::update()
{
	_hud_back->update();
	// 여기서 씬체인지 하기 때문에 가장 아래 둔다.
	_icons->update();
	if (_fRedButton) { _red_button->update(); }
}
void InGameUI::render()
{
	_icons->render();
	_hud_back->render();
	if (_fRedButton) { _red_button->render(); }
}
InGameUI::InGameUI()
{
}
InGameUI::~InGameUI()
{
}
