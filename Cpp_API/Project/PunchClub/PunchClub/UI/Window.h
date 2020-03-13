#pragma once
#include "UI.h"
#include "Button.h"

struct InvenSlot
{
	Image * item;
	RECT item_rc;
	POINT item_center;
	RECT slot_rc;
	POINT slot_center;
	RECT green_button_rc;
	POINT green_button_center;
};
struct LeagueSlot
{
	Image * back = nullptr;
	Image * lock_back = nullptr;
	Image * lock = nullptr;
	RECT back_rc;
	RECT lock_back_rc;
	RECT lock_rc;
	POINT slot_center;
	// fore
	Image * icon = nullptr;
	Image * icon_back = nullptr;
	RECT icon_rc;
	RECT icon_back_rc;
	POINT icon_center;
	// Text
	string title;
	string desc_type[2];
	string desc_rank[2];
	string desc_next[2];
	POINT title_pos;
	POINT desc_pos;
	// 버튼
	Image * btn_show;
	Image * btn_start;
	Image * icon_show;
	RECT btn_show_rc;
	RECT icon_show_rc;
	POINT btn_show_center;
};
class Window: public UI
{
private:
	WINDOW::TYPE _type;
	Image * _bg;
	Image * _locked_back;
	// Button
	Button * _red_button;
	// fg 설명
	Image * _fg;
	MyText _fg_title;
	MyText _fg_descr;
	// Inside Window
	Image * _inside;
	// 라인 위치
	POINT _line_pos;
	POINT _line_pos_ver;
	// 리그 슬롯을 위한 렉트
	RECT _league_slots_rc;
	LeagueSlot _league_slot[3];
	// 버스 윈도우를 위한 변수
	Image * _bus;
	MyText _bus_distance_str;
	int _bus_distance = 10;
	Button * _btn_bus;
	Button * _btn_walk;
	bool _fClose;
	bool _fOpen = false;
	bool _fOpenBuild = false;
	bool _fOpenBus = false;
	// 공사장 윈도우를 위한 변수
	Image * _work_jhammer;
	Image * _work_dust;
	Button * _btn_build;
protected:
	HRESULT init_window_bg(WINDOW::TYPE type);
	void delete_window_bg();
	void draw_window_bg();
	// 인벤토리 창을 초기화한다.
	void init_inventory();
	void draw_inventory();
	void delete_inventory();
	// 리그창을 초기화한다.
	void init_league();
	void draw_league();
	void update_league();
	void delete_league();
	// 리그 슬롯 창을 초기화한다.
	void init_league_slots();
	void draw_league_slots();
	void delete_league_slots();
	// 버스 윈도우를 초기화한다.
	HRESULT init_bus_fg();
	void draw_bus();
	void delete_bus();
	void update_bus();
	// bus_str: {string; Data} for description Text
	// bus_dist: {int; Data} that destination how far from player
	string map_bus_distance(string bus_str, int bus_dist);
	// 공사장 윈도우를 초기화한다.
	HRESULT init_build_fg();
	void draw_build();
	void delete_build();
	void update_build();
public:
	void close_window();
public:
	virtual HRESULT init(WINDOW::TYPE type);
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Window();
	~Window();
	bool is_closeWindow() { return _fClose; }
	bool is_openWindow() { return _fOpen; }
	void set_openWindow(bool fResult) { _fOpen = fResult; }
	bool is_openBuild() { return _fOpenBuild; }
	void set_fOpenBuild(bool fResult) { _fOpenBuild = fResult; }
	bool is_openBus() { return _fOpenBus; }
	void set_fOpenBus(bool fResult) { _fOpenBus = fResult; }
};

