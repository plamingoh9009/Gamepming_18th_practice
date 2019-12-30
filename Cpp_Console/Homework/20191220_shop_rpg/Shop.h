#pragma once
#include "ItemBase.h"

class Shop: public ItemBase
{
private:
	// ������ �Ĵ� ������ ����� ������ ������ �ִ´�.
	itemList_t _mItem_shop;
	itemList_t _mItem_inven;
	int _money;

public:
	void init_();
	void run_();
	void update_(int, itemList_t);
	itemList_t get_mItem_shop();
	itemList_t get_mItem_inven();
	int get_money();
protected:
	// Ŭ���� �ȿ��� ����ϴ� �Լ��� �����Ѵ�.
	void set_items();

	void show_shopPage();
	void run_pageBuy();
	void run_pageSell();
	void show_pageBuy();
	void show_pageSell();
public:
	Shop();
	~Shop();
};

