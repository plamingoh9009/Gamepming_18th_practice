#include "stdafx.h"
#include "HomeScene.h"
void HomeScene::init_furniture()
{
	set_imgPath("Home/Furniture/");
	string path;
	POINT center;
	// ============================
	// ***		주방 테이블		***
	// ============================
	path = _imgPath + "Kitchen_table.bmp";
	_kitchenTable = new Image;
	_kitchenTable->init(path.c_str(), (int)(142 * GAME_MULTIPLE), (int)(216 * GAME_MULTIPLE));
	_kitchenTable_center.x =
		(LONG)(WIN_HALF_W - _kitchenTable->get_width() * 0.57);
	_kitchenTable_center.y = 
		(LONG)(WIN_HALF_H - _kitchenTable->get_width() * 0.1);
	_kitchenTable_rc = RectMakeCenter(
		(int)(_kitchenTable_center.x),
		(int)(_kitchenTable_center.y),
		_kitchenTable->get_width(), _kitchenTable->get_height());
	// ============================
	// ***		냉장고			***
	// ============================
	path = _imgPath + "Refrigerator.bmp";
	_refrigerator = new Image;
	_refrigerator->init(path.c_str(), (int)(48 * GAME_MULTIPLE), (int)(87 * GAME_MULTIPLE));
	// 초기 위치
	_refrigerator_center.x = (LONG)(_kitchenTable_center.x -
		_refrigerator->get_width() * 0.86);
	_refrigerator_center.y = (LONG)(_kitchenTable_center.y +
		_refrigerator->get_width() * 0.1);
	_refrigerator_rc = RectMakeCenter(
		_refrigerator_center.x, _refrigerator_center.y,
		_refrigerator->get_width(), _refrigerator->get_height());
	// ============================
	// ***		스탠드			***
	// ============================
	path = _imgPath + "StandLight.bmp";
	_stand = new Image;
	_stand->init(path.c_str(), (int)(31 * GAME_MULTIPLE), (int)(78 * GAME_MULTIPLE));
	// 초기 위치
	_stand_center.x = (LONG)(WIN_HALF_W - _stand->get_width() * 0.015);
	_stand_center.y = (LONG)(_kitchenTable_center.y - _stand->get_width() * 0.1);
	_stand_rc = RectMakeCenter(_stand_center.x, _stand_center.y,
		_stand->get_width(), _stand->get_height());
	// ============================
	// ***			소파			***
	// ============================
	path = _imgPath + "Sofa.bmp";
	_sofa = new Image;
	_sofa->init(path.c_str(), (int)(111 * GAME_MULTIPLE), (int)(53 * GAME_MULTIPLE));
	_sofa_pos.x = (LONG)(_stand_rc.right - _stand->get_width() * 0.08);
	_sofa_pos.y = (LONG)(_stand_center.y - _stand->get_width() * 0.17);
	_sofa_rc = RectMake(_sofa_pos.x, _sofa_pos.y,
		_sofa->get_width(), _sofa->get_height());
	// ============================
	// ***		수조			***
	// ============================
	path = _imgPath + "FishTank.bmp";
	_fishTank = new Image;
	_fishTank->init(path.c_str(), (int)(205 * GAME_MULTIPLE), (int)(75 * GAME_MULTIPLE), 5, 1);
	_fishTank_pos.x = (LONG)(_sofa_rc.right - _fishTank->get_frameWidth() * 0.25);
	_fishTank_pos.y = (LONG)(_kitchenTable_center.y - _fishTank->get_frameWidth() * 0.43);
	_fishTank_rc = RectMake(_fishTank_pos.x, _fishTank_pos.y,
		_fishTank->get_frameWidth(), _fishTank->get_frameHeight());
	center.x = (LONG)((_fishTank_rc.left + _fishTank_rc.right) * 0.5);
	center.y = (LONG)((_fishTank_rc.top + _fishTank_rc.bottom) * 0.5);
	_fishTank_center = center;
	_fishTank->set_frameSection(1, 0, 4, 1);
	// 수조 뚜껑
	path = _imgPath + "FishTank_head.bmp";
	_fishTank_head = new Image;
	_fishTank_head->init(path.c_str(), (int)(36 * GAME_MULTIPLE), (int)(52 * GAME_MULTIPLE));
	center.x = (LONG)(_fishTank_center.x + _fishTank_head->get_width() * 0.05);
	center.y = (LONG)(_fishTank_center.y - _fishTank_head->get_width() * 0.43);
	_fishTank_head_rc = RectMakeCenter(center.x, center.y,
		_fishTank_head->get_width(), _fishTank_head->get_height());
	// ============================
	// ***			TV			***
	// ============================
	path = _imgPath + "TV.bmp";
	_tv = new Image;
	_tv->init(path.c_str(), (int)(147 * GAME_MULTIPLE), (int)(68 * GAME_MULTIPLE));
	_tv_pos.x = (LONG)(_sofa_rc.left + _stand->get_width() * 0.25);
	_tv_pos.y = (LONG)(_fishTank_rc.bottom - _stand->get_width() * 0.25);
	_tv_rc = RectMake(_tv_pos.x, _tv_pos.y, _tv->get_width(), _tv->get_height());
	center.x = (LONG)((_tv_rc.left + _tv_rc.right) * 0.5);
	center.y = (LONG)((_tv_rc.top + _tv_rc.bottom) * 0.5);
	_tv_center = center;
	// ============================
	// ***			선풍기		***
	// ============================
	path = _imgPath + "Fan.bmp";
	_fan = new Image;
	_fan->init(path.c_str(), (int)(183 * GAME_MULTIPLE), (int)(76 * GAME_MULTIPLE), 3, 1);
	center.x = (LONG)((_sofa_rc.left + _sofa_rc.right) * 0.5);
	center.y = (LONG)(_kitchenTable_center.y - _fan->get_frameHeight() * 0.92);
	_fan_center = center;
	_fan_rc = RectMakeCenter(center.x, center.y, _fan->get_frameWidth(), _fan->get_frameHeight());
	_fan->set_frameSection(1, 2, 0, 0.2f);
	// ============================
	// ***		테이블			***
	// ============================
	path = _imgPath + "Table.bmp";
	_table = new Image;
	_table->init(path.c_str(), (int)(142 * GAME_MULTIPLE), (int)(84 * GAME_MULTIPLE));
	_table_center.x = (LONG)(_stand_center.x + _stand->get_width() * 0.25);
	_table_center.y = (LONG)(WINSIZEY - _table->get_height() * 0.5);
	_table_rc = RectMakeCenter(_table_center.x, _table_center.y,
		_table->get_width(), _table->get_height());
	// ============================
	// ***		책꽂이			***
	// ============================
	path = _imgPath + "Bookshelf.bmp";
	_bookshelf = new Image;
	_bookshelf->init(path.c_str(), (int)(48 * GAME_MULTIPLE), (int)(175 * GAME_MULTIPLE));
	_bookshelf_pos.x = (LONG)(_tv_rc.right + _bookshelf->get_width() * 0.25);
	_bookshelf_pos.y = (LONG)(WINSIZEY - _bookshelf->get_height() - _bookshelf->get_width() * 0.1);
	_bookshelf_rc = RectMake(_bookshelf_pos.x, _bookshelf_pos.y,
		_bookshelf->get_width(), _bookshelf->get_height());
	center.x = (LONG)((_bookshelf_rc.left + _bookshelf_rc.right) * 0.5);
	center.y = (LONG)((_bookshelf_rc.top + _bookshelf_rc.bottom) * 0.5);
	_bookshelf_center = center;
	// ============================
	// ***			시계			***
	// ============================
	path = _imgPath + "Clock.bmp";
	_clock = new Image;
	_clock->init(path.c_str(), (int)(152 * GAME_MULTIPLE), (int)(43 * GAME_MULTIPLE), 8, 1);
	_clock_pos.x = (LONG)(_tv_rc.right - _clock->get_frameWidth() * 0.65);
	_clock_pos.y = (LONG)(_stand_rc.top - _clock->get_frameWidth() * 0.5);
	_clock_rc = RectMake(_clock_pos.x, _clock_pos.y,
		_clock->get_frameWidth(), _clock->get_frameHeight());
	center.x = (LONG)((_clock_rc.left + _clock_rc.right) * 0.5);
	center.y = (LONG)((_clock_rc.top + _clock_rc.bottom) * 0.5);
	_clock_center = center;
	_clock->set_frameSection(1, 0, 7, 0.15f);	//8프레임
	// ============================
	// ***			전화기		***
	// ============================
	path = _imgPath + "Phone.bmp";
	_phone = new Image;
	_phone->init(path.c_str(), (int)(40 * GAME_MULTIPLE), (int)(36 * GAME_MULTIPLE));
	center.x = (LONG)(_stand_center.x + _phone->get_height() * 0.1);
	center.y = (LONG)(_refrigerator_rc.bottom - _phone->get_height() * 0.1);
	_phone_rc = RectMakeCenter(center.x, center.y, _phone->get_width(), _phone->get_height());
	_phone_center = center;
}
void HomeScene::draw_furniture()
{
	_refrigerator->render(get_memDC(), _refrigerator_rc.left,
		_refrigerator_rc.top);
	_stand->render(get_memDC(), _stand_rc.left, _stand_rc.top);
	_phone->render(get_memDC(), _phone_rc.left, _phone_rc.top);
	_kitchenTable->render(get_memDC(), _kitchenTable_rc.left,
		_kitchenTable_rc.top);
	_fishTank->frameRender(get_memDC(), _fishTank_rc.left, _fishTank_rc.top);
	_fishTank_head->render(get_memDC(), _fishTank_head_rc.left, _fishTank_head_rc.top);
	_sofa->render(get_memDC(), _sofa_rc.left, _sofa_rc.top);
	_tv->render(get_memDC(), _tv_rc.left, _tv_rc.top);
	_fan->frameRender(get_memDC(), _fan_rc.left, _fan_rc.top);
	_table->render(get_memDC(), _table_rc.left, _table_rc.top);
	_bookshelf->render(get_memDC(), _bookshelf_rc.left, _bookshelf_rc.top);
	_clock->frameRender(get_memDC(), _clock_rc.left, _clock_rc.top);
	if (_fDebug)
	{
		ColorRect(get_memDC(), _kitchenTable_rc, RGB(83, 91, 90));
		ColorRect(get_memDC(), _refrigerator_rc, RGB(193, 215, 222));
		ColorRect(get_memDC(), _stand_rc, RGB(255, 245, 112));
		ColorRect(get_memDC(), _fishTank_rc, RGB(205, 229, 214));
		ColorRect(get_memDC(), _fishTank_head_rc, RGB(71, 72, 73));
		ColorRect(get_memDC(), _sofa_rc, RGB(170, 114, 97));
		ColorRect(get_memDC(), _tv_rc, RGB(149, 113, 73));
		ColorRect(get_memDC(), _fan_rc, RGB(119, 128, 126));
		ColorRect(get_memDC(), _table_rc, RGB(145, 108, 70));
		ColorRect(get_memDC(), _bookshelf_rc, RGB(180, 146, 104));
		ColorRect(get_memDC(), _clock_rc, RGB(116, 46, 25));
		ColorRect(get_memDC(), _phone_rc);
	}
}
void HomeScene::delete_furniture()
{
	_kitchenTable->release();
	_refrigerator->release();
	_stand->release();
	_fishTank->release();
	_fishTank_head->release();
	_sofa->release();
	_tv->release();
	_fan->release();
	_table->release();
	_kitchenTable = nullptr;
	_refrigerator = nullptr;
	_stand = nullptr;
	_fishTank = nullptr;
	_fishTank_head = nullptr;
	_sofa = nullptr;
	_tv = nullptr;
	_fan = nullptr;
	_table = nullptr;
}
HRESULT HomeScene::init()
{
	add_currentScene_toList(SCENE_HOME);
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
	// 노드에서 업데이트 받아온다.
	update_checkDebugMode();
	update_checkClicked();
	// 프레임 이미지 업데이트
	_fishTank->frameUpdate();
	_fan->frameUpdate(false, true);
	_clock->frameUpdate();
	INGAME_UI->update();
	// 항상 마지막에 씬을 바꾼다.
	if (_scene_forChange != SCENE_EMPTY) { change_currentScene(); }
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
