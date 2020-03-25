#include "stdafx.h"
#include "Facility.h"
#include "Player.h"
void Facility::change_player_run()
{
	switch (_run_type)
	{
	case MYOBJECT::TRM_PLAYER:
		change_player_actions(PLAYER_SET::ACTION_TREADMILL);
		break;
	case MYOBJECT::BBL_PLAYER:
		change_player_actions(PLAYER_SET::ACTION_BARBELL);
		break;
	case MYOBJECT::YCN_PLAYER:
		change_player_actions(PLAYER_SET::ACTION_YUNGCHUN);
		break;
	case MYOBJECT::TIR_PLAYER:
		change_player_actions(PLAYER_SET::ACTION_HIT_TIRE);
		break;
	case MYOBJECT::BP_PLAYER:
		change_player_actions(PLAYER_SET::ACTION_BENCH_PRESS);
		break;
	case MYOBJECT::PB_PLAYER:
		change_player_actions(PLAYER_SET::ACTION_PUNCHBUG);
		break;
	}
}
void Facility::change_player_actions(PLAYER_SET::ACTION runType)
{
	// Set actionType to player
	PLAYER->set_playerAction(runType);
	// Change player action state
	if (PLAYER->is_stop_action())
	{
		PLAYER->action_start();
	}
	else
	{
		PLAYER->action_pause();
	}
	// Change ImgRun On / Off
	_fImgRun = !_fImgRun;
}
void Facility::run_imgFrame()
{
	// �̹��� ������ ��
	if (_img_off != nullptr && is_frameImg(_img_off))
	{
		update_objImgFrame(_img_off);
		if (_img_shadow != nullptr)
		{
			update_objImgFrame(_img_shadow);
		}
	}
	if (_img_on != nullptr && is_frameImg(_img_on))
	{
		update_objImgFrame(_img_on);
	}
	if (_img_run != nullptr && is_frameImg(_img_run))
	{
		if (is_frameImg(_img_run))
		{
			update_objImgFrame(_img_run);
			if (_img_run_shadow != nullptr)
			{
				update_objImgFrame(_img_run_shadow);
			}
		}
	}
}

