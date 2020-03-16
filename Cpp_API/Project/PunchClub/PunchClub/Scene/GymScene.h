#pragma once
#include "Scene.h"
#include "UI/InGameUI.h"
class GymScene: public Scene
{
private:
	typedef vector<Object *> Facilitys;
private:
	Image * _bg;
	Facilitys _objs;
	Facility * _treadmill_left;
	Facility * _treadmill_mid;
	Facility * _treadmill_right;
protected:
	HRESULT init_objs();
	void delete_objs();
	void draw_objs();
	void update_objs();
	HRESULT init_treadmills();
	void delete_treadmills();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	GymScene();
	~GymScene();
};

