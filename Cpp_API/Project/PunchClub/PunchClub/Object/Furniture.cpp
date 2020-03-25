#include "stdafx.h"
#include "Furniture.h"
#include "Player.h"
HRESULT Furniture::init_objs()
{
	string path;
	switch (_type)
	{
	case MYOBJECT::OBJ_FRIGER:
		_img_off = new Image;
		path = _imgPath + "Refrigerator.bmp";
		_img_off->init(path.c_str(), (int)(48 * GAME_MULTIPLE), (int)(87 * GAME_MULTIPLE));
		_img_on = new Image;
		path = _imgPath + "Refrigerator_select.bmp";
		_img_on->init(path.c_str(), (int)(48 * GAME_MULTIPLE), (int)(87 * GAME_MULTIPLE));
		break;
	case MYOBJECT::OBJ_SOFA:
		_img_off = new Image;
		path = _imgPath + "Sofa.bmp";
		_img_off->init(path.c_str(), (int)(111 * GAME_MULTIPLE), (int)(53 * GAME_MULTIPLE));
		_img_on = new Image;
		path = _imgPath + "Sofa_select.bmp";
		_img_on->init(path.c_str(), (int)(111 * GAME_MULTIPLE), (int)(53 * GAME_MULTIPLE));
		break;
	case MYOBJECT::OBJ_TV:
		_img_off = new Image;
		path = _imgPath + "TV.bmp";
		_img_off->init(path.c_str(), (int)(147 * GAME_MULTIPLE), (int)(68 * GAME_MULTIPLE));
		_img_on = new Image;
		path = _imgPath + "TV_select.bmp";
		_img_on->init(path.c_str(), (int)(147 * GAME_MULTIPLE), (int)(68 * GAME_MULTIPLE));
		break;
	case MYOBJECT::OBJ_AQUARIUM:
		_img_off = new Image;
		path = _imgPath + "Aquarium.bmp";
		_img_off->init(path.c_str(), (int)(230 * GAME_MULTIPLE), (int)(78 * GAME_MULTIPLE), 5, 1);
		_img_off->set_frameSection(1, 0, 4, 0.1f);
		_img_off_fg = new Image;
		path = _imgPath + "Aquarium_fg.bmp";
		_img_off_fg->init(path.c_str(), (int)(36 * GAME_MULTIPLE), (int)(52 * GAME_MULTIPLE));
		_fImgOffOnly = true;
		break;
	case MYOBJECT::OBJ_FAN:
		_img_off = new Image;
		path = _imgPath + "Fan.bmp";
		_img_off->init(path.c_str(), (int)(183 * GAME_MULTIPLE), (int)(76 * GAME_MULTIPLE), 3, 1);
		_img_off->set_frameSection(1, 2, 0, 0.09f);
		_fImgOffOnly = true;
		break;
	case MYOBJECT::OBJ_CLOCK:
		_img_off = new Image;
		path = _imgPath + "Clock.bmp";
		_img_off->init(path.c_str(), (int)(152 * GAME_MULTIPLE), (int)(43 * GAME_MULTIPLE), 8, 1);
		_img_off->set_frameSection(1, 0, 7, 0.09f);	//8������
		_fImgOffOnly = true;
		break;
	case MYOBJECT::OBJ_KITCHEN_TABLE:
		_img_off = new Image;
		path = _imgPath + "Kitchen_table.bmp";
		_img_off->init(path.c_str(), (int)(142 * GAME_MULTIPLE), (int)(216 * GAME_MULTIPLE));
		_fImgOffOnly = true;
		break;
	case MYOBJECT::OBJ_STAND:
		_img_off = new Image;
		path = _imgPath + "StandLight.bmp";
		_img_off->init(path.c_str(), (int)(31 * GAME_MULTIPLE), (int)(78 * GAME_MULTIPLE));
		_fImgOffOnly = true;
		break;
	case MYOBJECT::OBJ_TABLE:
		_img_off = new Image;
		path = _imgPath + "Table.bmp";
		_img_off->init(path.c_str(), (int)(142 * GAME_MULTIPLE), (int)(84 * GAME_MULTIPLE));
		_fImgOffOnly = true;
		break;
	case MYOBJECT::OBJ_BOOKSHELF:
		_img_off = new Image;
		path = _imgPath + "Bookshelf.bmp";
		_img_off->init(path.c_str(), (int)(48 * GAME_MULTIPLE), (int)(175 * GAME_MULTIPLE));
		_fImgOffOnly = true;
		break;
	case MYOBJECT::OBJ_PHONE:
		_img_off = new Image;
		path = _imgPath + "Phone.bmp";
		_img_off->init(path.c_str(), (int)(40 * GAME_MULTIPLE), (int)(36 * GAME_MULTIPLE));
		_fImgOffOnly = true;
		break;
	}
	switch (_run_type)
	{
	case MYOBJECT::SOFA_PLAYER:
		// Run img
		_img_run = new Image;
		path = _imgPath + "Sofa_sleep.bmp";
		_img_run->init(path.c_str(), (int)(156 * GAME_MULTIPLE), (int)(57 * GAME_MULTIPLE), 2, 1);
		_img_run->set_frameSection(1, 0, 1, 1.0f);
		break;
	case MYOBJECT::TV_PLAYER:
		// Run img
		_img_run = new Image;
		path = _imgPath + "TV_watch.bmp";
		_img_run->init(path.c_str(), (int)(462 * GAME_MULTIPLE), (int)(76 * GAME_MULTIPLE), 3, 1);
		_img_run->set_frameSection(1, 0, 2, 0.3f);
		_fImgRunOnly = true;
		break;
	}
	return S_OK;
}
void Furniture::update_objImgFrame(Image * img)
{
	switch (_type)
	{
	case MYOBJECT::OBJ_FAN:
		img->frameUpdate(false, true);
		break;
	default:
		img->frameUpdate(false);
		break;
	}
}
void Furniture::change_player_run()
{
	switch (_run_type)
	{
	case MYOBJECT::SOFA_PLAYER:
		change_player_actions(PLAYER_SET::ACTION_SLEEP_SOFA);
		break;
	case MYOBJECT::TV_PLAYER:
		change_player_actions(PLAYER_SET::ACTION_WATCH_TV);
		break;
	}
}
void Furniture::runType_case_toUpdate()
{
	// Empty.. coding when you need
}
HRESULT Furniture::init()
{
	set_imgPath("Object/Home/");
	init_objs();
	return S_OK;
}
void Furniture::release()
{
	delete_objs();
}
void Furniture::update()
{
	update_objs();
}
void Furniture::render()
{
	draw_objs();
}

Furniture::Furniture()
{
}
Furniture::Furniture(MYOBJECT::TYPE type)
{
	_type = type;
}
Furniture::Furniture(MYOBJECT::TYPE type, MYOBJECT::RUN_TYPE run_type)
{
	_type = type;
	_run_type = run_type;
}
Furniture::~Furniture()
{
}

void Furniture::set_furniture_center(POINT center)
{
	set_center(center);
}
void Furniture::set_furniture_pos(POINT pos)
{
	set_pos(pos);
	switch (_type)
	{
	case MYOBJECT::OBJ_AQUARIUM:
		pos.x = (LONG)(pos.x + 12);
		pos.y = (LONG)(pos.y - 8);
		set_img_off_fg_pos(pos);
		break;
	case MYOBJECT::OBJ_SOFA:
		pos.x = (LONG)(pos.x + 20);
		pos.y = (LONG)(pos.y + 18);
		set_img_run_pos(pos);
		break;
	}
}
