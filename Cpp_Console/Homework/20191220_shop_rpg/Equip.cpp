#include "Equip.h"



void Equip::update_(itemList_t mItem_inven, itemList_t mItem_equip)
{
	_mItem_inven = mItem_inven;
	_mItem_equip = mItem_equip;
}

itemList_t Equip::get_mItem_equip()
{
	return _mItem_equip;
}

itemList_t Equip::get_mItem_inven()
{
	return _mItem_inven;
}

void Equip::show_equip()
{
	show_itemList(_mItem_equip, PAGE_TWO);
}

Equip::Equip()
{
}


Equip::~Equip()
{
}
