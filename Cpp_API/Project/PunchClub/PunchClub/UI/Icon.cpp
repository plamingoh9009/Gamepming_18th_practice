#include "stdafx.h"
#include "Icon.h"

void Icon::init_icons()
{
	// 이미지 불러오기
	_hud = new Image;
	_league = new Image;
	_skillTree = new Image;
	string path;
	path = _imgPath + "HUD_Icon.bmp";
	_hud->init(path.c_str(), 82, 82);
	path = _imgPath + "League_Icon.bmp";
	_league->init(path.c_str(), 82, 82);
	path = _imgPath + "SkillTree_Icon.bmp";
	_skillTree->init(path.c_str(), 82, 82);
	// 위치 잡아주기
	_icon_center.x = (LONG)(WIN_HALF_W);
	_icon_center.y = (LONG)(WIN_HALF_H);
	POINT center = _icon_center;
	// HUD
	_hud_rc = RectMakeCenter(center.x, center.y,
		_hud->get_width(), _hud->get_height());

}
void Icon::draw_icons()
{
	_hud->render(get_memDC(), _hud_rc.left, _hud_rc.top);
	if (_fDebug)
	{
		ColorRect(get_memDC(), _hud_rc);
	}
}
void Icon::delete_icons()
{
	_hud->release();
	_league->release();
	_skillTree->release();
	_hud = nullptr;
	_league = nullptr;
	_skillTree = nullptr;
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
