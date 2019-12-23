#include "Inventory.h"

void Inventory::init_()
{
	// �ʱ��ڱ� 10000�� ItemBase�� ���ε��Ѵ�.
	_money = 10000;
}

void Inventory::run_()
{
	// �����ִ� ����� �� �� �� �����ְ�, ���â �� �����ְ�
	show_inventory();

	// ���â �ʱ�ȭ, ������Ʈ
	/*_equip.update_(_mItem_inven, _mItem_equip);
	_equip.show_equip();*/

	// 1. ������ ���, 2. ��� ����
	cout << "[1. ������ ���]  " << "[2. ��� ����]  " <<
		"\t [0. �ڷΰ���]" << endl;

	int myChoice = input_choice();

	switch (myChoice)
	{
	case PAGE_ONE:
		//run_useItem() ���Ѵ�.
		run_useItem();
		break;
	case PAGE_TWO:
		//run_releaseItem() ���Ѵ�.
		run_releaseItem();
		break;
	case PAGE_EXIT:
		// �ڷΰ��� ������ �ƹ��͵� ���Ѵ�.
		break;
	}// end of switch: myChoice�� �������� ����, ��� �������� ���Ѵ�.
}

void Inventory::show_inventory()
{
	system("cls");

	// �첫�� �Ȳ��� ���� ����.
	cout << "*** �κ��丮 *** " << endl;
	cout << endl;

	// �����ٰ� �ִٸ� �� �����ְ�, ���ٸ� �κ��丮�� ����ٰ� �˸���.
	cout << "[������: " << _money << " ��] \t";
	cout << "[�ڷΰ���: q, Q]" << endl;

	if (_mItem_inven.size() == 0)
	{
		show_itemList(_mItem_inven, PAGE_TWO);
		cout << "�κ��丮�� ����ִ�. " << endl;
	}
	else
	{
		show_itemList(_mItem_inven, PAGE_TWO);
	}

	// ���⼭ ���â ������.
	cout << endl;
	cout << "*** ���â *** " << endl;
	cout << endl;

	// ���â �ʱ�ȭ, ������Ʈ
	_equip.update_(_mItem_inven, _mItem_equip);
	_equip.show_equip();
}

void Inventory::run_useItem()
{
	while (true)
	{
		string myInput;

		cout << "[����� ������]: ";
		cin >> myInput;

		if (myInput.compare("q") == 0 ||
			myInput.compare("Q") == 0 ||
			myInput.compare("����") == 0)
		{
			/*cout << "������ �׽�Ʈ" << endl;
			Sleep(1000);*/
			break;
		}// end of if: myIput�� q, Q, ���� ��� Ż���Ѵ�.

		// �κ��丮, ���â ���ͷ����� ����
		itemList_t::iterator mIter_inven;
		itemList_t::iterator mIter_equip;
		itemList_t::iterator mIter_shop;
		mIter_shop = _mItem_shop.find(myInput);
		// �κ��丮���� ����� �������� Ÿ��
		string itemType = "";
		// ���� ����ϰ� �ִ� �������� Ÿ��
		string keyEquipItem = "";

		// ���� ����� �������� inventory�� �����Ѵٸ�
		if (is_existKey_itemList(myInput, _mItem_inven) == true)
		{
			mIter_inven = _mItem_inven.find(myInput);
			itemType = mIter_inven->second.get_type();

			if (is_existType_itemList(itemType, _mItem_equip) == false)
			{
				insert_item_equip(myInput);
			}// end of if: ���â�� ���� type �������� ���ٸ�
			else
			{
				// ������ �������� delete �ϰ�
				keyEquipItem = get_keyEquipItem(itemType);
				delete_item_equip(keyEquipItem);

				// ����� �������� insert �Ѵ�.
				insert_item_equip(myInput);
			}// end of else: ���â�� ���� type �������� ���� �ִٸ�

			// ��� �޼���
			cout << mIter_shop->second.get_key() <<
				" (��/��)����ߴ�." << endl;

			Sleep(1000);
			//continue;
		}// end of if: ���� ����� �������� inventory�� �����Ѵٸ�
		else
		{
			show_warnMessage(WARN_INVALID_INPUT);
			Sleep(1000);
		}// end of else: inven�� ���ٸ�, �߸� �Է��� ��.

		// �������� ���⼭ �κ��丮�� �ٽ� �����ش�.
		system("cls");
		show_inventory();

	}// end of while:����� ������ loop
	//Sleep(1000)
}

