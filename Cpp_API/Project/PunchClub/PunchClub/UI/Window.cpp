#include "stdafx.h"
#include "Window.h"

void Window::init_default()
{
	string path;
	POINT center;
	path = _imgPath + "Window_back.bmp";
	_bg = new Image;
	_bg->init(path.c_str(), (int)(425 * GAME_MULTIPLE), (int)(300 * GAME_MULTIPLE));
	center.x = (LONG)(WIN_HALF_W);
	center.y = (LONG)(WIN_HALF_H + _bg->get_height() * 0.07);
	_bg_rc = RectMakeCenter(center.x, center.y, _bg->get_width(), _bg->get_height());
	_bg_center = center;
	_red_button = new RedButton();
	_red_button->init(_bg_rc.right, _bg_rc.top);
	// ������ �׸��� ����
	path = _imgPath + "Locked_back.bmp";
	_locked_back = new Image;
	_locked_back->init(path.c_str(), (int)(419 * GAME_MULTIPLE), (int)(234 * GAME_MULTIPLE));
	_locked_back_pos.x = (LONG)(_bg_rc.left + 6);
	_locked_back_pos.y = (LONG)(_bg_rc.top + _bg->get_height() * 0.2 + 4);
	_locked_back_rc = RectMake((int)(_locked_back_pos.x), (int)(_locked_back_pos.y),
		_locked_back->get_width(), _locked_back->get_height());
}
void Window::draw_default()
{
	_bg->render(get_memDC(), _bg_rc.left, _bg_rc.top);
	_red_button->render();
}
void Window::delete_default()
{
	_bg->release();
	_bg = nullptr;
	_slot->release();
	_slot = nullptr;
	_red_button->release();
	_red_button = nullptr;
	_locked_back->release();
	_locked_back = nullptr;
}
void Window::init_inventory()
{
	string path;
	path = _imgPath + "Inven_slot.bmp";
	_slot = new Image;
	_slot->init(path.c_str(), (int)(212 * GAME_MULTIPLE), (int)(60 * GAME_MULTIPLE));
	path = _imgPath + "Btn_green.bmp";

	_fg = new Image;
	switch (_type)
	{
	case WINDOW_FRIGER:
		path = _imgPath + "Hdr_friger.bmp";
		_fg->init(path.c_str(), (int)(79 * GAME_MULTIPLE), (int)(40 * GAME_MULTIPLE));
		// �۾�
		_fg_title = "�����";
		_fg_descr = "����� �� �ķ�ǰ�� �����˴ϴ�. �ķ�ǰ�� ���ۿ��� ������ �� �ֽ��ϴ�.";
		break;
	case WINDOW_SHOP:
		path = _imgPath + "Hdr_shop.bmp";
		_fg->init(path.c_str(), (int)(89 * GAME_MULTIPLE), (int)(47 * GAME_MULTIPLE));
		// �۾�
		_fg_title = "����";
		_fg_descr = "�ķ�ǰ �� ������ �帵ũ�� ������ �� �ֽ��ϴ�.";
		break;
	}
	_fg_rc = RectMake((int)(_bg_rc.left), (int)(_bg_rc.top + 10),
		(int)(_bg->get_width() * 0.25), (int)(_bg->get_height() * 0.2));
	_fg_center.x = (LONG)((_fg_rc.left + _fg_rc.right) * 0.5);
	_fg_center.y = (LONG)((_fg_rc.top + _fg_rc.bottom) * 0.5);
	_fg_title_pos.x = _fg_rc.right;
	_fg_title_pos.y = _fg_rc.top + 20;
	_fg_descr_pos.x = _fg_title_pos.x;
	_fg_descr_pos.y = _fg_title_pos.y + 40;
	_fg_rc = RectMakeCenter(_fg_center.x, _fg_center.y,
		_fg->get_width(), _fg->get_height());
	// ���� �ʱ�ȭ
	_line_pos.x = (LONG)(_locked_back_rc.left);
	_line_pos.y = (LONG)(_locked_back_rc.top);
}
void Window::draw_inventory()
{
	// Line�� �׸���.
	ColorLine(get_memDC(), _line_pos.x, (int)(_line_pos.y - 2),
		_locked_back_rc.right, (int)(_line_pos.y - 2),
		1, RGB(94, 84, 64));
	ColorLine(get_memDC(), _line_pos.x, _line_pos.y,
		_locked_back_rc.right - 1, _line_pos.y,
		2, RGB(78, 68, 50));
	_locked_back->alphaRender(get_memDC(), _locked_back_rc.left, _locked_back_rc.top, 32);
	// fg �̹����� �׸���.
	_fg->render(get_memDC(), _fg_rc.left, _fg_rc.top);
	FontTextShadow(get_memDC(), _fg_title_pos.x, _fg_title_pos.y, _fg_title.c_str(),
		"�޸ո���ü", 35, RGB(254, 254, 254));
	FontTextOut(get_memDC(), _fg_descr_pos.x, _fg_descr_pos.y, _fg_descr.c_str(),
		"�޸�����ü", 25, RGB(58, 47, 24));
	if (_fDebug) { ColorRect(get_memDC(), _fg_rc); }
}
void Window::delete_inventory()
{
	_fg->release();
	_fg = nullptr;
}

