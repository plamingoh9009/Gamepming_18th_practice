#pragma once
#include "ItemBase.h"
#include "Shop.h"
#include "Inventory.h"

class MainGame : public ItemBase
{
private:
	// 여기서 샵과 인벤정보를 가지고 있어야 두 정보간 교류가능
	Shop * _shop;
	Inventory * _inven;
	bool _isRunOver;

	// 여기서 공유할 데이터를 선언한다.
	int _money;
	itemList_t _mItem_shop;
	itemList_t _mItem_inven;
	itemList_t _mItem_equip;

	// 상속하면 안되는 함수다.
	void move_toShop();
	void move_toInven();
public:
	// 메인에서 콜할 수 있는 함수다.
	void init_();
	void run_();
protected:
	void show_mainPage();

	void exit_();
public:
	MainGame();
	~MainGame();
};

