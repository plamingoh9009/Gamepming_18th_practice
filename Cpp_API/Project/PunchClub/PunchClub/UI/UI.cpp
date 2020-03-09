#include "stdafx.h"
#include "UI.h"

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