void Window::init_league()
{
	set_imgPath("UI/Window/League/");
	string path;
	POINT pos;
	path = _imgPath + "League_fg.bmp";
	// ���� �ʱ�ȭ
	_line_pos.x = (LONG)(_locked_back_rc.left);
	_line_pos.y = (LONG)((_bg_rc.top + _locked_back_rc.top) * 0.5);
	_line_pos_ver.x = (LONG)((_bg_rc.left + _bg_rc.right) * 0.45);
	_line_pos_ver.y = (LONG)(_bg_rc.bottom - 8);
	// ���� ������ �̹���
	_fg = new Image;
	_fg->init(path.c_str(), (int)(159 * GAME_MULTIPLE), (int)(180 * GAME_MULTIPLE));
	pos.x = (LONG)(_line_pos.x);
	pos.y = (LONG)(_line_pos.y);
	_fg_rc = RectMake(pos.x, pos.y,
		(int)(_line_pos_ver.x - _line_pos.x),
		(int)(_line_pos_ver.y - _line_pos.y));
	_fg_center.x = (LONG)((_fg_rc.left + _fg_rc.right) * 0.5);
	_fg_center.y = (LONG)((_fg_rc.top + _fg_rc.bottom) * 0.525);
	_fg_rc = RectMakeCenter(_fg_center.x, _fg_center.y,
		_fg->get_width(), _fg->get_height());
	// ���� �۾�
	_fg_title = "����";
	_fg_title_pos.x = (LONG)(_bg_center.x);
	_fg_title_pos.y = (LONG)((_line_pos.y + _bg_rc.top) * 0.46);
	// ���� ������ ���� ��Ʈ
	init_league_slots();
}
void Window::draw_league()
{
	// ���� Line�� �׸���.
	ColorLine(get_memDC(), _locked_back_rc.left, (int)(_line_pos.y - 2),
		_locked_back_rc.right, (int)(_line_pos.y - 2),
		1, RGB(94, 84, 64));
	ColorLine(get_memDC(), _locked_back_rc.left, _line_pos.y,
		_locked_back_rc.right - 1, _line_pos.y,
		2, RGB(78, 68, 50));
	// ���� Line�� ��´�.
	ColorLine(get_memDC(), _line_pos_ver.x, _line_pos.y,
		_line_pos_ver.x, _line_pos_ver.y, 2, RGB(94, 84, 64));
	// ���� �������� �׸���
	_fg->render(get_memDC(), _fg_rc.left, _fg_rc.top);
	// ���� Ÿ��Ʋ�� ����.
	FontTextShadow(get_memDC(), _fg_title_pos.x, _fg_title_pos.y, _fg_title.c_str(),
		"�޸ո���ü", 35, RGB(254, 254, 254));
	draw_league_slots();
	// ����� ���
	if (_fDebug)
	{
		ColorRect(get_memDC(), _fg_rc);
	}
}
void Window::update_league()
{
}
void Window::delete_league()
{
	_fg->release();
	_fg = nullptr;
	delete_league_slots();
}
void Window::init_league_slots()
{
	string path;
	POINT pos;
	int width = (int)(_bg_rc.right - _line_pos_ver.x - 6);
	int height = (int)(_bg_rc.bottom - _line_pos.y - 6);
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
			// ������ �ؽ�Ʈ�� ���ϴ� �κ�
			_league_slot[i].title = "��Ű ����";
			_league_slot[i].desc_type[0] = "����: ";
			_league_slot[i].desc_type[1] = "���ھ��";
			_league_slot[i].desc_rank[0] = "���� ����: ";
			_league_slot[i].desc_rank[1] = "12";
			_league_slot[i].desc_next[0] = "���� �ο�: ";
			_league_slot[i].desc_next[1] = "2 �� ��";
			_league_slot[i].title_pos.x = (LONG)(_league_slot[i].slot_center.x - 30);
			_league_slot[i].title_pos.y = (LONG)(_league_slot[i].back_rc.top + 10);
			_league_slot[i].desc_pos.x = (LONG)(_league_slot[i].icon_back_rc.right + 5);
			_league_slot[i].desc_pos.y = (LONG)(_league_slot[i].icon_back_rc.top + 5);
			// ��ư
			path = _imgPath + "Btn_show.bmp";
			_league_slot[i].btn_show = new Image;
			_league_slot[i].btn_show->init(path.c_str(), 
				(int)(57 * GAME_MULTIPLE), (int)(20 * GAME_MULTIPLE));
			path = _imgPath + "Icon_show.bmp";
			_league_slot[i].icon_show = new Image;
			_league_slot[i].icon_show->init(path.c_str(), 
				(int)(24 * GAME_MULTIPLE), (int)(24 * GAME_MULTIPLE));
			// ��ư ��ġ
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
	}//loop: ������ �̹���, ��Ʈ�� ��� ���� ����
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
			// �ؽ�Ʈ
			FontTextShadow(get_memDC(), _league_slot[i].title_pos.x, _league_slot[i].title_pos.y,
				_league_slot[i].title.c_str(), "�޸ո���ü", 35, RGB(246, 204, 111));
			
			FontTextOut(get_memDC(), _league_slot[i].desc_pos.x, _league_slot[i].desc_pos.y,
				_league_slot[i].desc_type[0].c_str(), "�޸�����ü", 25, RGB(255, 193, 59));
			FontTextOut(get_memDC(), _league_slot[i].desc_pos.x + 40, _league_slot[i].desc_pos.y,
				_league_slot[i].desc_type[1].c_str(), "�޸�����ü", 25, RGB(254, 254, 254));
			FontTextOut(get_memDC(), _league_slot[i].desc_pos.x, _league_slot[i].desc_pos.y + 30,
				_league_slot[i].desc_rank[0].c_str(), "�޸�����ü", 25, RGB(255, 193, 59));
			FontTextOut(get_memDC(), _league_slot[i].desc_pos.x + 90, _league_slot[i].desc_pos.y + 30,
				_league_slot[i].desc_rank[1].c_str(), "�޸�����ü", 25, RGB(254, 254, 254));
			FontTextOut(get_memDC(), _league_slot[i].desc_pos.x, _league_slot[i].desc_pos.y + 60,
				_league_slot[i].desc_next[0].c_str(), "�޸�����ü", 25, RGB(255, 193, 59));
			FontTextOut(get_memDC(), _league_slot[i].desc_pos.x + 90, _league_slot[i].desc_pos.y + 60,
				_league_slot[i].desc_next[1].c_str(), "�޸�����ü", 25, RGB(254, 254, 254));
			// ��ư
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

