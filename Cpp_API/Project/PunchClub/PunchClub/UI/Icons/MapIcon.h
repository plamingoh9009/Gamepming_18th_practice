#pragma once
#include "UI/UI.h"

class MapIcon: public UI
{
private:
	MAPICON::TYPE _type = MAPICON::ICON_EMPTY;
	Image * _icon_off;
	Image * _icon_on;
	POINT _center;
	// 건물 아이콘에 사용할 변수
	bool _fIcon = false;
	// 플레이어 아이콘에 사용할 변수
	MAPICON::TYPE _current_location = MAPICON::ICON_EMPTY;
protected:
	HRESULT init_icon();
	void draw_icon();
	void delete_icon();
	void update_icon();
public:
	virtual HRESULT init(MAPICON::TYPE type);
	virtual void release();
	virtual void update();
	virtual void render();
public:
	MapIcon();
	~MapIcon();
public:
	HRESULT set_center(POINT center);
	POINT get_center() { return _center; }
	int get_width() { return _icon_off->get_width(); }
	int get_height() { return _icon_off->get_height(); }
	MAPICON::TYPE get_current_location() { return _current_location; }
	void set_current_location(MAPICON::TYPE location) { _current_location = location; }
};

