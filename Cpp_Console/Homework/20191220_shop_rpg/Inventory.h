#pragma once
#include "Equip.h"

class Inventory : public ItemBase
{
private:
	int _money;
	itemList_t _mItem_inven;
	itemList_t _mItem_equip;
	itemList_t _mItem_shop;
	Equip _equip;
public:
	void init_();
	void run_();
	int get_money();
	itemList_t get_mItem_inven();
	void set_money(int money);

	void update_(int, itemList_t, itemList_t);
protected:
	void delete_item_inventory(string key);
	void insert_item_inventory(string key);
	void delete_item_equip(string key);
	void insert_item_equip(string key);
	string get_keyEquipItem(string type);
	//void update_();
	void show_inventory();

	void run_useItem();
	void run_releaseItem();
public:
	Inventory();
	~Inventory();
};