HRESULT Window::init()
{
	set_imgPath("UI/Window/");
	init_default();

	_fClose = false;
	return S_OK;
}
HRESULT Window::init(WINDOW_TYPE type)
{
	_type = type;
	init();
	if (_type == WINDOW_FRIGER || _type == WINDOW_SHOP)
	{
		init_inventory();
	}
	else if (_type == WINDOW_LEAGUE) { init_league(); }
	return S_OK;
}
void Window::release()
{
	delete_default();
	if (_type == WINDOW_FRIGER || _type == WINDOW_SHOP)
	{
		delete_inventory();
	}
	else if (_type == WINDOW_LEAGUE)
	{
		delete_league();
	}
}
void Window::update()
{
	if (_type == WINDOW_LEAGUE) { update_league(); }
	if (KEYMANAGER->is_onceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_red_button->get_rc(), m_ptMouse))
		{
			_fClose = true;
			_fClickLock = false;
		}
	}//if: Ŭ�� ���� �� �κ��丮�� �ݴ´�.
	else
	{
		// �����찡 ���� ���� ������ ���� Ŭ���� �� ����.
		_fClickLock = true;
	}
}
void Window::render()
{
	draw_default();
	if (_type == WINDOW_FRIGER || _type == WINDOW_SHOP)
	{
		draw_inventory();
	}
	else if (_type == WINDOW_LEAGUE) { draw_league(); }
}
Window::Window()
{
	_type = WINDOW_NONE;
}
Window::~Window()
{
}
