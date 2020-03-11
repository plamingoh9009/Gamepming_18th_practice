#include "stdafx.h"
#include "Window.h"

HRESULT Window::init_window_bg(WINDOW::TYPE type)
{
	_type = type;
	string path;
	POINT center, pos;
	HRESULT result;
	int result_cnt = 0;
	switch (type)
	{
	case WINDOW::WINDOW_NONE:
	case WINDOW::WINDOW_SHOP:
	case WINDOW::WINDOW_FRIGER:
	case WINDOW::WINDOW_LEAGUE:
		// Background Image
		path = _imgPath + "Window_back.bmp";
		_bg = new Image;
		result = _bg->init(path.c_str(), (int)(425 * GAME_MULTIPLE), (int)(300 * GAME_MULTIPLE));
		result_cnt = (result == S_OK ? result_cnt : result_cnt++);
		center.x = (LONG)(WIN_HALF_W);
		center.y = (LONG)(WIN_HALF_H + _bg->get_height() * 0.07);
		_bg->set_center(center);
		// Red button Class
		_red_button = new Button();
		result = _red_button->init(BTN_RED, _bg->get_rect().right, _bg->get_rect().top);
		result_cnt = (result == S_OK ? result_cnt : result_cnt++);
		// 라인을 그리는 기준
		path = _imgPath + "Locked_back.bmp";
		_locked_back = new Image;
		result = _locked_back->init(path.c_str(),
			(int)(419 * GAME_MULTIPLE), (int)(234 * GAME_MULTIPLE));
		result_cnt = (result == S_OK ? result_cnt : result_cnt++);
		pos.x = (LONG)(_bg->getX() + 6);
		pos.y = (LONG)(_bg->getY() + _bg->get_height() * 0.2 + 4);
		_locked_back->set_pos(pos);
		break;
	case WINDOW::WINDOW_BUS:
		// Background Image
		path = _imgPath + "Window_back.bmp";
		_bg = new Image;
		result = _bg->init(path.c_str(), (int)(425 * GAME_MULTIPLE), (int)(300 * GAME_MULTIPLE));
		result_cnt = (result == S_OK ? result_cnt : result_cnt++);
		center.x = (LONG)(WIN_HALF_W);
		center.y = (LONG)(WIN_HALF_H + _bg->get_height() * 0.07);
		_bg->set_center(center);
		// Red button Class
		_red_button = new Button();
		result = _red_button->init(BTN_RED, _bg->get_rect().right, _bg->get_rect().top);
		result_cnt = (result == S_OK ? result_cnt : result_cnt++);
		break;
	}
	result = (result_cnt == 0 ? S_OK : E_FAIL);
	return result;
}
void Window::delete_window_bg()
{
	Release(_bg);
	Release(_red_button);
	Release(_locked_back);
}
void Window::draw_window_bg()
{
	Draw(_bg, get_memDC());
	Draw(_red_button);
}

