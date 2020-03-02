#include "stdafx.h"
#include "RedButton.h"

void RedButton::init_red_button()
{
	string path;
	POINT center;
	path = _imgPath + "Btn_red_back.bmp";
	_red_button = new Image;
	_red_button->init(path.c_str(), (int)(20 * GAME_MULTIPLE), (int)(20 * GAME_MULTIPLE));
	center.x = (LONG)(WINSIZEX - _red_button->get_width() * 1);
	center.y = (LONG)(0 + _red_button->get_height() * 1);
	_red_button_rc = RectMakeCenter(center.x, center.y,
		_red_button->get_width(), _red_button->get_height());
	_red_button_center = center;
	path = _imgPath + "Btn_del.bmp";
	_del_icon = new Image;
	_del_icon->init(path.c_str(), (int)(18 * GAME_MULTIPLE), (int)(18 * GAME_MULTIPLE));
	center.x -= (LONG)(_del_icon->get_width() * 0.06);
	center.y -= (LONG)(_del_icon->get_height() * 0.06);
	_del_icon_rc = RectMakeCenter(center.x, center.y,
		_del_icon->get_width(), _del_icon->get_height());
}
void RedButton::draw_red_button()
{
	_red_button->render(get_memDC(), _red_button_rc.left, _red_button_rc.top);
	_del_icon->render(get_memDC(), _del_icon_rc.left, _del_icon_rc.top);
	if (_fDebug)
	{
		ColorRect(get_memDC(), _red_button_rc, RGB(255, 77, 77));
		ColorRect(get_memDC(), _del_icon_rc);
	}
}
void RedButton::delete_red_button()
{
	_red_button->release();
	_del_icon->release();
	_red_button = nullptr;
	_del_icon = nullptr;
}

HRESULT RedButton::init()
{
	set_imgPath("UI/");
	init_red_button();
	return S_OK;
}
void RedButton::release()
{
	delete_red_button();
}
void RedButton::update()
{
}
void RedButton::render()
{
	draw_red_button();
}
RedButton::RedButton()
{
}
RedButton::~RedButton()
{
}
