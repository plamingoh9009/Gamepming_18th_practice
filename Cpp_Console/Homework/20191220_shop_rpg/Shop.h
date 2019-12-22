#pragma once
#include "ItemBase.h"

class Shop: public ItemBase
{
private:
	// 상점에 파는 아이템 목록을 맵으로 가지고 있는다.
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
	// 클래스 안에서 사용하는 함수를 정의한다.
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

