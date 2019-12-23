#include "Status.h"



void Status::init_()
{
	_damage = 10;
	_armor = 1;
	_hp = 50;
	_mp = 8;
}

void Status::run_()
{
	show_status();
}

void Status::update_(itemList_t mItem_equip)
{
	_mItem_equip = mItem_equip;
}

void Status::show_status()
{
	// _mItem_equip�� �������� �����Ѵٸ� ���ؼ� �����ش�.
	itemList_t::iterator mIter;
	// ���������� �������� ��ġ�� �����Ѵ�.
	int damage_item = 0;
	int armor_item = 0;
	int hp_item = 0;
	int mp_item = 0;
	string itemType = "";

	mIter = _mItem_equip.begin();
	for (mIter; mIter != _mItem_equip.end(); mIter++)
	{
		itemType = mIter->second.get_type();

		// ������ ���
		if(itemType.compare("����") == 0)
		{
			// ��, hp, mp
			damage_item += mIter->second.get_damage();
			hp_item += mIter->second.get_bonusHp();
			mp_item += mIter->second.get_bonusMp();
		}// end of if: ������� ������
		else if (itemType.compare("��") == 0)
		{
			// ��, hp, mp
			armor_item += mIter->second.get_armor();
			hp_item += mIter->second.get_bonusHp();
			mp_item += mIter->second.get_bonusMp();
		}// end of if: ������� �����
		else if (itemType.compare("��ű�") == 0)
		{
			damage_item += mIter->second.get_damage();
			armor_item += mIter->second.get_armor();
			hp_item += mIter->second.get_bonusHp();
			mp_item += mIter->second.get_bonusMp();
		}// end of if: ������� ��ű����
	}// end of for: ���� ���â�� �������� �����Ѵٸ� loop

	// ���� ���Ƽ� ��� �������� ���⼭ ��¹��� �����ش�.
	cout << endl;
	cout << "*** [����â] ***" << endl;
	//cout << "----------------------------------------" << endl;
	cout << " | " << "HP: \t\t" << _hp << " + " << hp_item << "    ";
	cout << " | " << "MP: \t" << _mp << " + " << mp_item << endl;

	cout << " | " << "���ݷ�: \t" << _damage << " + " << damage_item << "    ";
	cout << " | " << "����: \t" << _armor << " + " << armor_item << endl;
	cout << endl << endl;
}

Status::Status()
{
}


Status::~Status()
{
}
