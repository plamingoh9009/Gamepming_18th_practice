#pragma once
#include "ItemBase.h"
/*
	Status Ŭ������ ItemBase�� ��� �޴´�.

	���� ����â�� ��ȭ�� �����ִ� Ŭ����
*/
class Status : public ItemBase
{
private:
	// ������ �����̴�.
	int _damage;
	int _armor;
	int _hp;
	int _mp;

	// ������ ������ �����̴�.
	int _damageItem;
	int _armorItem;
	int _hpItem;
	int _mpItem;

	itemList_t _mItem_equip;
public:
	void init_();
	void run_();
	void update_(itemList_t);
protected:
	void show_status();
public:
	Status();
	~Status();
};

