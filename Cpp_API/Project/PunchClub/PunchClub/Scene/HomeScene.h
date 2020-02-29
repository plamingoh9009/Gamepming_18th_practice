#pragma once
#include "Scene.h"
#include "UI/InGameUI.h"
class HomeScene: public Scene
{
private:
	Image * _bg;
	// 가구, 가전용 변수
	Image * _kitchenTable;
	RECT _kitchenTable_rc;
	POINT _kitchenTable_center;
	Image * _refrigerator;
	RECT _refrigerator_rc;
	POINT _refrigerator_center;
protected:
	void init_furniture();
	void draw_furniture();
	void delete_furniture();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	HomeScene();
	~HomeScene();
};

