#pragma once
#include "GameBase.h"

class Item
{
private:
	// 아이템이 가질 속성
	/*
		_key: 아이템 종류
		_name: 아이템 이름
		_descripttion: 아이템 설명
		_damage: 아이템의 추가 데미지
		_armor: 아이템의 추가 방어력
		_bonusHp: 아이템의 추가 HP, 포션의 경우는 채워주는 양
		_bonusMp: 아이템의 추가 MP, 포션의 경우는 채워주는 양
	*/
	string _key;
	string _type;
	string _descripttion;
	int _damage;
	int _armor;
	int _bonusHp;
	int _bonusMp;
	int _price;
	int _count;
public:
	// getter 함수
	string get_key();
	string get_type();
	string get_descripttion();
	int get_damage();
	int get_armor();
	int get_bonusHp();
	int get_bonusMp();
	int get_price();
	int get_count();
	// setter 함수
	void set_key(string key);
	void set_type(string name);
	void set_descripttion(string des);
	void set_damage(int dam);
	void set_armor(int arm);
	void set_bonusHp(int hp);
	void set_bonusMp(int mp);
	void set_price(int price);
	void set_count(int count);

public:
	Item();
	~Item();
};

