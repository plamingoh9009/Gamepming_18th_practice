#pragma once
#include "ItemBase.h"
#include "Shop.h"
#include "Inventory.h"

class MainGame : public ItemBase
{
private:
	// ���⼭ ���� �κ������� ������ �־�� �� ������ ��������
	Shop * _shop;
	Inventory * _inven;
	bool _isRunOver;

	// ���⼭ ������ �����͸� �����Ѵ�.
	int _money;
	itemList_t _mItem_shop;
	itemList_t _mItem_inven;
	itemList_t _mItem_equip;

	// ����ϸ� �ȵǴ� �Լ���.
	void move_toShop();
	void move_toInven();
public:
	// ���ο��� ���� �� �ִ� �Լ���.
	void init_();
	void run_();
protected:
	void show_mainPage();

	void exit_();
public:
	MainGame();
	~MainGame();
};

