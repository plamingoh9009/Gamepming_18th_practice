#include "stdafx.h"
#include "Button.h"

void Button::init_red_button()
{
	string path;
	POINT center;
	path = _imgPath + "Btn_red_back.bmp";
	_red_button = new Image;
	_red_button->init(path.c_str(), (int)(20 * GAME_MULTIPLE), (int)(20 * GAME_MULTIPLE));
	center.x = (LONG)(WINSIZEX - _red_button->get_width() * 1);
	center.y = (LONG)(0 + _red_button->get_height() * 1);
	_button_rc = RectMakeCenter(center.x, center.y,
		_red_button->get_width(), _red_button->get_height());
	_button_center = center;
	path = _imgPath + "Btn_del.bmp";
	_del_icon = new Image;
	_del_icon->init(path.c_str(), (int)(18 * GAME_MULTIPLE), (int)(18 * GAME_MULTIPLE));
	center.x -= (LONG)(_del_icon->get_width() * 0.06);
	center.y -= (LONG)(_del_icon->get_height() * 0.06);
	_fore_rc = RectMakeCenter(center.x, center.y,
		_del_icon->get_width(), _del_icon->get_height());
}
void Button::init_red_button(int x, int y)
{
	string path;
	POINT center;
	path = _imgPath + "Btn_red_back.bmp";
	_red_button = new Image;
	_red_button->init(path.c_str(), (int)(20 * GAME_MULTIPLE), (int)(20 * GAME_MULTIPLE));
	center.x = (LONG)(x - _red_button->get_width() * 0.7);
	center.y = (LONG)(y + _red_button->get_height() * 0.7);
	_button_rc = RectMakeCenter(center.x, center.y,
		_red_button->get_width(), _red_button->get_height());
	_button_center = center;
	path = _imgPath + "Btn_del.bmp";
	_del_icon = new Image;
	_del_icon->init(path.c_str(), (int)(18 * GAME_MULTIPLE), (int)(18 * GAME_MULTIPLE));
	center.x -= (LONG)(_del_icon->get_width() * 0.06);
	center.y -= (LONG)(_del_icon->get_height() * 0.06);
	_fore_rc = RectMakeCenter(center.x, center.y,
		_del_icon->get_width(), _del_icon->get_height());
}
void Button::draw_red_button()
{
	_red_button->render(get_memDC(), _button_rc.left, _button_rc.top);
	_del_icon->render(get_memDC(), _fore_rc.left, _fore_rc.top);
	if (_fDebug)
	{
		ColorRect(get_memDC(), _button_rc, RGB(255, 77, 77));
		ColorRect(get_memDC(), _fore_rc);
	}
}
void Button::delete_red_button()
{
	_red_button->release();
	_del_icon->release();
	_red_button = nullptr;
	_del_icon = nullptr;
}

void Button::init_long_red_button(POINT center)
{
	string path = _imgPath + "Btn_red_long.bmp";
	_btn_red_long = new Image;
	_btn_red_long->init(path.c_str(), (int)(57 * GAME_MULTIPLE), (int)(20 * GAME_MULTIPLE));
	_button_rc = RectMakeCenter(center.x, center.y,
		_btn_red_long->get_width(), _btn_red_long->get_height());
	_button_center = center;
}
void Button::draw_long_red_button()
{
	_btn_red_long->render(get_memDC(), _button_rc.left, _button_rc.top);
}
void Button::update_long_red_button()
{
}
void Button::delete_long_red_button()
{
	_btn_red_long->release();
	_btn_red_long = nullptr;
}

void Button::draw_text_toButton()
{
	FontTextOut(get_memDC(), _text_pos.x, _text_pos.y, _text.c_str(),
		"ÈÞ¸Õ¸ÅÁ÷Ã¼", 25, RGB(254, 254, 254));
}

HRESULT Button::init()
{
	set_imgPath("UI/Button/");
	init_red_button();
	_type = BTN_RED;
	return S_OK;
}
HRESULT Button::init(BTN_TYPE type, int right, int top)
{
	set_imgPath("UI/Button/");
	switch (type)
	{
	case BTN_RED:
		init_red_button(right, top);
		break;
	default:
		break;
	}
	_type = type;
	return S_OK;
}
HRESULT Button::init(BTN_TYPE type, POINT center)
{
	set_imgPath("UI/Button/");
	switch (type)
	{
	case BTN_RED_LONG:
		init_long_red_button(center);
		break;
	default:
		break;
	}
	_type = type;
	return S_OK;
}
void Button::release()
{
	switch (_type)
	{
	case BTN_RED:
		delete_red_button();
		break;
	case BTN_RED_LONG:
		delete_long_red_button();
	default:
		break;
	}
}
void Button::update()
{
}
void Button::render()
{
	switch (_type)
	{
	case BTN_RED:
		draw_red_button();
		break;
	case BTN_RED_LONG:
		draw_long_red_button();
		break;
	default:
		break;
	}
	if (_fText) { draw_text_toButton(); }
}
Button::Button()
{
}
Button::~Button()
{
}

void Button::set_text_toButton(string text)
{
	_text = text;
	_fText = true;
	_text_pos.x = (LONG)(_button_center.x - text.length() * 5);
	_text_pos.y = (LONG)(_button_center.y - 8);
}