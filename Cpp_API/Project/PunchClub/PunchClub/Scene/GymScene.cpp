#include "stdafx.h"
#include "GymScene.h"


HRESULT GymScene::init_objs()
{
	init_treadmills();
	return S_OK;
}
void GymScene::delete_objs()
{
	auto iter = _objs.begin();
	for (; iter != _objs.end();)
	{
		Release((*iter));
		iter = _objs.erase(iter);
	}
	delete_treadmills();
	swap(Facilitys(), _objs);
}
void GymScene::draw_objs()
{
	auto iter = _objs.begin();
	for (; iter != _objs.end(); iter++)
	{
		Draw((*iter));
	}
}
void GymScene::update_objs()
{
	auto iter = _objs.begin();
	for (; iter != _objs.end(); iter++)
	{
		(*iter)->update();
	}
}

HRESULT GymScene::init_treadmills()
{
	POINT center;
	_treadmill_mid = new Facility(FACILITY::OBJ_TREADMILL, FACILITY::TRM_YELLOW_GIRL);
	_treadmill_mid->init();
	center.x = (LONG)(WIN_HALF_W + _treadmill_mid->get_width() * 0.5);
	center.y = (LONG)(WIN_HALF_H - _treadmill_mid->get_height());
	_treadmill_mid->set_center(center);
	_objs.push_back(_treadmill_mid);
	_treadmill_left = new Facility(FACILITY::OBJ_TREADMILL, FACILITY::TRM_ORANGE_GIRL);
	_treadmill_left->init();
	_treadmill_left->set_center(PointMake(center.x - 100, center.y));
	_objs.push_back(_treadmill_left);
	_treadmill_right = new Facility(FACILITY::OBJ_TREADMILL);
	_treadmill_right->init();
	_treadmill_right->set_center(PointMake(center.x + 100, center.y));
	_objs.push_back(_treadmill_right);

	return S_OK;
}
void GymScene::delete_treadmills()
{
	Release(_treadmill_left);
	Release(_treadmill_mid);
	Release(_treadmill_right);
}

HRESULT GymScene::init()
{
	add_currentScene_toList(SCENE_GYM);
	set_imgPath("Gym/");
	_bg = new Image;
	string path = _imgPath + "gym_bg.bmp";
	_bg->init(path.c_str(), (int)(682 * GAME_MULTIPLE), (int)(383 * GAME_MULTIPLE));
	// 운동기구들 초기화
	init_objs();
	INGAME_UI->init();
	INGAME_UI->set_fRedButton(true);
	return S_OK;
}
void GymScene::release()
{
	Release(_bg);
	delete_objs();
}
void GymScene::update()
{
	update_scene();
	update_objs();
	INGAME_UI->update();
	change_scene();
}
void GymScene::render()
{
	Draw(_bg, get_memDC());
	draw_objs();
	INGAME_UI->render();
}
GymScene::GymScene()
{
}
GymScene::~GymScene()
{
}