void Inventory::run_releaseItem()
{
	//cout << "release item" << endl;
	while (true)
	{
		string myInput;

		cout << "[������ ������]: ";
		cin >> myInput;

		if (myInput.compare("q") == 0 ||
			myInput.compare("Q") == 0 ||
			myInput.compare("����") == 0)
		{
			/*cout << "������ �׽�Ʈ" << endl;
			Sleep(1000);*/
			break;
		}// end of if: myIput�� q, Q, ���� ��� Ż���Ѵ�.

		// ����� ���ͷ����� ����
		itemList_t::iterator mIter_shop;
		mIter_shop = _mItem_shop.find(myInput);

		// ���� ������ �������� equip�� �����Ѵٸ�
		if (is_existKey_itemList(myInput, _mItem_equip) == true)
		{
			delete_item_equip(myInput);
			
			// ���� �޼���
			cout << mIter_shop->second.get_key() <<
				" (��/��)�����ߴ�." << endl;

			Sleep(1000);
		}// end of if: ���� ������ �������� equip�� �����Ѵٸ�
		else
		{
			show_warnMessage(WARN_INVALID_INPUT);
			Sleep(1000);
			//continue;
		}// end of else: ���� ������ �������� equip�� ���ٸ� -> �߸� �Է���.

		// ���⼭ �κ��丮�� �ٽ� �����ش�.
		system("cls");
		show_inventory();
	}// end of while: ������ ������ loop
}

void Inventory::delete_item_inventory(string key)
{
	// ������ Ȯ���ؼ� 0�̸� erase, �ƴϸ�, ������ -1
	itemList_t::iterator mIter;
	mIter = _mItem_inven.find(key);

	int itemCount = 0;
	itemCount = mIter->second.get_count();

	if (itemCount == 0)
	{
		// ������ ī��Ʈ�� ���ٸ� Delete
		_mItem_inven.erase(mIter);
	}// end of if: �������� 1�� ��(count�� 0)�̶��
	else
	{
		// ���� ���ڿ��� 1���� ����.
		mIter->second.set_count(itemCount - 1);
	}// end of else: �������� ���������
}

void Inventory::insert_item_inventory(string key)
{
	// ���ٸ� �׳� �ø���.
	itemList_t::iterator mIter;
	itemList_t::iterator mIter_shop;
	mIter = _mItem_inven.find(key);
	mIter_shop = _mItem_shop.find(key);

	int itemCount = 0;

	if (mIter != _mItem_inven.end())
	{
		// �κ��丮�� �ִٸ� count�� ++, insert�� �ʿ� ����.
		itemCount = mIter->second.get_count();
		mIter->second.set_count(itemCount + 1);
	}// end of if: �κ��丮�� �������� �̹� �����Ѵٸ�
	else
	{
		// �κ��丮�� �� �������� �׳� �ø���.
		_mItem_inven.insert(
			make_pair(key, mIter_shop->second)
		);

	}// end of else: �κ��丮�� �������� ���ٸ�
}

void Inventory::delete_item_equip(string key)
{
	itemList_t::iterator mIter_equip;
	mIter_equip = _mItem_equip.find(key);

	// ���â���� ������ �׼��� 
	// 1. �κ��丮�� insert 
	insert_item_inventory(key);
	// 2. ���â���� delete
	_mItem_equip.erase(mIter_equip);
}

void Inventory::insert_item_equip(string key)
{
	itemList_t::iterator mIter_shop;
	mIter_shop = _mItem_shop.find(key);

	// ���â�� �ִ� �׼���
	// 1. �κ��丮���� delete
	delete_item_inventory(key);
	// 2. ���â���� insert
	_mItem_equip.insert(
		make_pair(key, mIter_shop->second)
	);
}

int Inventory::get_money()
{
	return _money;
}

itemList_t Inventory::get_mItem_inven()
{
	return _mItem_inven;
}

itemList_t Inventory::get_mItem_equip()
{
	return _mItem_equip;
}

void Inventory::set_money(int money)
{
	_money = money;
}

void Inventory::update_(int money, itemList_t mItem_inven,
	itemList_t mItem_shop)
{
	// �����ݰ� �κ��丮 ����Ʈ�� �޾Ƽ� ������Ʈ�Ѵ�.
	_money = money;
	_mItem_inven = mItem_inven;
	_mItem_shop = mItem_shop;
}

string Inventory::get_keyEquipItem(string type)
{
	itemList_t::iterator mIter;
	string typeEquip = "";
	string key = "";

	mIter = _mItem_equip.begin();
	for (mIter; mIter != _mItem_equip.end(); mIter++)
	{
		typeEquip = mIter->second.get_type();
		if (type.compare(typeEquip) == 0)
		{
			key = mIter->first;
		}// end of if: ���â�� ���� Ÿ���� �������� ���� �ִٸ�
	}// end of for: ���â�� ���� ã�´�.

	return key;
}

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}