void Window::init_inventory()
{
	string path;
	_fg = new Image;
	switch (_type)
	{
	case WINDOW::WINDOW_FRIGER:
		path = _imgPath + "Hdr_friger.bmp";
		_fg->init(path.c_str(), (int)(79 * GAME_MULTIPLE), (int)(40 * GAME_MULTIPLE));
		// 글씨
		_fg_title = "냉장고";
		_fg_descr = "당신이 산 식료품이 보관됩니다. 식료품을 슈퍼에서 구입할 수 있습니다.";
		break;
	case WINDOW::WINDOW_SHOP:
		path = _imgPath + "Hdr_shop.bmp";
		_fg->init(path.c_str(), (int)(89 * GAME_MULTIPLE), (int)(47 * GAME_MULTIPLE));
		// 글씨
		_fg_title = "슈퍼";
		_fg_descr = "식료품 및 에너지 드링크를 구입할 수 있습니다.";
		break;
	}
	_fg->set_rect(
		RectMake(
		(int)(_bg->getX()), (int)(_bg->getY() + 10),
			(int)(_bg->get_width() * 0.25), (int)(_bg->get_height() * 0.2)
		)
	);
	_fg_title_pos.x = _fg->get_rect().right;
	_fg_title_pos.y = _fg->get_rect().top + 20;
	_fg_descr_pos.x = _fg_title_pos.x;
	_fg_descr_pos.y = _fg_title_pos.y + 40;
	_fg->set_rect(
		RectMakeCenter(
			_fg->get_center().x, _fg->get_center().y,
			_fg->get_width(), _fg->get_height()
		)
	);
	// 라인 초기화
	_line_pos.x = (LONG)(_locked_back->getX());
	_line_pos.y = (LONG)(_locked_back->getY());
}
void Window::draw_inventory()
{
	// Line을 그린다.
	ColorLine(get_memDC(), _line_pos.x, (int)(_line_pos.y - 2),
		_locked_back->get_rect().right, (int)(_line_pos.y - 2),
		1, RGB(94, 84, 64));
	ColorLine(get_memDC(), _line_pos.x, _line_pos.y,
		_locked_back->get_rect().right - 1, _line_pos.y,
		2, RGB(78, 68, 50));
	_locked_back->alphaRender(get_memDC(), 32);
	// fg 이미지를 그린다.
	Draw(_fg, get_memDC());
	FontTextShadow(get_memDC(), _fg_title_pos.x, _fg_title_pos.y, _fg_title.c_str(),
		"휴먼매직체", 35, RGB(254, 254, 254));
	FontTextOut(get_memDC(), _fg_descr_pos.x, _fg_descr_pos.y, _fg_descr.c_str(),
		"휴먼편지체", 25, RGB(58, 47, 24));
	if (_fDebug) { ColorRect(get_memDC(), _fg->get_rect()); }
}
void Window::delete_inventory()
{
	Release(_fg);
}

