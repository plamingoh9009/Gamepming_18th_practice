#include "Item.h"

Item::Item()
{
	// 생성자에서 모든 변수 초기화
	_key = "";
	_type = "";
	_descripttion = "";
	_damage = 0;
	_armor = 0;
	_bonusHp = 0;
	_bonusMp = 0;
	_price = 0;
	_count = 0;
}


Item::~Item()
{
}

string Item::get_key()
{
	return _key;
}

string Item::get_type()
{
	return _type;
}

string Item::get_descripttion()
{
	return _descripttion;
}

int Item::get_damage()
{
	return _damage;
}

int Item::get_armor()
{
	return _armor;
}

int Item::get_bonusHp()
{
	return _bonusHp;
}

int Item::get_bonusMp()
{
	return _bonusMp;
}

int Item::get_price()
{
	return _price;
}

int Item::get_count()
{
	return _count;
}

void Item::set_key(string key)
{
	_key = key;
}

void Item::set_type(string type)
{
	_type = type;
}

void Item::set_descripttion(string des)
{
	_descripttion = des;
}

void Item::set_damage(int dam)
{
	_damage = dam;
}

void Item::set_armor(int arm)
{
	_armor = arm;
}

void Item::set_bonusHp(int hp)
{
	_bonusHp = hp;
}

void Item::set_bonusMp(int mp)
{
	_bonusMp = mp;
}

void Item::set_price(int price)
{
	_price = price;
}

void Item::set_count(int count)
{
	_count = count;
}
