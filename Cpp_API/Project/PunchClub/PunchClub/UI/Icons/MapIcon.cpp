#include "stdafx.h"
#include "MapIcon.h"

HRESULT MapIcon::init_icon()
{
	string path;
	_icon_off = new Image;
	_icon_on = new Image;
	switch (_type)
	{
	case MAPICON::ICON_HOME:
		path = _imgPath + "Hud_home.bmp";
		_icon_off->init(path.c_str(), (int)(46 * GAME_MULTIPLE), (int)(33 * GAME_MULTIPLE));
		path = _imgPath + "Hud_home_on.bmp";
		_icon_on->init(path.c_str(), (int)(46 * GAME_MULTIPLE), (int)(33 * GAME_MULTIPLE));
		break;
	case MAPICON::ICON_SHOP:
		path = _imgPath + "Hud_shop.bmp";
		_icon_off->init(path.c_str(), (int)(46 * GAME_MULTIPLE), (int)(32 * GAME_MULTIPLE));
		path = _imgPath + "Hud_shop_on.bmp";
		_icon_on->init(path.c_str(), (int)(46 * GAME_MULTIPLE), (int)(32 * GAME_MULTIPLE));
		break;
	case MAPICON::ICON_GYM:
		path = _imgPath + "Hud_gym.bmp";
		_icon_off->init(path.c_str(), (int)(48 * GAME_MULTIPLE), (int)(31 * GAME_MULTIPLE));
		path = _imgPath + "Hud_gym_on.bmp";
		_icon_on->init(path.c_str(), (int)(48 * GAME_MULTIPLE), (int)(31 * GAME_MULTIPLE));
		break;
	case MAPICON::ICON_BUILD:
		path = _imgPath + "Hud_build.bmp";
		_icon_off->init(path.c_str(), (int)(46 * GAME_MULTIPLE), (int)(42 * GAME_MULTIPLE));
		path = _imgPath + "Hud_build_on.bmp";
		_icon_on->init(path.c_str(), (int)(46 * GAME_MULTIPLE), (int)(42 * GAME_MULTIPLE));
		break;
	case MAPICON::ICON_PLAYER:
		path = _imgPath + "Map_player.bmp";
		_icon_off->init(path.c_str(), (int)(30 * GAME_MULTIPLE), (int)(40 * GAME_MULTIPLE));
		_icon_on = nullptr;
		break;
	default:
		break;
	}
	// Result
	if (_type == MAPICON::ICON_PLAYER)
	{
		if (_icon_off != nullptr)
		{
			return S_OK;
		}
	}
	else
	{
		if (_icon_off != nullptr && _icon_on != nullptr)
		{
			return S_OK;
		}
	}
	return E_FAIL;
}
void MapIcon::draw_icon()
{
	if (_type == MAPICON::ICON_PLAYER)
	{
		if(_icon_off != nullptr)
			_icon_off->render(get_memDC(), _icon_off->get_rect().left, _icon_off->get_rect().top);
	}
	else
	{
		if (_icon_on != nullptr && _fIcon == true)
		{
			_icon_on->render(get_memDC(), _icon_on->get_rect().left, _icon_on->get_rect().top);
		}
		else if (_icon_off != nullptr && _fIcon == false)
		{
			_icon_off->render(get_memDC(), _icon_off->get_rect().left, _icon_off->get_rect().top);
		}
	}//else: 플레이어 아닌 아이콘 조건
	
	if (_fDebug)
	{
		if (_type == MAPICON::ICON_PLAYER)
		{
			ColorRect(get_memDC(), _icon_off->get_rect(), RGB(144, 233, 0));
		}
		else
		{
			ColorRect(get_memDC(), _icon_off->get_rect(), RGB(244, 180, 41));
		}

	}//if: Debug
}
void MapIcon::delete_icon()
{
	if (_icon_off != nullptr)
	{
		_icon_off->release();
		_icon_off = nullptr;
	}
	if (_icon_on != nullptr)
	{
		_icon_on->release();
		_icon_on = nullptr;
	}
}
void MapIcon::update_icon()
{
	if (PtInRect(&_icon_off->get_rect(), m_ptMouse))
	{
		_fIcon = true;
		if (_fClick)
		{
			_mapIcon_on = _type;
		}
	}
	else
	{
		_fIcon = false;
	}
}

HRESULT MapIcon::init(MAPICON::TYPE type)
{
	set_imgPath("UI/Icon/");
	_type = type;
	if (init_icon() == S_OK)
	{
		return S_OK;
	}
	return E_FAIL;
}
void MapIcon::release()
{
	delete_icon();
}
void MapIcon::update()
{
	update_icon();
}
void MapIcon::render()
{
	draw_icon();
}
MapIcon::MapIcon()
{
}
MapIcon::~MapIcon()
{
}

HRESULT MapIcon::set_center(POINT center)
{
	RECT rc;
	rc = RectMakeCenter(center.x, center.y, _icon_off->get_width(), _icon_off->get_height());
	_center = center;
	if (_type == MAPICON::ICON_PLAYER)
	{
		_icon_off->set_rect(rc);
		return S_OK;
	}
	else
	{
		_icon_off->set_rect(rc);
		_icon_on->set_rect(rc);
		return S_OK;
	}
	return E_FAIL;
}
