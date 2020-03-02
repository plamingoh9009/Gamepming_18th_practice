#include "stdafx.h"
#include "HudBack.h"

HRESULT HudBack::init()
{
	set_imgPath("UI/");
	string path = _imgPath + "Hud_back.bmp";
	_hud_back = new Image;
	_hud_back->init(path.c_str(), (int)(400 * GAME_MULTIPLE), (int)(70 * GAME_MULTIPLE));
	_hud_back_center.x = (LONG)(WIN_HALF_W);
	_hud_back_center.y = (LONG)(0 + _hud_back->get_height() * 0.33);
	_hud_back_rc = RectMakeCenter(_hud_back_center.x, _hud_back_center.y,
		_hud_back->get_width(), _hud_back->get_height());
	return S_OK;
}
void HudBack::release()
{
	_hud_back->release();
	_hud_back = nullptr;
}
void HudBack::update()
{
}
void HudBack::render()
{
	_hud_back->render(get_memDC(), _hud_back_rc.left, _hud_back_rc.top);
	if (_fDebug) { ColorRect(get_memDC(), _hud_back_rc); }
}
HudBack::HudBack()
{
}
HudBack::~HudBack()
{
}
