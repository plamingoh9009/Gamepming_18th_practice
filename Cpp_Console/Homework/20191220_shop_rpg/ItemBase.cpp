#include "ItemBase.h"



void ItemBase::show_itemList(itemList_t mItemList, PAGE_CHOICE p)
{
	itemList_t::iterator iterItemList;

	for (iterItemList = mItemList.begin();
		iterItemList != mItemList.end(); iterItemList++)
	{
		// ���� ���
		if (iterItemList->second.get_type().compare("����") == 0)
		{
			cout << "----------------------------------------";
			cout << "----------------------------------------" << endl;
			cout << iterItemList->second.get_key() << " | " <<
				"���ݷ�: " << iterItemList->second.get_damage() << " | " <<
				//"���� + " << iterShop->second.get_armor() << " | " <<
				"HP+" << iterItemList->second.get_bonusHp() << " | " <<
				"MP+" << iterItemList->second.get_bonusMp() << " | " << endl;
			cout << iterItemList->second.get_descripttion() << " | " <<
				"����: " << iterItemList->second.get_price();
			if (p == PAGE_ONE)
			{
				// PAGE_ONE �̸� �������
				cout << endl;
			}
			else
			{
				// PAGE_TWO �� ���� ���
				cout << " | ";
				cout << "����: " << iterItemList->second.get_count()+1 <<
					endl;
			}

		}
		// �� ���
		if (iterItemList->second.get_type().compare("��") == 0)
		{
			cout << "----------------------------------------";
			cout << "----------------------------------------" << endl;
			cout << iterItemList->second.get_key() << " | " <<
				//"���ݷ�: " << iterShop->second.get_damage() << " | " <<
				"����: " << iterItemList->second.get_armor() << " | " <<
				"HP+" << iterItemList->second.get_bonusHp() << " | " <<
				"MP+" << iterItemList->second.get_bonusMp() << " | " << endl;
			cout << iterItemList->second.get_descripttion() << " | " <<
				"����: " << iterItemList->second.get_price();
			if (p == PAGE_ONE)
			{
				// PAGE_ONE �̸� �������
				cout << endl;
			}
			else
			{
				// PAGE_TWO �� ���� ���
				cout << " | ";
				cout << "����: " << iterItemList->second.get_count()+1 <<
					endl;
			}
		}
		// ��ű� ���
		if (iterItemList->second.get_type().compare("��ű�") == 0)
		{
			cout << "----------------------------------------";
			cout << "----------------------------------------" << endl;
			cout << iterItemList->second.get_key() << " | " <<
				"���ݷ�: " << iterItemList->second.get_damage() << " | " <<
				"����: " << iterItemList->second.get_armor() << " | " <<
				"HP+" << iterItemList->second.get_bonusHp() << " | " <<
				"MP+" << iterItemList->second.get_bonusMp() << " | " << endl;
			cout << iterItemList->second.get_descripttion() << " | " <<
				"����: " << iterItemList->second.get_price();
			if (p == PAGE_ONE)
			{
				// PAGE_ONE �̸� �������
				cout << endl;
			}
			else
			{
				// PAGE_TWO �� ���� ���
				cout << " | ";
				cout << "����: " << iterItemList->second.get_count()+1 <<
					endl;
			}
		}
	}// end of for: myItemList�� ����� ���� ����� �� loop�� �����Ѵ�.
}

ItemBase::ItemBase()
{
}


ItemBase::~ItemBase()
{
}
