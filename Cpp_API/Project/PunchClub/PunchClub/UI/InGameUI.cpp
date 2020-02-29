#include "stdafx.h"
#include "InGameUI.h"

HRESULT InGameUI::init()
{
	_icons = new Icon;
	_icons->init();
	return S_OK;
}
void InGameUI::release()
{
	_icons->release();
	_icons = nullptr;
}
void InGameUI::update()
{
	_icons->update();
}
void InGameUI::render()
{
	_icons->render();
}
InGameUI::InGameUI()
{
}
InGameUI::~InGameUI()
{
}
