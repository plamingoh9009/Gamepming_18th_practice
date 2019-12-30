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
	// _mItem_equip에 아이템이 존재한다면 더해서 보여준다.
	itemList_t::iterator mIter;
	// 아이템으로 더해지는 수치를 선언한다.
	int damage_item = 0;
	int armor_item = 0;
	int hp_item = 0;
	int mp_item = 0;
	string itemType = "";

	mIter = _mItem_equip.begin();
	for (mIter; mIter != _mItem_equip.end(); mIter++)
	{
		itemType = mIter->second.get_type();

		// 무기인 경우
		if(itemType.compare("무기") == 0)
		{
			// 공, hp, mp
			damage_item += mIter->second.get_damage();
			hp_item += mIter->second.get_bonusHp();
			mp_item += mIter->second.get_bonusMp();
		}// end of if: 장비템이 무기라면
		else if (itemType.compare("방어구") == 0)
		{
			// 방, hp, mp
			armor_item += mIter->second.get_armor();
			hp_item += mIter->second.get_bonusHp();
			mp_item += mIter->second.get_bonusMp();
		}// end of if: 장비템이 방어구라면
		else if (itemType.compare("장신구") == 0)
		{
			damage_item += mIter->second.get_damage();
			armor_item += mIter->second.get_armor();
			hp_item += mIter->second.get_bonusHp();
			mp_item += mIter->second.get_bonusMp();
		}// end of if: 장비템이 장신구라면
	}// end of for: 만약 장비창에 아이템이 존재한다면 loop

	// 루프 돌아서 계산 끝났으면 여기서 출력문을 보여준다.
	cout << endl;
	cout << "*** [스탯창] ***" << endl;
	//cout << "----------------------------------------" << endl;
	cout << " | " << "HP: \t\t" << _hp << " + " << hp_item << "    ";
	cout << " | " << "MP: \t" << _mp << " + " << mp_item << endl;

	cout << " | " << "공격력: \t" << _damage << " + " << damage_item << "    ";
	cout << " | " << "방어력: \t" << _armor << " + " << armor_item << endl;
	cout << endl << endl;
}

Status::Status()
{
}


Status::~Status()
{
}
