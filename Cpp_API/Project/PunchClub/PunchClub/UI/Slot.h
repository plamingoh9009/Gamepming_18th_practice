#pragma once
#include "UI.h"
#include "Button.h"
#include "Icons/Icon.h"

class Slot: public UI
{
private:
	SLOT::TYPE _type;
	SLOT::ITEM _itemType = SLOT::ITM_EMPTY;
	Image * _bg = nullptr;
	Image * _fg = nullptr;
	Image * _fg_back = nullptr;
	MyText _title;
	MyText _descr;
	Button * _btn = nullptr;
protected:
	void init_bg(SLOT::TYPE type);
	void draw_bg();
	void delete_bg();
	void init_item();
	void draw_item();
	void setup_fg_center();
	void setup_text_pos();
	void setup_button();
public:
	// type: {SLOT::TYPE; enum}
	// center: Center for draw slot
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Slot(SLOT::TYPE type);
	Slot(SLOT::TYPE type, SLOT::ITEM itemType);
	~Slot();
public:
	// skill: {SLOT::SKILL; enum}
	void set_slotInfo(SLOT::SKILL skill);
	void set_slotCenter(POINT center);
	void set_slotPos(POINT pos);
	int get_width() { return _bg->get_width(); }
	int get_height() { return _bg->get_height(); }
	POINT get_center() { return _bg->get_center(); }
};