HRESULT Facility::init_objs()
{
	string path;
	switch (_type)
	{
	case MYOBJECT::OBJ_TREADMILL:
		_img_off = new Image;
		path = _imgPath + "treadmill.bmp";
		_img_off->init(path.c_str(), (int)(165 * GAME_MULTIPLE), (int)(59 * GAME_MULTIPLE), 3, 1);
		_img_off->set_frameSection(1, 0, 2, 0.4f);
		_img_shadow = new Image;
		path = _imgPath + "treadmill_shadow.bmp";
		_img_shadow->init(path.c_str(), (int)(165 * GAME_MULTIPLE), (int)(59 * GAME_MULTIPLE), 3, 1);
		_img_shadow->set_frameSection(1, 0, 2, 0.4f);
		_img_on = new Image;
		path = _imgPath + "treadmill_on.bmp";
		_img_on->init(path.c_str(), (int)(165 * GAME_MULTIPLE), (int)(59 * GAME_MULTIPLE), 3, 1);
		_img_on->set_frameSection(1, 0, 2, 0.4f);
		break;
	case MYOBJECT::OBJ_BARBELL:
		_img_off = new Image;
		path = _imgPath + "barbell.bmp";
		_img_off->init(path.c_str(), (int)(77 * GAME_MULTIPLE), (int)(102 * GAME_MULTIPLE));
		_img_shadow = new Image;
		path = _imgPath + "barbell_shadow.bmp";
		_img_shadow->init(path.c_str(), (int)(77 * GAME_MULTIPLE), (int)(102 * GAME_MULTIPLE));
		_img_on = new Image;
		path = _imgPath + "barbell_on.bmp";
		_img_on->init(path.c_str(), (int)(77 * GAME_MULTIPLE), (int)(102 * GAME_MULTIPLE));
		break;
	case MYOBJECT::OBJ_YUNGCHUN:
		_img_off = new Image;
		path = _imgPath + "yungchun.bmp";
		_img_off->init(path.c_str(), (int)(30 * GAME_MULTIPLE), (int)(80 * GAME_MULTIPLE));
		_img_shadow = new Image;
		path = _imgPath + "yungchun_shadow.bmp";
		_img_shadow->init(path.c_str(), (int)(30 * GAME_MULTIPLE), (int)(80 * GAME_MULTIPLE));
		_img_on = new Image;
		path = _imgPath + "yungchun_on.bmp";
		_img_on->init(path.c_str(), (int)(30 * GAME_MULTIPLE), (int)(80 * GAME_MULTIPLE));
		break;
	case MYOBJECT::OBJ_TIRE:
		_img_off = new Image;
		path = _imgPath + "hit_tire.bmp";
		_img_off->init(path.c_str(), (int)(91 * GAME_MULTIPLE), (int)(55 * GAME_MULTIPLE));
		_img_shadow = new Image;
		path = _imgPath + "hit_tire_shadow.bmp";
		_img_shadow->init(path.c_str(), (int)(91 * GAME_MULTIPLE), (int)(55 * GAME_MULTIPLE));
		_img_on = new Image;
		path = _imgPath + "hit_tire_on.bmp";
		_img_on->init(path.c_str(), (int)(91 * GAME_MULTIPLE), (int)(55 * GAME_MULTIPLE));
		break;
	case MYOBJECT::OBJ_BENCH_PRESS:
		_img_off = new Image;
		path = _imgPath + "bench.bmp";
		_img_off->init(path.c_str(), (int)(71 * GAME_MULTIPLE), (int)(77 * GAME_MULTIPLE));
		_img_shadow = new Image;
		path = _imgPath + "bench_shdw.bmp";
		_img_shadow->init(path.c_str(), (int)(71 * GAME_MULTIPLE), (int)(77 * GAME_MULTIPLE));
		_img_on = new Image;
		path = _imgPath + "bench_on.bmp";
		_img_on->init(path.c_str(), (int)(71 * GAME_MULTIPLE), (int)(77 * GAME_MULTIPLE));
		break;
	case MYOBJECT::OBJ_PUNCHBUG:
		_img_off = new Image;
		path = _imgPath + "punchbug.bmp";
		_img_off->init(path.c_str(), (int)(128 * GAME_MULTIPLE), (int)(211 * GAME_MULTIPLE), 4, 1);
		_img_off->set_frameSection(1, 0, 3, 0.5f);
		_img_shadow = new Image;
		path = _imgPath + "punchbug_shdw.bmp";
		_img_shadow->init(path.c_str(), (int)(128 * GAME_MULTIPLE), (int)(211 * GAME_MULTIPLE), 4, 1);
		_img_shadow->set_frameSection(1, 0, 3, 0.5f);
		_img_on = new Image;
		path = _imgPath + "punchbug_on.bmp";
		_img_on->init(path.c_str(), (int)(128 * GAME_MULTIPLE), (int)(211 * GAME_MULTIPLE), 4, 1);
		_img_on->set_frameSection(1, 0, 3, 0.5f);
		break;
	}
	switch (_run_type)
	{
	case MYOBJECT::TRM_ORANGE_GIRL:
		_img_run = new Image;
		path = _imgPath + "trm_orange_girl.bmp";
		_img_run->init(path.c_str(), (int)(174 * GAME_MULTIPLE), (int)(81 * GAME_MULTIPLE), 6, 1);
		_img_run->set_frameSection(1, 0, 5, 0.13f);
		_img_run_shadow = new Image;
		path = _imgPath + "trm_orange_girl_shadow.bmp";
		_img_run_shadow->init(path.c_str(), (int)(174 * GAME_MULTIPLE), (int)(81 * GAME_MULTIPLE), 6, 1);
		_img_run_shadow->set_frameSection(1, 0, 5, 0.13f);
		_fImgRun = true;
		// Ʈ����� ���� �ӵ��� �ٽ� ����ش�.
		_img_off->set_frameSection(1, 0, 2, 0.26f);
		_img_shadow->set_frameSection(1, 0, 2, 0.26f);
		break;
	case MYOBJECT::TRM_YELLOW_GIRL:
		_img_run = new Image;
		path = _imgPath + "trm_yellow_girl.bmp";
		_img_run->init(path.c_str(), (int)(180 * GAME_MULTIPLE), (int)(80 * GAME_MULTIPLE), 6, 1);
		_img_run->set_frameSection(1, 0, 5, 0.18f);
		_img_run_shadow = new Image;
		path = _imgPath + "trm_yellow_girl_shadow.bmp";
		_img_run_shadow->init(path.c_str(), (int)(180 * GAME_MULTIPLE), (int)(80 * GAME_MULTIPLE), 6, 1);
		_img_run_shadow->set_frameSection(1, 0, 5, 0.18f);
		_fImgRun = true;
		// Ʈ����� ���� �ӵ��� �ٽ� ����ش�.
		_img_off->set_frameSection(1, 0, 2, 0.36f);
		_img_shadow->set_frameSection(1, 0, 2, 0.36f);
		break;
	case MYOBJECT::TRM_PLAYER:
		_img_run = new Image;
		path = _imgPath + "trm_run_player.bmp";
		_img_run->init(path.c_str(), (int)(252 * GAME_MULTIPLE), (int)(80 * GAME_MULTIPLE), 6, 1);
		_img_run->set_frameSection(1, 0, 5, 0.1f);
		_img_run_shadow = new Image;
		path = _imgPath + "trm_run_shadow.bmp";
		_img_run_shadow->init(path.c_str(), (int)(252 * GAME_MULTIPLE), (int)(80 * GAME_MULTIPLE), 6, 1);
		_img_run_shadow->set_frameSection(1, 0, 5, 0.1f);
		// Ʈ����� ���� �ӵ��� �ٽ� ����ش�.
		_img_off->set_frameSection(1, 0, 2, 0.2f);
		_img_shadow->set_frameSection(1, 0, 2, 0.2f);
		break;
	case MYOBJECT::BBL_PLAYER:
		_img_run = new Image;
		path = _imgPath + "barbell_run.bmp";
		_img_run->init(path.c_str(), (int)(249 * GAME_MULTIPLE), (int)(105 * GAME_MULTIPLE), 3, 1);
		_img_run->set_frameSection(1, 0, 2, 0.5f);
		_img_run_shadow = new Image;
		path = _imgPath + "barbell_run_shadow.bmp";
		_img_run_shadow->init(path.c_str(), (int)(249 * GAME_MULTIPLE), (int)(105 * GAME_MULTIPLE), 3, 1);
		_img_run_shadow->set_frameSection(1, 0, 2, 0.5f);
		// ������ �ٺ��� �����.
		_fImgRunOnly = true;
		break;
	case MYOBJECT::YCN_PLAYER:
		_img_run = new Image;
		path = _imgPath + "yungchun_run.bmp";
		_img_run->init(path.c_str(), (int)(240 * GAME_MULTIPLE), (int)(85 * GAME_MULTIPLE), 6, 1);
		_img_run->set_frameSection(1, 0, 5, 0.3f);
		_img_run_shadow = new Image;
		path = _imgPath + "yungchun_run_shadow.bmp";
		_img_run_shadow->init(path.c_str(), (int)(240 * GAME_MULTIPLE), (int)(85 * GAME_MULTIPLE), 6, 1);
		_img_run_shadow->set_frameSection(1, 0, 5, 0.3f);
		// ������ �������� �����.
		_fImgRunOnly = true;
		break;
	case MYOBJECT::TIR_PLAYER:
		_img_run = new Image;
		path = _imgPath + "tire_hit.bmp";
		_img_run->init(path.c_str(), (int)(600 * GAME_MULTIPLE), (int)(95 * GAME_MULTIPLE), 6, 1);
		_img_run->set_frameSection(1, 0, 5, 0.3f);
		_img_run_shadow = new Image;
		path = _imgPath + "tire_hit_shadow.bmp";
		_img_run_shadow->init(path.c_str(), (int)(600 * GAME_MULTIPLE), (int)(95 * GAME_MULTIPLE), 6, 1);
		_img_run_shadow->set_frameSection(1, 0, 5, 0.3f);
		_img_runback = new Image;
		path = _imgPath + "hit_tire_runback.bmp";
		_img_runback->init(path.c_str(), (int)(86 * GAME_MULTIPLE), (int)(54 * GAME_MULTIPLE));
		_img_runback_shdw = new Image;
		path = _imgPath + "hit_tire_runback_shdw.bmp";
		_img_runback_shdw->init(path.c_str(), (int)(86 * GAME_MULTIPLE), (int)(54 * GAME_MULTIPLE));
		// �÷��̾ Ÿ�̾ ���� �� Ÿ�̾� �̹����� ��ü�Ѵ�.
		_fImgRunBack = true;
		break;
	case MYOBJECT::BP_PLAYER:
		_img_run = new Image;
		path = _imgPath + "bench_run.bmp";
		_img_run->init(path.c_str(), (int)(300 * GAME_MULTIPLE), (int)(75 * GAME_MULTIPLE), 4, 1);
		_img_run->set_frameSection(1, 0, 3, 0.3f);
		_img_run_shadow = new Image;
		path = _imgPath + "bench_run_shdw.bmp";
		_img_run_shadow->init(path.c_str(), (int)(300 * GAME_MULTIPLE), (int)(75 * GAME_MULTIPLE), 4, 1);
		_img_run_shadow->set_frameSection(1, 0, 3, 0.3f);
		// ������ ��ġ�� �����.
		_fImgRunOnly = true;
		break;
	case MYOBJECT::PB_PLAYER:
		_img_run = new Image;
		path = _imgPath + "punchbug_run.bmp";
		_img_run->init(path.c_str(), (int)(504 * GAME_MULTIPLE), (int)(213 * GAME_MULTIPLE), 7, 1);
		_img_run->set_frameSection(3, 0, 6, 0.3f, 3, 6, 0.1f, 3, 6, 0.2f);
		_img_run_shadow = new Image;
		path = _imgPath + "punchbug_run_shdw.bmp";
		_img_run_shadow->init(path.c_str(), (int)(504 * GAME_MULTIPLE), (int)(213 * GAME_MULTIPLE), 7, 1);
		_img_run_shadow->set_frameSection(3, 0, 6, 0.3f, 3, 6, 0.1f, 3, 6, 0.2f);
		break;
	}
	return S_OK;
}
void Facility::delete_objs()
{
	Release(_img_off);
	Release(_img_shadow);
	Release(_img_on);
	Release(_img_run);
	Release(_img_run_shadow);
}
void Facility::draw_objs()
{
	if (_fImgOn == true)
	{
		if (_fImgRun == true)
		{
			if (_fImgRunOnly == true) {}
			else
			{
				if (_fImgRunBack == true)
				{
					draw_img_runback();
				}
				else
				{
					draw_img_off();
				}//else: �̹��� runback ���� �ִٸ� �� �̹����� ��ü�Ѵ�.
			}
		}
		else
		{
			if (_fImgOffOnly == true)
			{
				draw_img_off();
			}
			else
			{
				draw_img_on();
			}
		}
	}//if: �̹����� ���콺 �ø��� On ���� ���
	else
	{
		if (_fImgRun == true && _fImgRunOnly == true) {}
		else if (_fImgRun == true && _fImgRunBack == true)
		{
			draw_img_runback();
		}//if: runback �̹����� ������ ���̹����� ��ü�Ѵ�.
		else
		{
			draw_img_off();
		}//else: ������ bool ������ ������ �� �̹����� �׳� ����Ѵ�.
	}//else: �̹����� ���콺�� �ö� ���� ������ off ���� ���

	if (_fImgRun == true)
	{
		draw_img_run();
	}//run: �� �̹����� ������ ��ο�

	if (_fDebug)
	{
		ColorRect(get_memDC(), _img_off->get_rect());
	}
}
void Facility::update_objs()
{
	// �̹��� ��, ����
	if (PtInRect(&_img_off->get_rect(), m_ptMouse))
	{
		_fImgOn = true;
	}
	else
	{
		_fImgOn = false;
	}
	// �� �̹��� 
	if (_fImgOn == true && _fClick == true)
	{
		change_player_run();
		_fObjMove = false;
	}//if: �ⱸ�� Ŭ���ϸ� ��� �����Ѵ�.
	else if (_fImgRun == true && _fClick == true)
	{
		change_player_run();
		_fObjMove = true;
	}
	runType_case_toUpdate();

	run_imgFrame();
}

