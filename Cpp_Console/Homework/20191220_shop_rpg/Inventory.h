#pragma once
#include "Equip.h"

class Inventory : public ItemBase
{
private:
	int _money;
	itemList_t _mItem_inven;
	itemList_t _mItem_equip;
	Equip _equip;
public:
	void init_();
	void run_();
	int get_money();
	itemList_t get_mItem_inven();
	void set_money(int money);

	void update_(int, itemList_t);
protected:
	//void update_();
	void show_inventory();

	void run_useItem();
	void run_releaseItem();
public:
	Inventory();
	~Inventory();
};

