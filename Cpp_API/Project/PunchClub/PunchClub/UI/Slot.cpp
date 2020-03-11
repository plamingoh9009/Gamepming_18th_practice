#include "stdafx.h"
#include "Slot.h"

void Slot::init_bg(SLOT::TYPE type)
{
	string path;
	switch (type)
	{
	case SLOT::SLOT_ACTIVE_SKILL:
		path = _imgPath + "skill_lock_cell.bmp";
		_bg = new Image;
		_bg->init(path.c_str(), (int)(36 * GAME_MULTIPLE), (int)(36 * GAME_MULTIPLE));
		break;
	default:
		break;
	}
}
void Slot::draw_bg()
{
	if (_bg != nullptr && _bg_rc != nullptr)
	{
		_bg->render(get_memDC(), _bg_rc->left, _bg_rc->top);
	}
}
void Slot::delete_bg()
{
	if (_bg != nullptr)
	{
		_bg->release();
		_bg = nullptr;
		SAFE_DELETE(_bg_rc);
	}
}

HRESULT Slot::init(SLOT::TYPE type)
{
	set_imgPath("UI/Skill/");
	_type = type;
	init_bg(type);
	return S_OK;
}
void Slot::release()
{
	delete_bg();
}
void Slot::update()
{
}
void Slot::render()
{
	draw_bg();
}
Slot::Slot()
{
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
		_bg_rc = new RECT;
		*_bg_rc = RectMakeCenter(center.x, center.y, _bg->get_width(), _bg->get_height());
	}
}
