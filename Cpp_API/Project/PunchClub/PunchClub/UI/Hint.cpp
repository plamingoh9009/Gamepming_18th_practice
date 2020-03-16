#include "stdafx.h"
#include "Hint.h"

HRESULT Hint::init_imgs()
{
	string path;
	HRESULT result;
	int result_cnt = 0;
	_bg = new Image;
	path = _imgPath + "hint_back.bmp";
	_bg_fileName = path;
	result = _bg->init(path.c_str(), (int)(180 * GAME_MULTIPLE), (int)(60 * GAME_MULTIPLE));
	result_cnt = (result == S_OK ? result_cnt : result_cnt++);
	_corner_under = new Image;
	path = _imgPath + "hint_corner_under.bmp";
	result = _corner_under->init(path.c_str(), (int)(13 * GAME_MULTIPLE), (int)(10 * GAME_MULTIPLE));
	result_cnt = (result == S_OK ? result_cnt : result_cnt++);
	_corner_upper = new Image;
	path = _imgPath + "hint_corner_upper.bmp";
	result = _corner_upper->init(path.c_str(), (int)(13 * GAME_MULTIPLE), (int)(10 * GAME_MULTIPLE));
	result_cnt = (result == S_OK ? result_cnt : result_cnt++);
	result = (result_cnt == 0 ? S_OK : E_FAIL);
	return result;
}
void Hint::delete_imgs()
{
}
void Hint::draw_imgs()
{
	if (_fPositionOK == true)
	{
		Draw(_bg, get_memDC());
		if (_fCorner_upper == true)
		{
			Draw(_corner_upper, get_memDC());
		}
		else
		{
			Draw(_corner_under, get_memDC());
		}
	}
}

void Hint::draw_texts()
{
	_title.render(get_memDC());
	_descr.render(get_memDC());
}

void Hint::update_imgPos()
{
	POINT center;
	RECT rc;
	center.x = (LONG)(m_ptMouse.x + _bg->get_width() * 0.4375);
	center.y = (LONG)(m_ptMouse.y - _bg->get_height() * 0.6);
	rc = RectMakeCenter(center.x, center.y, _bg->get_width(), _bg->get_height());
	if (rc.top <= WIN_HALF_H * 0.5)
	{
		_fCorner_upper = true;
		center.x = (LONG)(m_ptMouse.x + _bg->get_width() * 0.4375);
		center.y = (LONG)(m_ptMouse.y + _bg->get_height() * 0.8);
	}
	else
	{
		_fCorner_upper = false;
	}
	set_center(center);
}
void Hint::update_textPos()
{
	POINT pos;
	// Title
	pos.x = (LONG)(_bg->get_rect().left + 25);
	pos.y = (LONG)(_bg->get_rect().top + 20);
	_title.set_pos(pos);
	// Description
	pos.x = (LONG)(pos.x);
	pos.y = (LONG)(pos.y + 30);
	_descr.set_pos(pos);
}

void Hint::resize_bg()
{
	auto texts = _descr.get_texts();
	auto iter = texts.begin();
	
	int height = texts.size();
	int big_width = 0;
	for (; iter != texts.end(); iter++)
	{
		if (big_width <= int((*iter).length()))
		{
			big_width = (int)((*iter).length());
		}
	}
	_bg->init(_bg_fileName.c_str(), (int)(big_width * 10.5), (int)(height * 65));
}

HRESULT Hint::init()
{
	set_imgPath("UI/Hint/");
	HRESULT result;
	result = init_imgs();

	return result;
}

void Hint::release()
{
	delete_imgs();
}

void Hint::update()
{
	update_imgPos();
	update_textPos();
}

void Hint::render()
{
	draw_imgs();
	draw_texts();
}
Hint::Hint()
{
}
Hint::~Hint()
{
}

void Hint::set_center(POINT center)
{
	POINT myCenter;
	if(_bg != nullptr)
	{
		_bg->set_center(center);
		// Corner Under
		myCenter.x = (LONG)(_bg->get_rect().left + _corner_under->get_width() * 1.5);
		myCenter.y = (LONG)(_bg->get_rect().bottom - _corner_under->get_height() * 0.75);
		_corner_under->set_center(myCenter);
		// Corner Upper
		myCenter.x = (LONG)(_bg->get_rect().left + _corner_upper->get_width() * 1.5);
		myCenter.y = (LONG)(_bg->get_rect().top + _corner_upper->get_height() * 0.3);
		_corner_upper->set_center(myCenter);
		_fPositionOK = true;
	}
}

void Hint::set_texts(string title, string descr)
{
	_title = MyText(MYTEXT::TXT_DESCR, title, RGB(1, 1, 1));
	_descr = MyText(MYTEXT::TXT_DESCR, descr, RGB(71, 79, 81));
	_descr.set_maxChars(34);
	resize_bg();
}
