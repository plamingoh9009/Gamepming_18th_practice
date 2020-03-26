#include "stdafx.h"
#include "Bead.h"
#include "Object/Player.h"
HRESULT Bead::init()
{
	set_imgPath("UI/Bead/");
	init_bead();
	setup_bead_position();
	return S_OK;
}
void Bead::release()
{
	Release(_img);
}
void Bead::update()
{
	if (_fNextPos)
	{
		if (_fDelete) {}
		else
		{
			move_toDestination();
		}
	}
	else
	{
		move_toNext();
	}
}
void Bead::render()
{
	Draw(_img, get_memDC());
}
Bead::Bead()
{
}
Bead::Bead(BEAD::TYPE type, bool isReverse)
{
	_type = type;
	_fReverse = isReverse;
}
Bead::~Bead()
{
}
HRESULT Bead::init_bead()
{
	string path;
	POINT center;
	switch (_type)
	{
		// Stat
	case BEAD::BD_HEALTH:
		_img = new Image;
		path = _imgPath + "drop_health.bmp";
		_img->init(path.c_str(), (int)(15 * 1.6), (int)(15 * 1.6));
		break;
	case BEAD::BD_FOOD:
		_img = new Image;
		path = _imgPath + "drop_food.bmp";
		_img->init(path.c_str(), (int)(15 * 1.6), (int)(15 * 1.6));
		break;
	case BEAD::BD_MOOD:
		_img = new Image;
		path = _imgPath + "drop_mood.bmp";
		_img->init(path.c_str(), (int)(15 * 1.6), (int)(15 * 1.6));
		break;
	case BEAD::BD_ENERGY:
		_img = new Image;
		path = _imgPath + "drop_energy.bmp";
		_img->init(path.c_str(), (int)(15 * 1.6), (int)(15 * 1.6));
		break;
		// Fight
	case BEAD::BD_STR:
		_img = new Image;
		path = _imgPath + "drop_str.bmp";
		_img->init(path.c_str(), (int)(15 * GAME_MULTIPLE), (int)(15 * GAME_MULTIPLE));
		break;
	case BEAD::BD_AGL:
		_img = new Image;
		path = _imgPath + "drop_agl.bmp";
		_img->init(path.c_str(), (int)(15 * GAME_MULTIPLE), (int)(15 * GAME_MULTIPLE));
		break;
	case BEAD::BD_STM:
		_img = new Image;
		path = _imgPath + "drop_stm.bmp";
		_img->init(path.c_str(), (int)(15 * GAME_MULTIPLE), (int)(15 * GAME_MULTIPLE));
		break;
	}
	return S_OK;
}
void Bead::setup_bead_position()
{
	POINT center;
	if (_fReverse)
	{
		center.x = (LONG)(10);
		center.y = (LONG)(10);
		_img->set_center(center);
	}
	else
	{
		center.x = (LONG)(PLAYER->get_playerCenter().x);
		center.y = (LONG)(PLAYER->get_playerCenter().y - 50);
		_img->set_center(center);
		// Next
		_nextPos.x = center.x;
		_nextPos.y = center.y - 100;
	}
}

void Bead::move_toNext()
{
	POINT center;
	if (_nextPos.x && _nextPos.y)
	{
		center = _img->get_center();
		if (center.y > _nextPos.y)
		{
			center.y--;
		}
		else if (center.y < _nextPos.y)
		{
			center.y++;
		}
		else
		{
			_fNextPos = true;
		}
		_img->set_center(center);
	}
}

void Bead::move_toDestination()
{
	POINT center;
	bool xOK = false;
	bool yOK = false;
	if (_dest.x && _dest.y)
	{
		center = _img->get_center();
		if (center.y > _dest.y)
		{
			center.y--;
		}
		else if (center.y < _dest.y)
		{
			center.y++;
		}
		else
		{
			yOK = true;
		}

		if (center.x > _dest.x)
		{
			center.x--;
		}
		else if (center.x < _dest.x)
		{
			center.x++;
		}
		else
		{
			xOK = true;
		}
		_img->set_center(center);
	}

	if (xOK && yOK)
	{
		_fDelete = true;
	}
}
