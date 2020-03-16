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

	Image * _img_run = nullptr;
	Image * _img_run_shadow = nullptr;
protected:
	HRESULT init_objs();
	void delete_objs();
	void draw_objs();
	void update_objs();
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
	int get_width() { return _img_off->get_width(); }
	int get_height() { return _img_off->get_height(); }
};