void Window::init_league()
{
	set_imgPath("UI/Window/League/");
	string path;
	POINT pos, center;
	path = _imgPath + "League_fg.bmp";
	// 라인 초기화
	_line_pos.x = (LONG)(_locked_back->get_rect().left);
	_line_pos.y = (LONG)((_bg->get_rect().top + _locked_back->get_rect().top) * 0.5);
	_line_pos_ver.x = (LONG)((_bg->get_rect().left + _bg->get_rect().right) * 0.45);
	_line_pos_ver.y = (LONG)(_bg->get_rect().bottom - 8);
	// 리그 아저씨 이미지
	_fg = new Image;
	_fg->init(path.c_str(), (int)(159 * GAME_MULTIPLE), (int)(180 * GAME_MULTIPLE));
	pos.x = (LONG)(_line_pos.x);
	pos.y = (LONG)(_line_pos.y);
	_fg->set_rect(
		RectMake(pos.x, pos.y,
		(int)(_line_pos_ver.x - _line_pos.x),
			(int)(_line_pos_ver.y - _line_pos.y)
		)
	);
	center.x = (LONG)((_fg->get_rect().left + _fg->get_rect().right) * 0.5);
	center.y = (LONG)((_fg->get_rect().top + _fg->get_rect().bottom) * 0.525);
	_fg->set_center(center);
	// 리그 글씨
	_fg_title = "리그";
	_fg_title_pos.x = (LONG)(_bg->get_center().x);
	_fg_title_pos.y = (LONG)((_line_pos.y + _bg->get_rect().top) * 0.46);
	// 리그 슬롯을 위한 렉트
	init_league_slots();
}
void Window::draw_league()
{
	// 가로 Line을 그린다.
	ColorLine(get_memDC(), _locked_back->get_rect().left, (int)(_line_pos.y - 2),
		_locked_back->get_rect().right, (int)(_line_pos.y - 2),
		1, RGB(94, 84, 64));
	ColorLine(get_memDC(), _locked_back->get_rect().left, _line_pos.y,
		_locked_back->get_rect().right - 1, _line_pos.y,
		2, RGB(78, 68, 50));
	// 세로 Line을 잡는다.
	ColorLine(get_memDC(), _line_pos_ver.x, _line_pos.y,
		_line_pos_ver.x, _line_pos_ver.y, 2, RGB(94, 84, 64));
	// 리그 아저씨를 그린다
	Draw(_fg, get_memDC());
	// 리그 타이틀을 띄운다.
	FontTextShadow(get_memDC(), _fg_title_pos.x, _fg_title_pos.y, _fg_title.c_str(),
		"휴먼매직체", 35, RGB(254, 254, 254));
	draw_league_slots();
	// 디버그 모드
	if (_fDebug)
	{
		ColorRect(get_memDC(), _fg->get_rect());
	}
}
void Window::update_league()
{
	if (PtInRect(&_league_slot[0].btn_show_rc, m_ptMouse))
	{
		_fClose = true;
		_fClickLock = false;
		_scene_forChange = SCENE_LEAGUE_WAIT;
	}
}
void Window::delete_league()
{
	Release(_fg);
	delete_league_slots();
}
void Window::init_league_slots()
{
	string path;
	POINT pos;
	int width = (int)(_bg->get_rect().right - _line_pos_ver.x - 6);
	int height = (int)(_bg->get_rect().bottom - _line_pos.y - 6);
	_league_slots_rc = RectMake(_line_pos_ver.x + 2, _line_pos.y, width, height);
	height = (int)(height / 3);
	for (int i = 0; i < 3; i++)
	{
		_league_slot[i].back_rc = RectMake(
			_league_slots_rc.left,
			(int)(_league_slots_rc.top + i * height),
			width, height);
		_league_slot[i].slot_center.x = (LONG)((_league_slot[i].back_rc.left + _league_slot[i].back_rc.right) * 0.5);
		_league_slot[i].slot_center.y = (LONG)((_league_slot[i].back_rc.top + _league_slot[i].back_rc.bottom) * 0.5);
		_league_slot[i].back = new Image;
		path = _imgPath + "League_slot.bmp";
		_league_slot[i].back->init(path.c_str(),
			(int)(243 * GAME_MULTIPLE), (int)(88 * GAME_MULTIPLE));
		if (i == 0)
		{
			path = _imgPath + "League_icon.bmp";
			_league_slot[i].icon = new Image;
			_league_slot[i].icon->init(path.c_str(),
				(int)(27 * GAME_MULTIPLE), (int)(42 * GAME_MULTIPLE));
			path = _imgPath + "League_icon_bg.bmp";
			_league_slot[i].icon_back = new Image;
			_league_slot[i].icon_back->init(path.c_str(),
				(int)(61 * GAME_MULTIPLE), (int)(61 * GAME_MULTIPLE));
			pos.x = (LONG)(_league_slot[i].back_rc.left + 10);
			pos.y = (LONG)(_league_slot[i].back_rc.bottom -
				_league_slot[i].icon_back->get_height() * 1.05);
			_league_slot[i].icon_back_rc = RectMake(pos.x, pos.y,
				_league_slot[i].icon_back->get_width(),
				_league_slot[i].icon_back->get_height());
			_league_slot[i].icon_center.x = (LONG)((_league_slot[i].icon_back_rc.left +
				_league_slot[i].icon_back_rc.right) * 0.5);
			_league_slot[i].icon_center.y = (LONG)((_league_slot[i].icon_back_rc.top +
				_league_slot[i].icon_back_rc.bottom) * 0.5);
			_league_slot[i].icon_rc = RectMakeCenter(
				_league_slot[i].icon_center.x,
				_league_slot[i].icon_center.y,
				_league_slot[i].icon->get_width(), _league_slot[i].icon->get_height());
			// 슬롯의 텍스트를 정하는 부분
			_league_slot[i].title = "루키 리그";
			_league_slot[i].desc_type[0] = "종류: ";
			_league_slot[i].desc_type[1] = "스코어리그";
			_league_slot[i].desc_rank[0] = "현재 순위: ";
			_league_slot[i].desc_rank[1] = "12";
			_league_slot[i].desc_next[0] = "다음 싸움: ";
			_league_slot[i].desc_next[1] = "2 일 후";
			_league_slot[i].title_pos.x = (LONG)(_league_slot[i].slot_center.x - 30);
			_league_slot[i].title_pos.y = (LONG)(_league_slot[i].back_rc.top + 10);
			_league_slot[i].desc_pos.x = (LONG)(_league_slot[i].icon_back_rc.right + 5);
			_league_slot[i].desc_pos.y = (LONG)(_league_slot[i].icon_back_rc.top + 5);
			// 버튼
			path = _imgPath + "Btn_show.bmp";
			_league_slot[i].btn_show = new Image;
			_league_slot[i].btn_show->init(path.c_str(),
				(int)(57 * GAME_MULTIPLE), (int)(20 * GAME_MULTIPLE));
			path = _imgPath + "Icon_show.bmp";
			_league_slot[i].icon_show = new Image;
			_league_slot[i].icon_show->init(path.c_str(),
				(int)(24 * GAME_MULTIPLE), (int)(24 * GAME_MULTIPLE));
			// 버튼 위치
			pos.x = (LONG)(_league_slot[i].back_rc.right -
				_league_slot[i].btn_show->get_width() * 1.075);
			pos.y = (LONG)(_league_slot[i].back_rc.bottom -
				_league_slot[i].btn_show->get_height() * 1.15);
			_league_slot[i].btn_show_rc = RectMake(pos.x, pos.y,
				_league_slot[i].btn_show->get_width(),
				_league_slot[i].btn_show->get_height());
			_league_slot[i].btn_show_center.x = (LONG)(
				(_league_slot[i].btn_show_rc.left + _league_slot[i].btn_show_rc.right) * 0.5);
			_league_slot[i].btn_show_center.y = (LONG)(
				(_league_slot[i].btn_show_rc.top + _league_slot[i].btn_show_rc.bottom) * 0.5);
			_league_slot[i].icon_show_rc = RectMakeCenter(
				_league_slot[i].btn_show_center.x,
				_league_slot[i].btn_show_center.y,
				_league_slot[i].icon_show->get_width(),
				_league_slot[i].icon_show->get_height());
		}
		else
		{
			path = _imgPath + "League_lock_back2.bmp";
			_league_slot[i].lock_back = new Image;
			_league_slot[i].lock_back->init(path.c_str(),
				(int)(241 * GAME_MULTIPLE), (int)(86 * GAME_MULTIPLE));
			_league_slot[i].lock_back_rc = RectMakeCenter(
				_league_slot[i].slot_center.x, _league_slot[i].slot_center.y,
				_league_slot[i].lock_back->get_width(), _league_slot[i].lock_back->get_height());
			path = _imgPath + "League_lock.bmp";
			_league_slot[i].lock = new Image;
			_league_slot[i].lock->init(path.c_str(),
				(int)(45 * GAME_MULTIPLE), (int)(52 * GAME_MULTIPLE));
			_league_slot[i].lock_rc = RectMakeCenter(
				_league_slot[i].slot_center.x,
				_league_slot[i].slot_center.y,
				_league_slot[i].lock->get_width(),
				_league_slot[i].lock->get_height());
		}
	}//loop: 슬롯의 이미지, 렉트를 잡기 위한 루프
}
void Window::draw_league_slots()
{
	for (int i = 0; i < 3; i++)
	{
		_league_slot[i].back->render(get_memDC(),
			_league_slot[i].back_rc.left, _league_slot[i].back_rc.top);
		if (i == 0)
		{
			_league_slot[i].icon_back->render(get_memDC(),
				_league_slot[i].icon_back_rc.left, _league_slot[i].icon_back_rc.top);
			_league_slot[i].icon->render(get_memDC(),
				_league_slot[i].icon_rc.left, _league_slot[i].icon_rc.top);
			// 텍스트
			FontTextShadow(get_memDC(), _league_slot[i].title_pos.x, _league_slot[i].title_pos.y,
				_league_slot[i].title.c_str(), "휴먼매직체", 35, RGB(246, 204, 111));

			FontTextOut(get_memDC(), _league_slot[i].desc_pos.x, _league_slot[i].desc_pos.y,
				_league_slot[i].desc_type[0].c_str(), "휴먼편지체", 25, RGB(255, 193, 59));
			FontTextOut(get_memDC(), _league_slot[i].desc_pos.x + 40, _league_slot[i].desc_pos.y,
				_league_slot[i].desc_type[1].c_str(), "휴먼편지체", 25, RGB(254, 254, 254));
			FontTextOut(get_memDC(), _league_slot[i].desc_pos.x, _league_slot[i].desc_pos.y + 30,
				_league_slot[i].desc_rank[0].c_str(), "휴먼편지체", 25, RGB(255, 193, 59));
			FontTextOut(get_memDC(), _league_slot[i].desc_pos.x + 90, _league_slot[i].desc_pos.y + 30,
				_league_slot[i].desc_rank[1].c_str(), "휴먼편지체", 25, RGB(254, 254, 254));
			FontTextOut(get_memDC(), _league_slot[i].desc_pos.x, _league_slot[i].desc_pos.y + 60,
				_league_slot[i].desc_next[0].c_str(), "휴먼편지체", 25, RGB(255, 193, 59));
			FontTextOut(get_memDC(), _league_slot[i].desc_pos.x + 90, _league_slot[i].desc_pos.y + 60,
				_league_slot[i].desc_next[1].c_str(), "휴먼편지체", 25, RGB(254, 254, 254));
			// 버튼
			_league_slot[i].btn_show->render(get_memDC(),
				_league_slot[i].btn_show_rc.left,
				_league_slot[i].btn_show_rc.top);
			_league_slot[i].icon_show->render(get_memDC(),
				_league_slot[i].icon_show_rc.left,
				_league_slot[i].icon_show_rc.top);
		}
		else
		{
			_league_slot[i].lock_back->alphaRender(get_memDC(),
				_league_slot[i].lock_back_rc.left, _league_slot[i].lock_back_rc.top, 80);
			_league_slot[i].lock->alphaRender(get_memDC(),
				_league_slot[i].lock_rc.left, _league_slot[i].lock_rc.top, 255);
		}
	}
	if (_fDebug)
	{
		for (int i = 0; i < 3; i++)
		{
			ColorRect(get_memDC(), _league_slot[i].back_rc);
			ColorRect(get_memDC(), _league_slot[i].btn_show_rc, RGB(162, 204, 232));
			ColorRect(get_memDC(), _league_slot[i].icon_rc);
		}
		ColorRect(get_memDC(), _league_slot[0].icon_back_rc);
	}
}
void Window::delete_league_slots()
{
	for (int i = 0; i < 3; i++)
	{
		_league_slot[i].back->release();
		_league_slot[i].back = nullptr;
		_league_slot[i].lock_back->release();
		_league_slot[i].lock_back = nullptr;
		_league_slot[i].lock->release();
		_league_slot[i].lock = nullptr;
		_league_slot[i].icon->release();
		_league_slot[i].icon = nullptr;
		_league_slot[i].icon_back->release();
		_league_slot[i].icon_back = nullptr;
	}
}

