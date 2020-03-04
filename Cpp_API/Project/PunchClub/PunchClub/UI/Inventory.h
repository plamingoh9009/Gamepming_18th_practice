#pragma once
#include "UI.h"
#include "RedButton.h"
enum INVEN_TYPE
{
	INVEN_NONE,
	INVEN_FRIGER,
	INVEN_SHOP
};
struct InvenSlot
{
	Image * _item;
	RECT _item_rc;
	POINT _item_center;
	RECT _slot_rc;
	POINT _slot_center;
	RECT _green_button_rc;
	POINT _green_button_center;
};
class Inventory: public UI
{
private:
	INVEN_TYPE _type;
	Image * _bg;
	RECT _bg_rc;
	POINT  _bg_center;
	Image * _locked_back;
	RECT _locked_back_rc;
	POINT _locked_back_pos;
	Image * _slot;
	Image * _green_button;
	RedButton * _red_button;
	// fg Ό³Έν
	Image * _fg;
	RECT _fg_rc;
	POINT _fg_center;
	string _fg_title;
	POINT _fg_title_pos;
	string _fg_descr;
	POINT _fg_descr_pos;
	bool _fClose;
protected:
	void init_default();
	void draw_default();
	void delete_default();
	void init_fg();
	void draw_fg();
	void delete_fg();
public:
	virtual HRESULT init();
	virtual HRESULT init(INVEN_TYPE type);
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Inventory();
	~Inventory();
	bool is_closeInven() { return _fClose; }
};

