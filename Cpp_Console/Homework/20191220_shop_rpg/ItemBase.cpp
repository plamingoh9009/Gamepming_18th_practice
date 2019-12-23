#include "ItemBase.h"



void ItemBase::show_itemList(itemList_t mItemList, PAGE_CHOICE p)
{
	itemList_t::iterator iterItemList;

	for (iterItemList = mItemList.begin();
		iterItemList != mItemList.end(); iterItemList++)
	{
		// 무기 출력
		if (iterItemList->second.get_type().compare("무기") == 0)
		{
			cout << "----------------------------------------";
			cout << "----------------------------------------" << endl;
			cout << iterItemList->second.get_key() << " | " <<
				"공격력: " << iterItemList->second.get_damage() << " | " <<
				//"방어력 + " << iterShop->second.get_armor() << " | " <<
				"HP+" << iterItemList->second.get_bonusHp() << " | " <<
				"MP+" << iterItemList->second.get_bonusMp() << " | " << endl;
			cout << iterItemList->second.get_descripttion() << " | " <<
				"가격: " << iterItemList->second.get_price();
			if (p == PAGE_ONE)
			{
				// PAGE_ONE 이면 상점출력
				cout << endl;
			}
			else
			{
				// PAGE_TWO 면 개수 출력
				cout << " | ";
				cout << "갯수: " << iterItemList->second.get_count()+1 <<
					endl;
			}

		}
		// 방어구 출력
		if (iterItemList->second.get_type().compare("방어구") == 0)
		{
			cout << "----------------------------------------";
			cout << "----------------------------------------" << endl;
			cout << iterItemList->second.get_key() << " | " <<
				//"공격력: " << iterShop->second.get_damage() << " | " <<
				"방어력: " << iterItemList->second.get_armor() << " | " <<
				"HP+" << iterItemList->second.get_bonusHp() << " | " <<
				"MP+" << iterItemList->second.get_bonusMp() << " | " << endl;
			cout << iterItemList->second.get_descripttion() << " | " <<
				"가격: " << iterItemList->second.get_price();
			if (p == PAGE_ONE)
			{
				// PAGE_ONE 이면 상점출력
				cout << endl;
			}
			else
			{
				// PAGE_TWO 면 개수 출력
				cout << " | ";
				cout << "갯수: " << iterItemList->second.get_count()+1 <<
					endl;
			}
		}
		// 장신구 출력
		if (iterItemList->second.get_type().compare("장신구") == 0)
		{
			cout << "----------------------------------------";
			cout << "----------------------------------------" << endl;
			cout << iterItemList->second.get_key() << " | " <<
				"공격력: " << iterItemList->second.get_damage() << " | " <<
				"방어력: " << iterItemList->second.get_armor() << " | " <<
				"HP+" << iterItemList->second.get_bonusHp() << " | " <<
				"MP+" << iterItemList->second.get_bonusMp() << " | " << endl;
			cout << iterItemList->second.get_descripttion() << " | " <<
				"가격: " << iterItemList->second.get_price();
			if (p == PAGE_ONE)
			{
				// PAGE_ONE 이면 상점출력
				cout << endl;
			}
			else
			{
				// PAGE_TWO 면 개수 출력
				cout << " | ";
				cout << "갯수: " << iterItemList->second.get_count()+1 <<
					endl;
			}
		}
	}// end of for: myItemList의 목록을 전부 출력한 후 loop를 종료한다.
}

bool ItemBase::is_existKey_itemList(string key, itemList_t mItemList)
{
	bool result = false;
	itemList_t::iterator mIter;
	mIter = mItemList.find(key);

	if (mIter != mItemList.end())
	{
		result = true;
	}// end of if: mItem_inven에 key값이 존재한다면
	else
	{
		result = false;
	}// end of else: mItem_inven에 key값이 없다면

	return result;
}

bool ItemBase::is_existType_itemList(string type, itemList_t mItemList)
{
	bool result = false;
	itemList_t::iterator mIter;

	mIter = mItemList.begin();

	for (mIter; mIter != mItemList.end(); mIter++)
	{
		if(mIter->second.get_type() == type)
		{
			result = true;
		}// end of if: mItemList에 type 값이 존재한다면
		else
		{
			result = false;
		}// end of else: mItemList에 type 값이 없다면
	}
	return result;
}

ItemBase::ItemBase()
{
}


ItemBase::~ItemBase()
{
}
