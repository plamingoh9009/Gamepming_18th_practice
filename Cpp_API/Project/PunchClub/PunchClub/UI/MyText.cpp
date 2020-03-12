#include "stdafx.h"
#include "MyText.h"

HRESULT MyText::init()
{
	return E_NOTIMPL;
}
void MyText::release()
{
}
void MyText::update()
{
}
void MyText::render(HDC hdc)
{
	if (_text != "")
	{
		switch (_type)
		{
		case MYTEXT::TXT_TITLE:
			FontTextShadow(hdc, _pos.x, _pos.y, _text.c_str(), _font.c_str(), _size, _color);
			break;
		case MYTEXT::TXT_DESCR:
			FontTextOut(hdc, _pos.x, _pos.y, _text.c_str(), _font.c_str(), _size, _color);
			break;
		}
	}
}
MyText::MyText()
{
}
MyText::MyText(MYTEXT::TYPE type, string text, COLORREF color)
{
	_type = type;
	switch (type)
	{
	case MYTEXT::TXT_TITLE:
		_size = 35;
		_font = "ÈÞ¸Õ¸ÅÁ÷Ã¼";
		if (color == NULL)
		{
			_color = RGB(254, 254, 254);
		}
		break;
	case MYTEXT::TXT_DESCR:
		_size = 25;
		_font = "ÈÞ¸ÕÆíÁöÃ¼";
		if (color == NULL)
		{
			_color = RGB(1, 1, 1);
		}
		break;
	default:
		_size = 20;
		_font = "±Ã¼­Ã¼";
		if (color == NULL)
		{
			_color = RGB(1, 1, 1);
		}
		break;
	}
	// default Color
	if (color != NULL)
	{
		_color = color;
	}
	// Text
	_text = text;
}
MyText::~MyText()
{
}