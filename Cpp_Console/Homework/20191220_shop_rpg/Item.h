#pragma once
#include "GameBase.h"

class Item
{
private:
	// �������� ���� �Ӽ�
	/*
		_key: ������ ����
		_name: ������ �̸�
		_descripttion: ������ ����
		_damage: �������� �߰� ������
		_armor: �������� �߰� ����
		_bonusHp: �������� �߰� HP, ������ ���� ä���ִ� ��
		_bonusMp: �������� �߰� MP, ������ ���� ä���ִ� ��
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
	// getter �Լ�
	string get_key();
	string get_type();
	string get_descripttion();
	int get_damage();
	int get_armor();
	int get_bonusHp();
	int get_bonusMp();
	int get_price();
	int get_count();
	// setter �Լ�
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

