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
	// ��ư
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
	// fg ����
	Image * _fg;
	string _fg_title;
	POINT _fg_title_pos;
	string _fg_descr;
	POINT _fg_descr_pos;
	// ���� ��ġ
	POINT _line_pos;
	POINT _line_pos_ver;
	// ���� ������ ���� ��Ʈ
	RECT _league_slots_rc;
	LeagueSlot _league_slot[3];
	bool _fClose;
	bool _fOpenBus = false;
protected:
	HRESULT init_window_bg(WINDOW::TYPE type);
	void delete_window_bg();
	void draw_window_bg();
	// �κ��丮 â�� �ʱ�ȭ�Ѵ�.
	void init_inventory();
	void draw_inventory();
	void delete_inventory();
	// ����â�� �ʱ�ȭ�Ѵ�.
	void init_league();
	void draw_league();
	void update_league();
	void delete_league();
	// ���� ���� â�� �ʱ�ȭ�Ѵ�.
	void init_league_slots();
	void draw_league_slots();
	void delete_league_slots();
public:
	// ����â�� ���� ���� ���Ѵ�.
	void update_fOpenBus();
public:
	virtual HRESULT init(WINDOW::TYPE type);
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Window();
	~Window();
	bool is_closeWindow() { return _fClose; }
	bool is_openBus() { return _fOpenBus; }
};

