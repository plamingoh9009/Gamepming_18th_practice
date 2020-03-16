#include "stdafx.h"
#include "Icon.h"

void Icon::init_icons()
{
	string path;
	string title;
	string descr;
	// 이미지 불러오기
	_bg = new Image;
	path = _imgPath + "Hud_btn_main_bg.bmp";
	_bg->init(path.c_str(), (int)(41 * GAME_MULTIPLE), (int)(41 * GAME_MULTIPLE));
	_fg = new Image;
	_hint = new Hint;
	_hint->init();
	switch (_type)
	{
	case ICON::ICN_HUD_MAP:
		path = _imgPath + "Icon_map.bmp";
		_fg->init(path.c_str(), (int)(35 * GAME_MULTIPLE), (int)(33 * GAME_MULTIPLE));
		title = "시내 지도";
		descr = "클릭하면 시내 지도를 열어, 다른 장소로 이동할 수 있습니다.";
		_hint->set_texts(title, descr);
		break;
	case ICON::ICN_LEAGUE:
		path = _imgPath + "Icon_league.bmp";
		_fg->init(path.c_str(), (int)(26 * GAME_MULTIPLE), (int)(29 * GAME_MULTIPLE));
		title = "파이트 리그";
		descr = "리그, 대전 상태, 다음 시합에 관한 정보를 볼 수 있습니다.";
		_hint->set_texts(title, descr);
		break;
	case ICON::ICN_SKILLTREE:
		path = _imgPath + "Icon_skilltree.bmp";
		_fg->init(path.c_str(), (int)(37 * GAME_MULTIPLE), (int)(37 * GAME_MULTIPLE));
		title = "스킬 트리";
		descr = "스킬 목록을 열어 새로운 기술을 구입하려면, 이곳을 클릭하세요.";
		_hint->set_texts(title, descr);
		break;
	}
}
void Icon::draw_icons()
{
	Draw(_bg, get_memDC());
	Draw(_fg, get_memDC());
	if (_fDebug)
	{
		ColorRect(get_memDC(), _bg->get_rect());
	}
}
void Icon::delete_icons()
{
	Release(_bg);
	Release(_fg);
}
void Icon::draw_hint()
{
	Draw(_hint);
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
	//==========================================
	//##			아이콘 클릭처리			  ##
	//==========================================
	if (PtInRect(&_bg->get_rect(), m_ptMouse))
	{
		if (_fClick == true)
		{
			switch (_type)
			{
			case ICON::ICN_HUD_MAP:
				_scene_forChange = SCENE_HUD_MAP;
				break;
			case ICON::ICN_LEAGUE:
				_fLeague = true;
				break;
			case ICON::ICN_SKILLTREE:
				_scene_forChange = SCENE_SKILLTREE;
				break;
			default:
				_fLeague = false;
				break;
			}
			// 아이콘을 누를 때 플레이어 못움직이게 한다.
			if (_type != ICON::ICN_EMPTY) { _obj->set_fObjMove(false); }
		}//if: 클릭 했다면
		_hint->update();
		_fHint = true;
	}//if: 마우스가 지나가면 힌트를 띄운다.
	else
	{
		_fHint = false;
	}
}
void Icon::render()
{
	draw_icons();
}
Icon::Icon()
{
}
Icon::Icon(ICON::TYPE type)
{
	_type = type;
}
Icon::~Icon()
{
}

void Icon::set_center(POINT center)
{
	_bg->set_center(center);
	_fg->set_center(center);
	_hint->set_center(center);
}
