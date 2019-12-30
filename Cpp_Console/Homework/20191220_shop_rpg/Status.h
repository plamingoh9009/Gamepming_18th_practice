#pragma once
#include "ItemBase.h"
/*
	Status 클래스는 ItemBase를 상속 받는다.

	현재 스탯창의 변화를 보여주는 클래스
*/
class Status : public ItemBase
{
private:
	// 기존의 스탯이다.
	int _damage;
	int _armor;
	int _hp;
	int _mp;

	// 아이템 스탯의 총합이다.
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