void Facility::draw_img_run()
{
	if (_img_run != nullptr)
	{
		if (is_frameImg(_img_run) == true)
		{
			_img_run->frameRender(get_memDC());
			if (_img_run_shadow != nullptr)
			{
				_img_run_shadow->frameAlphaRender(get_memDC(), 128);
			}
		}
		else
		{
			Draw(_img_run, get_memDC());
			if (_img_run_shadow != nullptr)
			{
				Draw(_img_run_shadow, get_memDC());
			}
		}
	}
}
void Facility::draw_img_off()
{
	if (_img_off != nullptr)
	{
		if (is_frameImg(_img_off))
		{
			_img_off->frameRender(get_memDC());
			if (_img_shadow != nullptr)
			{
				_img_shadow->frameAlphaRender(get_memDC(), 128);
			}
		}
		else
		{
			Draw(_img_off, get_memDC());
			if (_img_shadow != nullptr)
			{
				Draw(_img_shadow, get_memDC());
			}
		}
	}
	if (_img_off_fg != nullptr)
	{
		if (is_frameImg(_img_off_fg))
		{
			_img_off_fg->frameAlphaRender(get_memDC(), 128);
		}
		else
		{
			Draw(_img_off_fg, get_memDC());
		}
	}
}
void Facility::draw_img_on()
{
	if (_img_on != nullptr)
	{
		if (is_frameImg(_img_on) == true)
		{
			_img_shadow->frameAlphaRender(get_memDC(), 128);
			_img_on->frameRender(get_memDC());
		}
		else
		{
			Draw(_img_shadow, get_memDC());
			Draw(_img_on, get_memDC());
		}
	}
}
void Facility::draw_img_runback()
{
	if (_img_runback != nullptr)
	{
		if (is_frameImg(_img_runback) == true)
		{
			_img_runback->frameRender(get_memDC());
			_img_runback_shdw->frameAlphaRender(get_memDC(), 128);
		}
		else
		{
			Draw(_img_runback, get_memDC());
			Draw(_img_runback_shdw, get_memDC());
		}
	}
}

