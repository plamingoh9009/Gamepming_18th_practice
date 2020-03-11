#pragma once
#include "UI.h"
namespace SLOT
{
	enum TYPE
	{
		SLOT_EMPTY,
		SLOT_ACTIVE_SKILL
	};
	enum SKILL
	{
		SKILL_EMPTY,
		SKILL_BLOCK,
		SKILL_DODGE,
		SKILL_PUNCH
	};
}
class Slot: public UI
{
private:
	SLOT::TYPE _type;
	Image * _bg = nullptr;
	RECT * _bg_rc = nullptr;
protected:
	void init_bg(SLOT::TYPE type);
	void draw_bg();
	void delete_bg();
public:
	// type: {SLOT::TYPE; enum}
	// center: Center for draw slot
	virtual HRESULT init(SLOT::TYPE type);
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Slot();
	~Slot();
public:
	// skill: {SLOT::SKILL; enum}
	void set_slotInfo(SLOT::SKILL skill);
	void set_slotCenter(POINT center);
	int get_width() { return _bg->get_width(); }
	int get_height() { return _bg->get_height(); }
};