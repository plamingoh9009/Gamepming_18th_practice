#include "stdafx.h"
#include "Facility.h"

HRESULT Facility::init_objs()
{
	string path;
	switch (_type)
	{
	case FACILITY::OBJ_TREADMILL:
		_img_off = new Image;
		path = _imgPath + "treadmill.bmp";
		_img_off->init(path.c_str(), (int)(165 * GAME_MULTIPLE), (int)(59 * GAME_MULTIPLE), 3, 1);
		_img_off->set_frameSection(1, 0, 2, 0.4f);
		_img_shadow = new Image;
		path = _imgPath + "treadmill_shadow.bmp";
		_img_shadow->init(path.c_str(), (int)(165 * GAME_MULTIPLE), (int)(59 * GAME_MULTIPLE), 3, 1);
		_img_shadow->set_frameSection(1, 0, 2, 0.4f);
		break;
	}
	switch (_run_type)
	{
	case FACILITY::TRM_ORANGE_GIRL:
		_img_run = new Image;
		path = _imgPath + "trm_orange_girl.bmp";
		_img_run->init(path.c_str(), (int)(174 * GAME_MULTIPLE), (int)(81 * GAME_MULTIPLE), 6, 1);
		_img_run->set_frameSection(1, 0, 5, 0.13f);
		_img_run_shadow = new Image;
		path = _imgPath + "trm_orange_girl_shadow.bmp";
		_img_run_shadow->init(path.c_str(), (int)(174 * GAME_MULTIPLE), (int)(81 * GAME_MULTIPLE), 6, 1);
		_img_run_shadow->set_frameSection(1, 0, 5, 0.13f);
		// 트레드밀 도는 속도를 다시 잡아준다.
		_img_off->set_frameSection(1, 0, 2, 0.26f);
		_img_shadow->set_frameSection(1, 0, 2, 0.26f);
		break;
	case FACILITY::TRM_YELLOW_GIRL:
		_img_run = new Image;
		path = _imgPath + "trm_yellow_girl.bmp";
		_img_run->init(path.c_str(), (int)(180 * GAME_MULTIPLE), (int)(80 * GAME_MULTIPLE), 6, 1);
		_img_run->set_frameSection(1, 0, 5, 0.18f);
		_img_run_shadow = new Image;
		path = _imgPath + "trm_yellow_girl_shadow.bmp";
		_img_run_shadow->init(path.c_str(), (int)(180 * GAME_MULTIPLE), (int)(80 * GAME_MULTIPLE), 6, 1);
		_img_run_shadow->set_frameSection(1, 0, 5, 0.18f);
		// 트레드밀 도는 속도를 다시 잡아준다.
		_img_off->set_frameSection(1, 0, 2, 0.36f);
		_img_shadow->set_frameSection(1, 0, 2, 0.36f);
		break;
	}
	return S_OK;
}
void Facility::delete_objs()
{
	Release(_img_off);
	Release(_img_shadow);
	Release(_img_run);
	Release(_img_run_shadow);
}
void Facility::draw_objs()
{
	switch (_type)
	{
	case FACILITY::OBJ_TREADMILL:
		if (_img_off != nullptr && _img_shadow != nullptr)
		{
			_img_off->frameRender(get_memDC());
			_img_shadow->frameAlphaRender(get_memDC(), 128);
		}
		break;
	}
	switch (_run_type)
	{
	case FACILITY::TRM_ORANGE_GIRL:
	case FACILITY::TRM_YELLOW_GIRL:
		if (_img_run != nullptr)
		{
			_img_run->frameRender(get_memDC());
			_img_run_shadow->frameAlphaRender(get_memDC(), 128);
		}
		break;
	}
}
void Facility::update_objs()
{
	switch (_type)
	{
	case FACILITY::OBJ_TREADMILL:
		_img_off->frameUpdate(false);
		_img_shadow->frameUpdate(false);
		break;
	}
	switch (_run_type)
	{
	case FACILITY::TRM_ORANGE_GIRL:
	case FACILITY::TRM_YELLOW_GIRL:
		_img_run->frameUpdate(false);
		_img_run_shadow->frameUpdate(false);
		break;
	}
}

HRESULT Facility::init()
{
	set_imgPath("Object/Gym/");
	HRESULT result;
	result = init_objs();
	return result;
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
Facility::Facility(FACILITY::TYPE type)
{
	_type = type;
}
Facility::Facility(FACILITY::TYPE type, FACILITY::RUN_TYPE run_type)
{
	_type = type;
	_run_type = run_type;
}
Facility::~Facility()
{
}

void Facility::set_center(POINT center)
{
	if (_img_off != nullptr)
	{
		_img_off->set_center(center);
	}
	if (_img_on != nullptr)
	{
		_img_on->set_center(center);
	}
	if (_img_shadow != nullptr)
	{
		_img_shadow->set_center(center);
	}
	// 달리기 모션을 중간에 조정한다.
	switch (_run_type)
	{
	case FACILITY::TRM_ORANGE_GIRL:
		center.y = (LONG)(center.y - 35);
		break;
	case FACILITY::TRM_YELLOW_GIRL:
		center.y = (LONG)(center.y - 32);
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
