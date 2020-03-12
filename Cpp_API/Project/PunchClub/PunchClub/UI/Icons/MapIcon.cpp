#include "stdafx.h"
#include "MapIcon.h"

void MapIcon::update_playerIcon()
{
	if (_fplayerIcon_move == true)
	{
		_icon_off->set_center(_playerIcon_center);
		_fplayerIcon_move = false;
	}
}

bool MapIcon::is_player_atHere()
{
	if (_type != MAPICON::ICN_PLAYER)
	{
		if (_type == _current_location)
		{
			return true;
		}
	}//if: 플레이어가 같은 곳에 있으면 true
	return false;
}

HRESULT MapIcon::init_icon()
{
	string path;
	_icon_off = new Image;
	_icon_on = new Image;
	switch (_type)
	{
	case MAPICON::ICN_HOME:
		path = _imgPath + "Hud_home.bmp";
		_icon_off->init(path.c_str(), (int)(46 * GAME_MULTIPLE), (int)(33 * GAME_MULTIPLE));
		path = _imgPath + "Hud_home_on.bmp";
		_icon_on->init(path.c_str(), (int)(46 * GAME_MULTIPLE), (int)(33 * GAME_MULTIPLE));
		break;
	case MAPICON::ICN_SHOP:
		path = _imgPath + "Hud_shop.bmp";
		_icon_off->init(path.c_str(), (int)(46 * GAME_MULTIPLE), (int)(32 * GAME_MULTIPLE));
		path = _imgPath + "Hud_shop_on.bmp";
		_icon_on->init(path.c_str(), (int)(46 * GAME_MULTIPLE), (int)(32 * GAME_MULTIPLE));
		break;
	case MAPICON::ICN_GYM:
		path = _imgPath + "Hud_gym.bmp";
		_icon_off->init(path.c_str(), (int)(48 * GAME_MULTIPLE), (int)(31 * GAME_MULTIPLE));
		path = _imgPath + "Hud_gym_on.bmp";
		_icon_on->init(path.c_str(), (int)(48 * GAME_MULTIPLE), (int)(31 * GAME_MULTIPLE));
		break;
	case MAPICON::ICN_BUILD:
		path = _imgPath + "Hud_build.bmp";
		_icon_off->init(path.c_str(), (int)(46 * GAME_MULTIPLE), (int)(42 * GAME_MULTIPLE));
		path = _imgPath + "Hud_build_on.bmp";
		_icon_on->init(path.c_str(), (int)(46 * GAME_MULTIPLE), (int)(42 * GAME_MULTIPLE));
		break;
	case MAPICON::ICN_PLAYER:
		path = _imgPath + "Map_player.bmp";
		_icon_off->init(path.c_str(), (int)(30 * GAME_MULTIPLE), (int)(40 * GAME_MULTIPLE));
		_icon_on = nullptr;
		break;
	default:
		break;
	}
	// Result
	if (_type == MAPICON::ICN_PLAYER)
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
	if (_type == MAPICON::ICN_PLAYER)
	{
		if (_icon_off != nullptr)
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
		if (_type == MAPICON::ICN_PLAYER)
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
		if (_fClick && _type != MAPICON::ICN_PLAYER)
		{
			if (is_player_atHere() == true)
			{
				_mapIcon_on = MAPICON::ICN_EMPTY;
			}
			else
			{
				_mapIcon_on = _type;
				_playerIcon_center = _icon_off->get_center();
			}
		}//if: 클릭하면 플레이어의 위치 업데이트, 플레이어가 여기 있으면 업데이트 X
	}//if: 마우스가 올라오면 아이콘에 노란불
	else
	{
		_fIcon = false;
	}
	if (_type == MAPICON::ICN_PLAYER)
	{
		update_playerIcon();
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
	if (_type == MAPICON::ICN_PLAYER)
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
