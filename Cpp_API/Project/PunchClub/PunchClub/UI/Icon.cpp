#include "stdafx.h"
#include "Icon.h"

void Icon::init_icons()
{
	// 이미지 불러오기
	_icon_btn_back = new Image;
	_hud_map = new Image;
	_league = new Image;
	_skillTree = new Image;
	string path;

	path = _imgPath + "Hud_btn_main_bg.bmp";
	_icon_btn_back->init(path.c_str(), (int)(41 * GAME_MULTIPLE), (int)(41 * GAME_MULTIPLE));

	path = _imgPath + "Icon_map.bmp";
	_hud_map->init(path.c_str(), (int)(35 * GAME_MULTIPLE), (int)(33 * GAME_MULTIPLE));
	path = _imgPath + "Icon_league.bmp";
	_league->init(path.c_str(), (int)(26 * GAME_MULTIPLE), (int)(29 * GAME_MULTIPLE));
	path = _imgPath + "Icon_skillTree.bmp";
	_skillTree->init(path.c_str(), (int)(37 * GAME_MULTIPLE), (int)(37 * GAME_MULTIPLE));
	// 위치 잡아주기
	_icon_center.x = (LONG)(_icon_btn_back->get_width() - _icon_btn_back->get_width() * 0.2);
	_icon_center.y = (LONG)(_icon_btn_back->get_height() - _icon_btn_back->get_height() * 0.2);
	POINT center = _icon_center;
	double blank = _icon_btn_back->get_height() * 0.2;
	// HUD
	_hud_map_back_rc = RectMakeCenter(center.x, center.y,
		_icon_btn_back->get_width(), _icon_btn_back->get_height());
	_hud_map_rc = RectMakeCenter(center.x, center.y,
		_hud_map->get_width(), _hud_map->get_height());
	// League
	center.y += (LONG)(_icon_btn_back->get_height() + blank);
	_league_back_rc = RectMakeCenter(center.x, center.y,
		_icon_btn_back->get_width(), _icon_btn_back->get_height());
	_league_rc = RectMakeCenter(center.x, center.y,
		_league->get_width(), _league->get_height());
	// SkillTree
	center.y += (LONG)(_icon_btn_back->get_height() + blank);
	_skillTree_back_rc = RectMakeCenter(center.x, center.y,
		_icon_btn_back->get_width(), _icon_btn_back->get_height());
	_skillTree_rc = RectMakeCenter(center.x, center.y,
		_skillTree->get_width(), _skillTree->get_height());
}
void Icon::draw_icons()
{
	_icon_btn_back->render(get_memDC(), _hud_map_back_rc.left, _hud_map_back_rc.top);
	_hud_map->render(get_memDC(), _hud_map_rc.left, _hud_map_rc.top);
	_icon_btn_back->render(get_memDC(), _league_back_rc.left, _league_back_rc.top);
	_league->render(get_memDC(), _league_rc.left, _league_rc.top);
	_icon_btn_back->render(get_memDC(), _skillTree_back_rc.left, _skillTree_back_rc.top);
	_skillTree->render(get_memDC(), _skillTree_rc.left, _skillTree_rc.top);
	if (_fDebug)
	{
		ColorRect(get_memDC(), _hud_map_back_rc);
		ColorRect(get_memDC(), _league_back_rc);
		ColorRect(get_memDC(), _skillTree_back_rc);
	}
}
void Icon::delete_icons()
{
	_icon_btn_back->release();
	//_hud_map->release();
	//_league->release();
	//_skillTree->release();
	_icon_btn_back = nullptr;
	//_hud_map = nullptr;
	//_league = nullptr;
	//_skillTree = nullptr;
}
//==========================================
//##			아이콘 클릭처리			  ##
//==========================================
void Icon::select_icons(ICON_TYPE type)
{
	switch (type)
	{
	case ICON_HUD_MAP:
		_scene_forChange = SCENE_HUD_MAP;
		break;
	case ICON_LEAGUE:
		break;
	case ICON_SKILLTREE:
		_scene_forChange = SCENE_SKILLTREE;
		break;
	default:
		break;
	}
}

HRESULT Icon::init()
{
	set_imgPath("UI/");
	init_icons();
	return S_OK;
}
void Icon::release()
{
	delete_icons();
}
void Icon::update()
{
	if (_fClick == true)
	{
		if (PtInRect(&_hud_map_back_rc, m_ptMouse)) { select_icons(ICON_HUD_MAP); }
		else if (PtInRect(&_league_back_rc, m_ptMouse)) { select_icons(ICON_LEAGUE); }
		else if (PtInRect(&_skillTree_back_rc, m_ptMouse)) { select_icons(ICON_SKILLTREE); }
		else { select_icons(ICON_EMPTY); }
	}//if: 클릭 했다면
}
void Icon::render()
{
	draw_icons();
}
Icon::Icon()
{
}
Icon::~Icon()
{
}
