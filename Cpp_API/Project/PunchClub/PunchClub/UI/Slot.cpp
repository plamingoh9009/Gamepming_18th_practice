#include "stdafx.h"
#include "Slot.h"

void Slot::init_bg(SLOT::TYPE type)
{
	string path;
	switch (type)
	{
	case SLOT::SLT_ACTIVE_SKILL:
		path = _imgPath + "skill_lock_cell.bmp";
		_bg = new Image;
		_bg->init(path.c_str(), (int)(36 * GAME_MULTIPLE), (int)(36 * GAME_MULTIPLE));
		break;
	case SLOT::SLT_ITEM:
		set_imgPath("UI/Slot/");
		_bg = new Image;
		path = _imgPath + "Inven_slot.bmp";
		_bg->init(path.c_str(), (int)(210 * GAME_MULTIPLE), (int)(60 * GAME_MULTIPLE));
		// Item initial to type
		init_item();
		// Green button
		_btn = new Button(BUTTON::BTN_GREEN_INVEN);
		_btn->init();
		break;
	}
}
void Slot::draw_bg()
{
	Draw(_bg, get_memDC());
	draw_item();
}
void Slot::delete_bg()
{
	Release(_bg);
}

void Slot::init_item()
{
	string path;
	// FG Image's background
	_fg_back = new Image;
	path = _imgPath + "Item_bg.bmp";
	_fg_back->init(path.c_str(), (int)(40 * GAME_MULTIPLE), (int)(40 * GAME_MULTIPLE));
	switch (_itemType)
	{
	case SLOT::ITM_MEAT:
		_fg = new Image;
		path = _imgPath + "Meat.bmp";
		_fg->init(path.c_str(), (int)(39 * GAME_MULTIPLE), (int)(40 * GAME_MULTIPLE));
		
		_title = MyText(MYTEXT::TXT_DESCR, "고기", RGB(241, 223, 187));
		_title.set_size(30);
		_descr = MyText(MYTEXT::TXT_DESCR, "음메에?", RGB(54, 50, 39));
		break;
	case SLOT::ITM_SODA:
		_fg = new Image;
		path = _imgPath + "Soda.bmp";
		_fg->init(path.c_str(), (int)(27 * GAME_MULTIPLE), (int)(40 * GAME_MULTIPLE));

		_title = MyText(MYTEXT::TXT_DESCR, "소다", RGB(241, 223, 187));
		_title.set_size(30);
		_descr = MyText(MYTEXT::TXT_DESCR, "달고 맛있다. 하지만 건강에는 나쁘다.", RGB(54, 50, 39));
		_descr.set_size(22);
		break;
	case SLOT::ITM_PIZZA_BOX:
		_fg = new Image;
		path = _imgPath + "Pizza_box.bmp";
		_fg->init(path.c_str(), (int)(46 * GAME_MULTIPLE), (int)(32 * GAME_MULTIPLE));

		_title = MyText(MYTEXT::TXT_DESCR, "냉동 피자", RGB(241, 223, 187));
		_title.set_size(30);
		_descr = MyText(MYTEXT::TXT_DESCR, "평범한 피자와 같지만 냉동이 되어있다.", RGB(54, 50, 39));
		_descr.set_size(20);
		break;
	}
}
void Slot::draw_item()
{
	Draw(_fg_back, get_memDC());
	Draw(_fg, get_memDC());
	_title.render(get_memDC());
	_descr.render(get_memDC());
}
void Slot::setup_fg_center()
{
	POINT center;
	
	if (_fg != nullptr)
	{
		// Setup positions
		center.x = (LONG)(_bg->get_rect().left + _fg->get_width() * 0.65);
		center.y = (LONG)(_bg->get_center().y);
		_fg->set_center(center);
	}
	if (_fg_back != nullptr)
	{
		_fg_back->set_center(center);
	}
}
void Slot::setup_text_pos()
{
	POINT pos;
	if (_fg_back != nullptr)
	{
		pos.x = (LONG)(_fg_back->get_rect().right + 10);
		pos.y = (LONG)(_fg_back->get_rect().top - 10);
		_title.set_pos(pos);
		pos.y += 40;
		_descr.set_pos(pos);
	}
}
void Slot::setup_button()
{
	POINT center;
	if (_btn != nullptr)
	{
		center.x = (LONG)(_bg->get_rect().right - _btn->get_width() * 0.6);
		center.y = (LONG)(_bg->get_rect().bottom - _btn->get_height() * 0.7);
		_btn->set_center(center);
		switch (_itemType)
		{
		case SLOT::ITM_MEAT:
			_btn->set_text_toButton("$20", 20, MYTEXT::TXT_DESCR);
			break;
		case SLOT::ITM_SODA:
			_btn->set_text_toButton("$6", 20, MYTEXT::TXT_DESCR);
			break;
		case SLOT::ITM_PIZZA_BOX:
			_btn->set_text_toButton("$9", 20, MYTEXT::TXT_DESCR);
			break;
		}
	}
}

HRESULT Slot::init()
{
	set_imgPath("UI/Skill/");
	init_bg(_type);
	return S_OK;
}
void Slot::release()
{
	delete_bg();
	Release(_fg);
	Release(_fg_back);
}
void Slot::update()
{
}
void Slot::render()
{
	draw_bg();
	draw_item();
	Draw(_btn);
}
Slot::Slot(SLOT::TYPE type)
{
	_type = type;
}
Slot::Slot(SLOT::TYPE type, SLOT::ITEM itemType)
{
	_type = type;
	_itemType = itemType;
}
Slot::~Slot()
{
}

void Slot::set_slotInfo(SLOT::SKILL skill)
{
}
void Slot::set_slotCenter(POINT center)
{
	if (_bg != nullptr)
	{
		_bg->set_center(center);
		setup_fg_center();
		setup_text_pos();
		setup_button();
	}
}
void Slot::set_slotPos(POINT pos)
{
	if (_bg != nullptr)
	{
		_bg->set_pos(pos);
		setup_fg_center();
		setup_text_pos();
		setup_button();
	}
}