void Facility::update_objImgFrame(Image * img)
{
	img->frameUpdate(false);
}

void Facility::runType_case_toUpdate()
{
	// � �ⱸ�� ����
	switch (_run_type)
	{
	case MYOBJECT::PB_PLAYER:
		if (0 <= _img_run->get_frameX() && _img_run->get_frameX() < 3)
		{
			_fImgRunOnly = false;
		}
		else if (3 <= _img_run->get_frameX() && _img_run->get_frameX() < _img_run->get_maxFrameX())
		{
			_fImgRunOnly = true;
		}
		break;
	}
}

HRESULT Facility::init()
{
	set_imgPath("Object/Gym/");
	init_objs();
	return S_OK;
}
void Facility::release()
{
	delete_objs();
}
void Facility::update()
{
	update_objs();
}
void Facility::render()
{
	draw_objs();
}
Facility::Facility()
{
}
Facility::Facility(MYOBJECT::TYPE type)
{
	_type = type;
}
Facility::Facility(MYOBJECT::TYPE type, MYOBJECT::RUN_TYPE run_type)
{
	_type = type;
	_run_type = run_type;
}
Facility::~Facility()
{
}

void Facility::set_center(POINT center)
{
	POINT temp = { 0, 0 };
	switch (_type)
	{
	case MYOBJECT::OBJ_TIRE:
		temp = center;
		temp.x = (LONG)(temp.x + 5);
		temp.y = (LONG)(temp.y);
		break;
	}
	if (_img_off != nullptr)
	{
		_img_off->set_center(center);
	}
	if (_img_off_fg != nullptr)
	{
		_img_off_fg->set_center(center);
	}
	if (_img_on != nullptr)
	{
		_img_on->set_center(center);
	}
	if (_img_shadow != nullptr)
	{
		_img_shadow->set_center(center);
	}
	if (_img_runback != nullptr)
	{
		_img_runback->set_center(temp);
	}
	if (_img_runback_shdw != nullptr)
	{
		_img_runback_shdw->set_center(temp);
	}
	// �޸��� ����� �߰��� �����Ѵ�.
	switch (_run_type)
	{
	case MYOBJECT::TRM_ORANGE_GIRL:
		center.y = (LONG)(center.y - 35);
		break;
	case MYOBJECT::TRM_YELLOW_GIRL:
		center.y = (LONG)(center.y - 32);
		break;
	case MYOBJECT::TRM_PLAYER:
		center.y = (LONG)(center.y - 30);
		break;
	case MYOBJECT::BBL_PLAYER:
		center.x = (LONG)(center.x - 2);
		center.y = (LONG)(center.y + 3);
		break;
	case MYOBJECT::YCN_PLAYER:
		center.x = (LONG)(center.x - 8);
		center.y = (LONG)(center.y + 6);
		break;
	case MYOBJECT::TIR_PLAYER:
		center.x = (LONG)(center.x - 120);
		center.y = (LONG)(center.y - 60);
		break;
	case MYOBJECT::BP_PLAYER:
		center.x = (LONG)(center.x + 4);
		center.y = (LONG)(center.y + 2);
		break;
	case MYOBJECT::PB_PLAYER:
		center.x = (LONG)(center.x - 40);
		center.y = (LONG)(center.y);
		break;
	}
	if (_img_run != nullptr)
	{
		_img_run->set_center(center);
	}
	if (_img_run_shadow != nullptr)
	{
		_img_run_shadow->set_center(center);
	}
}
void Facility::set_pos(POINT pos)
{
	if (_img_off != nullptr)
	{
		_img_off->set_pos(pos);
	}
	if (_img_off_fg != nullptr)
	{
		_img_off_fg->set_pos(pos);
	}
	if (_img_on != nullptr)
	{
		_img_on->set_pos(pos);
	}
	if (_img_shadow != nullptr)
	{
		_img_shadow->set_pos(pos);
	}
	if (_img_run != nullptr)
	{
		_img_run->set_pos(pos);
	}
	if (_img_run_shadow != nullptr)
	{
		_img_run_shadow->set_pos(pos);
	}
}
void Facility::set_img_off_fg_pos(POINT pos)
{
	if (_img_off_fg != nullptr)
	{
		_img_off_fg->set_pos(pos);
	}
}
void Facility::set_img_run_pos(POINT pos)
{
	if (_img_run != nullptr)
	{
		_img_run->set_pos(pos);
	}
	if (_img_run_shadow != nullptr)
	{
		_img_run_shadow->set_pos(pos);
	}
}
int Facility::get_width()
{
	if (is_frameImg(_img_off) == true)
	{
		return _img_off->get_frameWidth();
	}
	else
	{
		return _img_off->get_width();
	}
}
int Facility::get_height()
{
	if (is_frameImg(_img_off) == true)
	{
		return _img_off->get_frameHeight();
	}
	else
	{
		return _img_off->get_height();
	}
}
RECT Facility::get_rect()
{
	if (_img_off != nullptr)
	{
		return _img_off->get_rect();
	}
	return RECT();
}