void Window::update_fOpenBus()
{
	// 윈도우를 열지 말지 정한다.
	if (_mapIcon_on == MAPICON::ICON_EMPTY) { _fOpenBus = false; }
	else { _fOpenBus = true; }
}

HRESULT Window::init(WINDOW::TYPE type)
{
	set_imgPath("UI/Window/");
	_type = type;
	// Background 초기화
	init_window_bg(type);
	// Foreground Image 초기화
	switch (type)
	{
	case WINDOW::WINDOW_FRIGER:
		init_inventory();
		break;
	case WINDOW::WINDOW_SHOP:
		init_inventory();
		break;
	case WINDOW::WINDOW_LEAGUE:
		init_league();
		break;
	}
	_fClose = false;
	return S_OK;
}
void Window::release()
{
	delete_window_bg();
	switch (_type)
	{
	case WINDOW::WINDOW_FRIGER:
		delete_inventory();
		break;
	case WINDOW::WINDOW_SHOP:
		delete_inventory();
		break;
	case WINDOW::WINDOW_LEAGUE:
		delete_league();
		break;
	}
}
void Window::update()
{
	if (KEYMANAGER->is_onceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_red_button->get_rc(), m_ptMouse))
		{
			_fClose = true;
			_fOpenBus = false;
			_fClickLock = false;
			_mapIcon_on = MAPICON::ICON_EMPTY;
		}// 닫기 버튼을 누르면 닫는다.
		switch (_type)
		{
		case WINDOW::WINDOW_LEAGUE:
			update_league();
			break;
		}
	}//if: 클릭 했을 때 인벤토리를 닫는다.
	else
	{
		// 윈도우가 열린 동안 윈도우 밖은 클릭할 수 없다.
		_fClickLock = true;
	}
}
void Window::render()
{
	draw_window_bg();
	switch (_type)
	{
	case WINDOW::WINDOW_FRIGER:
		draw_inventory();
		break;
	case WINDOW::WINDOW_SHOP:
		draw_inventory();
		break;
	case WINDOW::WINDOW_LEAGUE:
		draw_league();
		break;
	}
}
Window::Window()
{
	_type = WINDOW::WINDOW_NONE;
}
Window::~Window()
{
}
