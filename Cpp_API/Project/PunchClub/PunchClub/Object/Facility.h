#pragma once
#include "Object.h"
class Facility: public Object
{
private:
	FACILITY::TYPE _type = FACILITY::OBJ_EMPTY;
	FACILITY::RUN_TYPE _run_type = FACILITY::TRM_EMPTY;
	Image * _img_off = nullptr;
	Image * _img_on = nullptr;
	Image * _img_shadow = nullptr;
	Image * _img_runback = nullptr;
	Image * _img_runback_shdw = nullptr;

	Image * _img_run = nullptr;
	Image * _img_run_shadow = nullptr;
	bool _fImgOn = false;
	bool _fImgRun = false;
	bool _fImgRunBack = false;
	bool _fImgRunOnly = false;
protected:
	bool is_frameImg(Image * img);
	void change_player_run();
protected:
	HRESULT init_objs();
	void delete_objs();
	void draw_objs();
	void update_objs();
	void draw_img_run();
	void draw_img_off();
	void draw_img_on();
	void draw_img_runback();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Facility();
	Facility(FACILITY::TYPE type);
	Facility(FACILITY::TYPE type, FACILITY::RUN_TYPE run_type);
	~Facility();
public:
	void set_center(POINT center);
	void set_pos(POINT pos);
	int get_width();
	int get_height();
	POINT get_center() { return _img_off->get_center(); }
};

