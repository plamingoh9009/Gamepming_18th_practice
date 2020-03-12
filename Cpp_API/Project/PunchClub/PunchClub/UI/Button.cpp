#include "stdafx.h"
#include "Button.h"

HRESULT Button::init_red_button()
{
	// Result to return
	HRESULT result;
	int result_cnt = 0;
	// Init
	string path;
	_button = new Image;
	path = _imgPath + "Btn_red_back.bmp";
	result = _button->init(path.c_str(), (int)(20 * GAME_MULTIPLE), (int)(20 * GAME_MULTIPLE));
	result_cnt = (result == S_OK ? result_cnt: result_cnt++);
	// Return
	result = (result_cnt == 0 ? S_OK : E_FAIL);
	return result;
}
//==========================================
//##		Long Red Button			  ##
//==========================================
HRESULT Button::init_long_red_button()
{
	// Result to return
	HRESULT result;

	string path = _imgPath + "Btn_red_long.bmp";
	_button = new Image;
	result = _button->init(path.c_str(), (int)(57 * GAME_MULTIPLE), (int)(20 * GAME_MULTIPLE));
	// Return
	return result;
}
void Button::update_long_red_button()
{
}
HRESULT Button::init_delete_red_button()
{
	// Result to return
	HRESULT result;
	int result_cnt = 0;
	string path;
	// Init
	_button = new Image;
	path = _imgPath + "Btn_red_back.bmp";
	result = _button->init(path.c_str(), (int)(20 * GAME_MULTIPLE), (int)(20 * GAME_MULTIPLE));
	result_cnt = (result == S_OK ? result_cnt : result_cnt++);
	_icon = new Image;
	path = _imgPath + "del_icon.bmp";
	result = _icon->init(path.c_str(), (int)(18 * GAME_MULTIPLE), (int)(18 * GAME_MULTIPLE));
	result_cnt = (result == S_OK ? result_cnt : result_cnt++);
	_iconType = BUTTON::ICN_DELETE;
	// Return
	result = (result_cnt == 0 ? S_OK : E_FAIL);
	return result;
}
void Button::update_delete_red_button()
{
	if (_fClick)
	{
		if (PtInRect(&_button->get_rect(), m_ptMouse))
		{
			_fCloseWindow = true;
		}
	}
}
//==========================================
//##		Long Green Button			  ##
//==========================================
HRESULT Button::init_long_green_button()
{
	HRESULT result;

	string path = _imgPath + "Btn_green_long.bmp";
	_button = new Image;
	result = _button->init(path.c_str(), (int)(57 * GAME_MULTIPLE), (int)(20 * GAME_MULTIPLE));
	return result;
}
void Button::update_long_green_button()
{
}
//==========================================
//##		Bus Green Button			  ##
//==========================================
HRESULT Button::init_bus_green_button()
{
	HRESULT result;

	string path = _imgPath + "Btn_bus_green.bmp";
	_button = new Image;
	result = _button->init(path.c_str(), (int)(107 * GAME_MULTIPLE), (int)(30 * GAME_MULTIPLE));
	return result;
}
void Button::update_bus_green_button()
{
	switch (_iconType)
	{
	case BUTTON::ICN_DOLLAR:
		break;
	case BUTTON::ICN_TIME_DAYS:
		break;
	}
	_fCloseWindow = true;
	_fplayerIcon_move = true;
}

void Button::draw_text_toButton()
{
	_text.render(get_memDC());
}

HRESULT Button::init()
{
	set_imgPath("UI/Button/");
	init_red_button();
	_type = BUTTON::BTN_RED;
	return S_OK;
}
HRESULT Button::init(BUTTON::TYPE type)
{
	// Result to return
	HRESULT result;

	set_imgPath("UI/Button/");
	_type = type;
	switch (type)
	{
	case BUTTON::BTN_RED:
		result = init_red_button();
		break;
	case BUTTON::BTN_RED_LONG:
		result = init_long_red_button();
		break;
	case BUTTON::BTN_DELETE_RED:
		result = init_delete_red_button();
		break;
	case BUTTON::BTN_GREEN_LONG:
		result = init_long_green_button();
		break;
	case BUTTON::BTN_BUS_GREEN :
		result = init_bus_green_button();
		break;
	default:
		result = E_FAIL;
		break;
	}
	return result;
}

void Button::release()
{
	if (_button != nullptr)
	{
		Release(_button);
	}
	if (_icon != nullptr)
	{
		Release(_icon);
	}
}
void Button::update()
{
	switch (_type)
	{
	case BUTTON::BTN_DELETE_RED:
		update_delete_red_button();
		break;
	case BUTTON::BTN_BUS_GREEN:
		update_bus_green_button();
		break;
	}
}
void Button::render()
{
	if (_button != nullptr) { Draw(_button, get_memDC()); }
	if (_icon != nullptr) { Draw(_icon, get_memDC()); }
	if (_fText) { draw_text_toButton(); }

	if (_fDebug)
	{
		ColorRect(get_memDC(), _button->get_rect(), RGB(255, 77, 77));
		ColorRect(get_memDC(), _icon->get_rect());
	}
}
Button::Button()
{
}
Button::~Button()
{
}

void Button::set_text_toButton(string text)
{
	POINT pos;
	_text = MyText(MYTEXT::TXT_TITLE, text);
	pos.x = (LONG)(_button->get_center().x - text.length() * 5);
	pos.y = (LONG)(_button->get_center().y - 25 * 0.5);
	_text.set_pos(pos);
	_text.set_size(25);
	_fText = true;
}

void Button::set_icon_toButton(BUTTON::ICON type, POINT center)
{
	string path;
	_icon = new Image;
	_iconType = type;
	switch (type)
	{
	case BUTTON::ICN_DOLLAR:
		path = _imgPath + "dollar_icon.bmp";
		_icon->init(path.c_str(), (int)(15 * GAME_MULTIPLE), (int)(15 * GAME_MULTIPLE));
		break;
	case BUTTON::ICN_TIME_DAYS:
		path = _imgPath + "time_days_icon.bmp";
		_icon->init(path.c_str(), (int)(11 * GAME_MULTIPLE), (int)(11 * GAME_MULTIPLE));
		break;
	}
	_icon->set_center(center);
}
void Button::set_center(POINT center)
{
	_button->set_center(center);
}

void Button::set_pos_toRT_edge(RECT rc)
{
	POINT center;
	center.x = (LONG)(rc.right - _button->get_width() * 0.7);
	center.y = (LONG)(rc.top + _button->get_height() * 0.7);
	_button->set_center(center);

	center.x -= (LONG)(_icon->get_width() * 0.06);
	center.y -= (LONG)(_icon->get_height() * 0.06);
	_icon->set_center(center);
}
