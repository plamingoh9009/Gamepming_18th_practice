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
// ====================================
// ***		리그창 열었을 때			***
// ====================================
void InGameUI::update_league()
{
	_window_league->update();
	if (_window_league->is_closeWindow())
	{
		_icons->set_fLeague(false);
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

	_icons = new Icon;
	_icons->init();
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

	_icons->release();
	_icons = nullptr;
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
		_icons->update();
		if (_fRedButton) { run_red_button(); }
		if (_fInven_friger) { update_friger(); }
		if (_icons->get_fLeague()) { update_league(); }
		break;
	}
}
void InGameUI::render()
{
	switch (_type)
	{
	case UI_LEAGUE_WAIT:
		draw_gauges();
		break;
	default:
		_icons->render();
		_hud_back->render();
		if (_fRedButton) { _red_button->render(); }
		if (_fInven_friger) { _inven_friger->render(); }
		if (_icons->get_fLeague()) { _window_league->render(); }
		break;
	}
}
InGameUI::InGameUI()
{
}
InGameUI::~InGameUI()
{
}
