#include "stdafx.h"
#include "Inventory.h"

void Inventory::init_default()
{
	string path;
	POINT center;
	path = _imgPath + "Inven_back.bmp";
	_bg = new Image;
	_bg->init(path.c_str(), (int)(425 * GAME_MULTIPLE), (int)(300 * GAME_MULTIPLE));
	center.x = (LONG)(WIN_HALF_W);
	center.y = (LONG)(WIN_HALF_H + _bg->get_height() * 0.07);
	_bg_rc = RectMakeCenter(center.x, center.y, _bg->get_width(), _bg->get_height());
	_bg_center = center;
	path = _imgPath + "Inven_slot.bmp";
	_slot = new Image;
	_slot->init(path.c_str(), (int)(212 * GAME_MULTIPLE), (int)(60 * GAME_MULTIPLE));
	path = _imgPath + "Locked_back.bmp";
	_locked_back = new Image;
	_locked_back->init(path.c_str(), (int)(419 * GAME_MULTIPLE), (int)(234 * GAME_MULTIPLE));
	_locked_back_pos.x = (LONG)(_bg_rc.left + 6);
	_locked_back_pos.y = (LONG)(_bg_rc.top + _bg->get_height() * 0.2 + 4);
	_locked_back_rc = RectMake((int)(_locked_back_pos.x), (int)(_locked_back_pos.y),
		_locked_back->get_width(), _locked_back->get_height());
	path = _imgPath + "Btn_green.bmp";
	_red_button = new RedButton();
	_red_button->init(_bg_rc.right, _bg_rc.top);

	if (_type != INVEN_NONE) { init_fg(); }
}
void Inventory::draw_default()
{
	_bg->render(get_memDC(), _bg_rc.left, _bg_rc.top);
	_locked_back->alphaRender(get_memDC(), _locked_back_rc.left, _locked_back_rc.top, 32);
	// Line�� �׸���.
	ColorLine(get_memDC(), _locked_back_rc.left, _locked_back_rc.top - 2,
		_locked_back_rc.right, _locked_back_rc.top - 2, 
		1, RGB(94, 84, 64));
	ColorLine(get_memDC(), _locked_back_rc.left, _locked_back_rc.top,
		_locked_back_rc.right-1, _locked_back_rc.top, 
		2, RGB(78, 68, 50));
	_red_button->render();

	if (_type != INVEN_NONE) { draw_fg(); }
}
void Inventory::delete_default()
{
	_bg->release();
	_bg = nullptr;
	_slot->release();
	_slot = nullptr;
	_locked_back->release();
	_locked_back = nullptr;
	_red_button->release();
	_red_button = nullptr;
	if (_type != INVEN_NONE) { delete_fg(); }
}

void Inventory::init_fg()
{
	string path;
	_fg = new Image;
	switch (_type)
	{
	case INVEN_FRIGER:
		path = _imgPath + "Hdr_friger.bmp";
		_fg->init(path.c_str(), (int)(79 * GAME_MULTIPLE), (int)(40 * GAME_MULTIPLE));
		// �۾�
		_fg_title = "�����";
		_fg_descr = "����� �� �ķ�ǰ�� �����˴ϴ�. �ķ�ǰ�� ���ۿ��� ������ �� �ֽ��ϴ�.";
		break;
	case INVEN_SHOP:
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
}
void Inventory::draw_fg()
{
	_fg->render(get_memDC(), _fg_rc.left, _fg_rc.top);
	FontTextOut(get_memDC(), _fg_title_pos.x, _fg_title_pos.y, _fg_title.c_str(),
		"�޸ո���ü", 35, RGB(254, 254, 254));
	FontTextOut(get_memDC(), _fg_descr_pos.x, _fg_descr_pos.y, _fg_descr.c_str(),
		"�޸�����ü", 25, RGB(58, 47, 24));
	if (_fDebug) { ColorRect(get_memDC(), _fg_rc); }
}
void Inventory::delete_fg()
{
	_fg->release();
	_fg = nullptr;
}

HRESULT Inventory::init()
{
	set_imgPath("UI/Inven/");
	init_default();
	
	_fClose = false;
	return S_OK;
}
HRESULT Inventory::init(INVEN_TYPE type)
{
	_type = type;
	init();
	return S_OK;
}
void Inventory::release()
{
	delete_default();
}
void Inventory::update()
{
	if (_fClick)
	{
		if (PtInRect(&_red_button->get_rc(), m_ptMouse)) { _fClose = true; }
	}//if: Ŭ�� ���� ��
}
void Inventory::render()
{
	draw_default();
}
Inventory::Inventory()
{
	_type = INVEN_NONE;
}
Inventory::~Inventory()
{
}
