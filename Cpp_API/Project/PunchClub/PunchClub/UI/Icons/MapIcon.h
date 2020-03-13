#pragma once
#include "UI/UI.h"

class MapIcon: public UI
{
private:
	MAPICON::TYPE _type = MAPICON::ICN_EMPTY;
	Image * _icon_off;
	Image * _icon_on;
	// 건물 아이콘에 사용할 변수
	bool _fIcon = false;
	bool _fOpenBus = false;
protected:
	// Player Icon
	void update_playerIcon();
	bool is_player_atHere();
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
	POINT get_center() { return _icon_off->get_center(); }
	int get_width() { return _icon_off->get_width(); }
	int get_height() { return _icon_off->get_height(); }
	bool is_playerIcon_moveOK() { return _fplayerIcon_move; }
	MAPICON::TYPE get_current_location() { return _playerIcon_location; }
	void set_current_location(MAPICON::TYPE location) { _playerIcon_location = location; }
	// 버스 윈도우 컨트롤
	bool get_fOpenBus() { return _fOpenBus; }
	void set_fOpenBus(bool fResult) { _fOpenBus = fResult; }
};