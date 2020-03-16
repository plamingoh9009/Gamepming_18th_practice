#include "stdafx.h"
#include "InGameUI.h"
#include "Object/Player.h"
// ====================================
// ***		씬에서 닫기 눌렀을 때		***
// ====================================
void InGameUI::run_red_button()
{
	if (_fClick == true && PtInRect(&_red_button->get_rc(), m_ptMouse))
	{
		_scene_forChange = SCENE_BACK;
		_fClick = false;
	}//if: 버튼을 눌렀다면 씬을 되돌린다.
}
HRESULT InGameUI::init_icons()
{
	HRESULT result;
	int result_cnt = 0;
	POINT center;
	double blank;
	if (_icn_hud_map == nullptr)
	{
		_icn_hud_map = new Icon(ICON::ICN_HUD_MAP);
		result = _icn_hud_map->init();
		result_cnt = (result == S_OK ? result_cnt : result_cnt++);
		// 위치 잡기
		center.x = (LONG)(_icn_hud_map->get_width() - _icn_hud_map->get_width() * 0.2);
		center.y = (LONG)(_icn_hud_map->get_height() - _icn_hud_map->get_height() * 0.2);
		_icn_hud_map->set_center(center);
	}
	blank = _icn_hud_map->get_height() * 0.2;
	if (_icn_league == nullptr)
	{
		_icn_league = new Icon(ICON::ICN_LEAGUE);
		result = _icn_league->init();
		result_cnt = (result == S_OK ? result_cnt : result_cnt++);
		// 위치 잡기
		center.x = (LONG)(_icn_hud_map->get_center().x);
		center.y = (LONG)(_icn_hud_map->get_center().y + _icn_league->get_height() + blank);
		_icn_league->set_center(center);
	}
	if (_icn_skilltree == nullptr)
	{
		_icn_skilltree = new Icon(ICON::ICN_SKILLTREE);
		result = _icn_skilltree->init();
		result_cnt = (result == S_OK ? result_cnt : result_cnt++);
		// 위치 잡기
		center.x = (LONG)(_icn_league->get_center().x);
		center.y = (LONG)(_icn_league->get_center().y + _icn_skilltree->get_height() + blank);
		_icn_skilltree->set_center(center);
	}
	result = (result_cnt == 0 ? S_OK : E_FAIL);
	return result;
}
void InGameUI::delete_icons()
{
	Release(_icn_hud_map);
	Release(_icn_league);
	Release(_icn_skilltree);
}
void InGameUI::draw_icons()
{
	Draw(_icn_hud_map);
	Draw(_icn_league);
	Draw(_icn_skilltree);
	// Hints
	if (_icn_hud_map->get_fHint() == true)
	{
		_icn_hud_map->draw_hint();
	}
	else if (_icn_league->get_fHint() == true)
	{
		_icn_league->draw_hint();
	}
	else if (_icn_skilltree->get_fHint() == true)
	{
		_icn_skilltree->draw_hint();
	}
}
void InGameUI::update_icons()
{
	_icn_hud_map->update();
	_icn_league->update();
	_icn_skilltree->update();
}
// ====================================
// ***		리그창 열었을 때			***
// ====================================
void InGameUI::update_league()
{
	_window_league->update();
	if (_window_league->is_closeWindow())
	{
		_icn_league->set_fLeague(false);
		_window_league->init(WINDOW::WND_LEAGUE);
	}
}
// ====================================
// ***		냉장고 열었을 때			***
// ====================================
void InGameUI::update_friger()
{
	_inven_friger->update();
	if (_inven_friger->is_closeWindow())
	{
		_fInven_friger = false;
		_inven_friger->init(WINDOW::WND_FRIGER);
	}
}

void InGameUI::init_gauges()
{
	_gauge = new Gauge;
	_gauge->init();
}
void InGameUI::draw_gauges()
{
	_gauge->render();
}
void InGameUI::update_gauges()
{
	_gauge->update();
}
void InGameUI::delete_gauges()
{
	_gauge->release();
}

HRESULT InGameUI::init()
{
	_obj = new Object;

	// Cursor
	if (_cursor == nullptr)
	{
		_cursor = new Cursor;
		_cursor->init();
	}
	// Icons
	init_icons();
	_hud_back = new HudBack;
	_hud_back->init();
	_red_button = new Button;
	_red_button->init(BUTTON::BTN_DELETE_RED);
	_red_button->set_pos_toRT_edge(
		RectMake(0, 0, WINSIZEX, WINSIZEY)
	);
	_fRedButton = false;
	_inven_friger = new Window;
	_inven_friger->init(WINDOW::WND_FRIGER);
	_fInven_friger = false;
	_window_league = new Window;
	_window_league->init(WINDOW::WND_LEAGUE);
	return S_OK;
}
HRESULT InGameUI::init(UI_TYPE type)
{
	switch (type)
	{
	case UI_LEAGUE_WAIT:
		init_gauges();
		_type = type;
		break;
	default:
		break;
	}
	return S_OK;
}
void InGameUI::release()
{
	_obj = nullptr;

	Release(_cursor);
	delete_icons();
	_hud_back->release();
	_hud_back = nullptr;
	_red_button->release();
	_inven_friger->release();
	_window_league->release();
	_red_button = nullptr;
	_inven_friger = nullptr;
	_window_league = nullptr;

	delete_gauges();
}
void InGameUI::update()
{
	switch (_type)
	{
	case UI_LEAGUE_WAIT:
		update_gauges();
		break;
	default:
		_hud_back->update();
		update_icons();
		if (_fRedButton) { run_red_button(); }
		if (_fInven_friger) { update_friger(); }
		if (_icn_league->get_fLeague()) { update_league(); }
		break;
	}
	_cursor->update();
}
void InGameUI::render()
{
	switch (_type)
	{
	case UI_LEAGUE_WAIT:
		draw_gauges();
		break;
	default:
		draw_icons();
		_hud_back->render();
		if (_fRedButton) { _red_button->render(); }
		if (_fInven_friger) { _inven_friger->render(); }
		if (_icn_league->get_fLeague()) { _window_league->render(); }
		break;
	}
	Draw(_cursor);
}
InGameUI::InGameUI()
{
}
InGameUI::~InGameUI()
{
}
