#pragma once
#include "ItemBase.h"

class Equip : public ItemBase
{
private:
	itemList_t _mItem_equip;
	itemList_t _mItem_inven;
public:
	void update_(itemList_t, itemList_t);
	itemList_t get_mItem_equip();
	itemList_t get_mItem_inven();

	void show_equip();
public:
	Equip();
	~Equip();
};

