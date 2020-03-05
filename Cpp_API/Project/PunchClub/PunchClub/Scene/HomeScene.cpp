#include "stdafx.h"
#include "HomeScene.h"
void HomeScene::update_objectSelected()
{
	done_action();
	// 냉장고
	if (PtInRect(&_friger_rc, m_ptMouse)) 
	{ 
		_fFriger = true;
		if (_fClick == true) { INGAME_UI->set_fInven_friger(true); }
	}
	else { _fFriger = false; }
	// 소파
	if (PtInRect(&_sofa_rc, m_ptMouse))
	{
		_fSofa = true;
		if (_fClick == true && _fSleep == false) { _fSleep = true; }
	}
	else { _fSofa = false; }
	
	// TV
	if (PtInRect(&_tv_rc, m_ptMouse))
	{
		_fTv = true;
		if (_fClick == true && _fWatch == false) { _fWatch = true; }
	}
	else { _fTv = false; }

	// 플레이어 행동
	if (_fSleep == true)
	{
		_sofa_sleep->frameUpdate(false);
		PLAYER->sleep_toSofa();
	}
	else if (_fWatch == true)
	{
		_tv_watch->frameUpdate(false);
		PLAYER->watch_tv();
	}
}
void HomeScene::done_action()
{
	// 행동 끝내기
	if (_fClick == true && _fSleep == true)
	{
		_fSleep = false;
		_sofa_sleep->set_frameX(0);
	}
	else if (_fClick == true && _fWatch == true)
	{
		_fWatch = false;
		_tv_watch->set_frameX(0);
	}
}
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
	_friger = new Image;
	_friger->init(path.c_str(), (int)(48 * GAME_MULTIPLE), (int)(87 * GAME_MULTIPLE));
	// 초기 위치
	_friger_center.x = (LONG)(_kitchenTable_center.x -
		_friger->get_width() * 0.86);
	_friger_center.y = (LONG)(_kitchenTable_center.y +
		_friger->get_width() * 0.1);
	_friger_rc = RectMakeCenter(
		_friger_center.x, _friger_center.y,
		_friger->get_width(), _friger->get_height());
	// 냉장고 선택 이미지
	path = _imgPath + "Refrigerator_select.bmp";
	_friger_select = new Image;
	_friger_select->init(path.c_str(), (int)(48 * GAME_MULTIPLE), (int)(87 * GAME_MULTIPLE));
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
	_sofa_pos.y = (LONG)(_stand_center.y - _stand->get_width() * 0.1);
	_sofa_rc = RectMake(_sofa_pos.x, _sofa_pos.y,
		_sofa->get_width(), _sofa->get_height());
	_sofa_center.x = (LONG)((_sofa_rc.left + _sofa_rc.right) * 0.5);
	_sofa_center.y = (LONG)((_sofa_rc.top + _sofa_rc.bottom) * 0.5);
	path = _imgPath + "Sofa_select.bmp";
	_sofa_select = new Image;
	_sofa_select->init(path.c_str(), (int)(111 * GAME_MULTIPLE), (int)(53 * GAME_MULTIPLE));
	// 잠자는 이미지
	path = _imgPath + "Sofa_sleep.bmp";
	_sofa_sleep = new Image;
	_sofa_sleep->init(path.c_str(), (int)(156 * GAME_MULTIPLE), (int)(57 * GAME_MULTIPLE), 2, 1);
	_sofa_sleep->set_frameSection(1, 0, 1, 1.0f);
	center.x = (LONG)(_sofa_center.x - _sofa_sleep->get_frameWidth() * 0.1);
	center.y = (LONG)(_sofa_center.y + _sofa_sleep->get_frameHeight() * 0.2);
	_sofa_sleep_rc = RectMakeCenter(center.x, center.y,
		_sofa_sleep->get_frameWidth(), _sofa_sleep->get_frameHeight());
	// ============================
	// ***		수조			***
	// ============================
	path = _imgPath + "Aquarium.bmp";
	_aquarium = new Image;
	_aquarium->init(path.c_str(), (int)(230 * GAME_MULTIPLE), (int)(78 * GAME_MULTIPLE), 5, 1);
	_aquarium_pos.x = (LONG)(_sofa_rc.right - _aquarium->get_frameWidth() * 0.25);
	_aquarium_pos.y = (LONG)(_kitchenTable_center.y - _aquarium->get_frameWidth() * 0.35);
	_aquarium_rc = RectMake(_aquarium_pos.x, _aquarium_pos.y,
		_aquarium->get_frameWidth(), _aquarium->get_frameHeight());
	center.x = (LONG)((_aquarium_rc.left + _aquarium_rc.right) * 0.5);
	center.y = (LONG)((_aquarium_rc.top + _aquarium_rc.bottom) * 0.5);
	_aquarium_center = center;
	_aquarium->set_frameSection(1, 0, 4, 0.1f);
	// 수조 뚜껑
	path = _imgPath + "Aquarium_fg.bmp";
	_aquarium_fg = new Image;
	_aquarium_fg->init(path.c_str(), (int)(36 * GAME_MULTIPLE), (int)(52 * GAME_MULTIPLE));
	center.x = (LONG)(_aquarium_center.x + _aquarium_fg->get_width() * 0.05);
	center.y = (LONG)(_aquarium_center.y - _aquarium_fg->get_width() * 0.43);
	_aquarium_fg_rc = RectMakeCenter(center.x, center.y,
		_aquarium_fg->get_width(), _aquarium_fg->get_height());
	// ============================
	// ***			TV			***
	// ============================
	path = _imgPath + "TV.bmp";
	_tv = new Image;
	_tv->init(path.c_str(), (int)(147 * GAME_MULTIPLE), (int)(68 * GAME_MULTIPLE));
	_tv_pos.x = (LONG)(_sofa_rc.left + _stand->get_width() * 0.25);
	_tv_pos.y = (LONG)(_aquarium_rc.bottom - _stand->get_width() * 0.37);
	_tv_rc = RectMake(_tv_pos.x, _tv_pos.y, _tv->get_width(), _tv->get_height());
	center.x = (LONG)((_tv_rc.left + _tv_rc.right) * 0.5);
	center.y = (LONG)((_tv_rc.top + _tv_rc.bottom) * 0.5);
	_tv_center = center;
	path = _imgPath + "TV_select.bmp";
	_tv_select = new Image;
	_tv_select->init(path.c_str(), (int)(147 * GAME_MULTIPLE), (int)(68 * GAME_MULTIPLE));
	// TV 보는 이미지
	path = _imgPath + "TV_watch.bmp";
	_tv_watch = new Image;
	_tv_watch->init(path.c_str(), (int)(462 * GAME_MULTIPLE), (int)(76 * GAME_MULTIPLE), 3, 1);
	_tv_watch->set_frameSection(1, 0, 2, 0.3f);
	center.x = (LONG)(_tv_center.x + _tv_watch->get_frameWidth() * 0.009);
	center.y = (LONG)(_tv_center.y - _tv_watch->get_frameHeight() * 0.045);
	_tv_watch_rc = RectMakeCenter(center.x, center.y,
		_tv_watch->get_frameWidth(), _tv_watch->get_frameHeight());
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
	_fan->set_frameSection(1, 2, 0, 0.09f);
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
	_clock->set_frameSection(1, 0, 7, 0.09f);	//8프레임
	// ============================
	// ***			전화기		***
	// ============================
	path = _imgPath + "Phone.bmp";
	_phone = new Image;
	_phone->init(path.c_str(), (int)(40 * GAME_MULTIPLE), (int)(36 * GAME_MULTIPLE));
	center.x = (LONG)(_stand_center.x + _phone->get_height() * 0.1);
	center.y = (LONG)(_friger_rc.bottom - _phone->get_height() * 0.1);
	_phone_rc = RectMakeCenter(center.x, center.y, _phone->get_width(), _phone->get_height());
	_phone_center = center;
}
void HomeScene::draw_furniture()
{
	if (_fFriger == true) { _friger_select->render(get_memDC(), _friger_rc.left, _friger_rc.top); }
	else { _friger->render(get_memDC(), _friger_rc.left, _friger_rc.top); }
	_stand->render(get_memDC(), _stand_rc.left, _stand_rc.top);
	_phone->render(get_memDC(), _phone_rc.left, _phone_rc.top);
	_kitchenTable->render(get_memDC(), _kitchenTable_rc.left,
		_kitchenTable_rc.top);
	_aquarium->frameRender(get_memDC(), _aquarium_rc.left, _aquarium_rc.top);
	_aquarium_fg->render(get_memDC(), _aquarium_fg_rc.left, _aquarium_fg_rc.top);
	// 소파 렌더
	if (_fSofa == true) 
	{ 
		_sofa_select->render(get_memDC(), _sofa_rc.left, _sofa_rc.top); 
		if(_fSleep == true)
		{ 
			_sofa_sleep->frameRender(get_memDC(), _sofa_sleep_rc.left, _sofa_sleep_rc.top); 
		}
	}
	else 
	{ 
		_sofa->render(get_memDC(), _sofa_rc.left, _sofa_rc.top);
		if (_fSleep == true)
		{
			_sofa_sleep->frameRender(get_memDC(), _sofa_sleep_rc.left, _sofa_sleep_rc.top);
		}
	}
	// TV 렌더
	if (_fTv == true) 
	{ 
		_tv_select->render(get_memDC(), _tv_rc.left, _tv_rc.top);
		if (_fWatch == true)
		{
			_tv_watch->frameRender(get_memDC(), _tv_watch_rc.left, _tv_watch_rc.top);
		}
	}
	else 
	{ 
		_tv->render(get_memDC(), _tv_rc.left, _tv_rc.top);
		if (_fWatch == true)
		{
			_tv_watch->frameRender(get_memDC(), _tv_watch_rc.left, _tv_watch_rc.top);
		}
	}
	_fan->frameRender(get_memDC(), _fan_rc.left, _fan_rc.top);
	_table->render(get_memDC(), _table_rc.left, _table_rc.top);
	_bookshelf->render(get_memDC(), _bookshelf_rc.left, _bookshelf_rc.top);
	_clock->frameRender(get_memDC(), _clock_rc.left, _clock_rc.top);
	if (_fDebug) { draw_rects(); }
}
void HomeScene::delete_furniture()
{
	_kitchenTable->release();
	_friger->release();
	_friger_select->release();
	_stand->release();
	_aquarium->release();
	_aquarium_fg->release();
	_sofa->release();
	_sofa_select->release();
	_tv->release();
	_tv_select->release();
	_fan->release();
	_table->release();
	_kitchenTable = nullptr;
	_friger = nullptr;
	_friger_select = nullptr;
	_stand = nullptr;
	_aquarium = nullptr;
	_aquarium_fg = nullptr;
	_sofa = nullptr;
	_sofa_select = nullptr;
	_tv = nullptr;
	_tv_select = nullptr;
	_fan = nullptr;
	_table = nullptr;
}
void HomeScene::draw_rects()
{
	ColorRect(get_memDC(), _kitchenTable_rc, RGB(83, 91, 90));
	ColorRect(get_memDC(), _friger_rc, RGB(193, 215, 222));
	ColorRect(get_memDC(), _stand_rc, RGB(255, 245, 112));
	ColorRect(get_memDC(), _aquarium_rc, RGB(205, 229, 214));
	ColorRect(get_memDC(), _aquarium_fg_rc, RGB(71, 72, 73));
	ColorRect(get_memDC(), _sofa_rc, RGB(170, 114, 97));
	ColorRect(get_memDC(), _tv_rc, RGB(149, 113, 73));
	ColorRect(get_memDC(), _fan_rc, RGB(119, 128, 126));
	ColorRect(get_memDC(), _table_rc, RGB(145, 108, 70));
	ColorRect(get_memDC(), _bookshelf_rc, RGB(180, 146, 104));
	ColorRect(get_memDC(), _clock_rc, RGB(116, 46, 25));
	ColorRect(get_memDC(), _phone_rc);
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
	// Player
	PLAYER->init();
	// UI
	INGAME_UI->init();
	return S_OK;
}
void HomeScene::release()
{
	_bg->release();
	_bg = nullptr;
	delete_furniture();
}
void HomeScene::update()
{
	update_scene();		// 모든 씬에서 공통으로 업데이트 해야 하는 것을 함수화
	update_objectSelected();
	// ========================================
	// ***		프레임 이미지 업데이트			***
	// ========================================
	_aquarium->frameUpdate();
	_fan->frameUpdate(false, true);
	_clock->frameUpdate();
	// 
	if(_fSleep == true) {}
	else if(_fWatch == true) {}
	else { PLAYER->update(); }
	
	INGAME_UI->update();
	change_scene();	// 항상 마지막에 씬을 바꾼다.
}
void HomeScene::render()
{
	_bg->render(get_memDC());
	draw_furniture();
	if(_fSleep == true) {}
	else if(_fWatch == true) {}
	else { PLAYER->render(); }
	
	INGAME_UI->render();
}
HomeScene::HomeScene()
{
}
HomeScene::~HomeScene()
{
}
