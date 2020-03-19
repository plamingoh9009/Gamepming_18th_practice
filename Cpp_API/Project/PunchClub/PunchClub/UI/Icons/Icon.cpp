#include "stdafx.h"
#include "Icon.h"

void Icon::init_icons()
{
	string path;
	string title;
	string descr;
	// �̹��� �ҷ�����
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
		title = "�ó� ����";
		descr = "Ŭ���ϸ� �ó� ������ ����, �ٸ� ��ҷ� �̵��� �� �ֽ��ϴ�.";
		_hint->set_texts(title, descr);
		break;
	case ICON::ICN_LEAGUE:
		path = _imgPath + "Icon_league.bmp";
		_fg->init(path.c_str(), (int)(26 * GAME_MULTIPLE), (int)(29 * GAME_MULTIPLE));
		title = "����Ʈ ����";
		descr = "����, ���� ����, ���� ���տ� ���� ������ �� �� �ֽ��ϴ�.";
		_hint->set_texts(title, descr);
		break;
	case ICON::ICN_SKILLTREE:
		path = _imgPath + "Icon_skilltree.bmp";
		_fg->init(path.c_str(), (int)(37 * GAME_MULTIPLE), (int)(37 * GAME_MULTIPLE));
		title = "��ų Ʈ��";
		descr = "��ų ����� ���� ���ο� ����� �����Ϸ���, �̰��� Ŭ���ϼ���.";
		_hint->set_texts(title, descr);
		break;
	case ICON::ICN_ENERGY:
		path = _imgPath + "Energy_icon.bmp";
		_fg->init(path.c_str(), (int)(13 * GAME_MULTIPLE), (int)(13 * GAME_MULTIPLE));
		break;
	case ICON::ICN_FEEL:
		path = _imgPath + "Feel_icon.bmp";
		_fg->init(path.c_str(), (int)(13 * GAME_MULTIPLE), (int)(13 * GAME_MULTIPLE));
		break;
	case ICON::ICN_FOOD:
		path = _imgPath + "Food_icon.bmp";
		_fg->init(path.c_str(), (int)(13 * GAME_MULTIPLE), (int)(13 * GAME_MULTIPLE));
		break;
	case ICON::ICN_HEALTH:
		path = _imgPath + "Health_icon.bmp";
		_fg->init(path.c_str(), (int)(13 * GAME_MULTIPLE), (int)(13 * GAME_MULTIPLE));
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
	//##			������ Ŭ��ó��			  ##
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
			// �������� ���� �� �÷��̾� �������̰� �Ѵ�.
			if (_type != ICON::ICN_EMPTY) { _obj->set_fObjMove(false); }
		}//if: Ŭ�� �ߴٸ�
		_hint->update();
		_fHint = true;
	}//if: ���콺�� �������� ��Ʈ�� ����.
	else
	{
		_fHint = false;
	}
}
void Icon::render()
{
	draw_icons();
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
	if (_bg != nullptr)
	{
		_bg->set_center(center);
	}
	if (_fg != nullptr)
	{
		_fg->set_center(center);
	}
	if (_hint != nullptr)
	{
		_hint->set_center(center);
	}
}

void Icon::set_text_toIcon(string str, int size, COLORREF color)
{
	POINT pos;
	switch (_type)
	{
	case ICON::ICN_ENERGY:
	case ICON::ICN_FEEL:
	case ICON::ICN_FOOD:
	case ICON::ICN_HEALTH:
		_icon_txt = MyText(MYTEXT::TXT_DESCR, str, RGB(254, 254, 254));
		pos.x = (LONG)(_fg->get_rect().right);
		pos.y = (LONG)(_fg->get_rect().top);
		_icon_txt.set_pos(pos);
		_icon_txt.set_size(size);
		break;
	}
}
