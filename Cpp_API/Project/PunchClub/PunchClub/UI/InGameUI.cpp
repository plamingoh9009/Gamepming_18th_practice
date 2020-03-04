#include "stdafx.h"
#include "InGameUI.h"
// ====================================
// ***		¾À¿¡¼­ ´Ý±â ´­·¶À» ¶§		***
// ====================================
void InGameUI::run_red_button()
{
	if (_fClick == true && PtInRect(&_red_button->get_rc(), m_ptMouse))
	{
		_scene_forChange = SCENE_BACK;
		_fClick = false;
	}//if: ¹öÆ°À» ´­·¶´Ù¸é ¾ÀÀ» µÇµ¹¸°´Ù.
}
// ====================================
// ***		³ÃÀå°í ¿­¾úÀ» ¶§			***
// ====================================
void InGameUI::update_friger()
{
	_inven_friger->update();
	if (_inven_friger->is_closeInven())
	{
		_fInven_friger = false;
		_inven_friger->init();
	}
}

HRESULT InGameUI::init()
{
	_icons = new Icon;
	_icons->init();
	_hud_back = new HudBack;
	_hud_back->init();
	_red_button = new RedButton;
	_red_button->init();
	_fRedButton = false;
	_inven_friger = new Inventory;
	_inven_friger->init(INVEN_FRIGER);
	_fInven_friger = false;
	return S_OK;
}
void InGameUI::release()
{
	_icons->release();
	_hud_back->release();
	_red_button->release();
	_inven_friger->release();
	_icons = nullptr;
	_hud_back = nullptr;
	_red_button = nullptr;
	_inven_friger = nullptr;
}
void InGameUI::update()
{
	_hud_back->update();
	_icons->update();
	if (_fRedButton) { run_red_button(); }
	if (_fInven_friger) { update_friger(); }
}
void InGameUI::render()
{
	_icons->render();
	_hud_back->render();
	if (_fRedButton) { _red_button->render(); }
	if (_fInven_friger) { _inven_friger->render(); }
}
InGameUI::InGameUI()
{
}
InGameUI::~InGameUI()
{
}
