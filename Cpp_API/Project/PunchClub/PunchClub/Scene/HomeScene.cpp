#include "stdafx.h"
#include "HomeScene.h"
void HomeScene::init_furniture()
{
	set_imgPath("Home/Furniture/");
	string path;
	// ============================
	// ***		주방 테이블		***
	// ============================
	path = _imgPath + "Kitchen_table.bmp";
	_kitchenTable = new Image;
	_kitchenTable->init(path.c_str(), 240, 365);
	_kitchenTable_center.x = 
		(LONG)(WIN_HALF_W - _kitchenTable->get_width() * 0.5 - 17);
	_kitchenTable_center.y = (LONG)(WIN_HALF_H - 25);
	_kitchenTable_rc = RectMakeCenter(
		(int)(_kitchenTable_center.x), 
		(int)(_kitchenTable_center.y), 
		_kitchenTable->get_width(), _kitchenTable->get_height());
	// ============================
	// ***		냉장고			***
	// ============================
	path = _imgPath + "Refrigerator.bmp";
	_refrigerator = new Image;
	_refrigerator->init(path.c_str(), 81, 147);
	// 초기 위치
	_refrigerator_center.x = (LONG)(_kitchenTable_center.x - 
		_refrigerator->get_width() * 0.9 + 2);
	_refrigerator_center.y = (LONG)(_kitchenTable_center.y + 6);
	_refrigerator_rc = RectMakeCenter(
		_refrigerator_center.x, _refrigerator_center.y,
		_refrigerator->get_width(), _refrigerator->get_height());
}
void HomeScene::draw_furniture()
{
	_refrigerator->render(get_memDC(), _refrigerator_rc.left,
		_refrigerator_rc.top);
	_kitchenTable->render(get_memDC(), _kitchenTable_rc.left,
		_kitchenTable_rc.top);
	if (_fDebug)
	{
		ColorRect(get_memDC(), _kitchenTable_rc);
		ColorRect(get_memDC(), _refrigerator_rc);
	}
}
void HomeScene::delete_furniture()
{
	_kitchenTable->release();
	_kitchenTable = nullptr;
}
HRESULT HomeScene::init()
{
	set_imgPath("Home/");
	string path = _imgPath + "Kitchen_bg.bmp";
	_bg = new Image;
	_bg->init(path.c_str(), (int)(682 * GAME_MULTIPLE),
		(int)(383 * GAME_MULTIPLE));
	// 배치할 가구 초기화
	init_furniture();
	// UI
	INGAME_UI->init();
	return S_OK;
}
void HomeScene::release()
{
	_bg->release();
	_bg = nullptr;
	delete_furniture();
	INGAME_UI->release();
}
void HomeScene::update()
{
	update_checkDebugMode();
	INGAME_UI->update();
}
void HomeScene::render()
{
	_bg->render(get_memDC());
	draw_furniture();
	INGAME_UI->render();
}
HomeScene::HomeScene()
{
}
HomeScene::~HomeScene()
{
}
