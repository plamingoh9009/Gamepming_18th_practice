#include "Inventory.h"

void Inventory::init_()
{
	// 초기자금 10000을 ItemBase에 업로드한다.
	_money = 10000;
}

void Inventory::run_()
{
	// 보여주는 모양은 내 템 쭉 보여주고, 장비창 쭉 보여주고
	show_inventory();

	// 장비창 초기화, 업데이트
	/*_equip.update_(_mItem_inven, _mItem_equip);
	_equip.show_equip();*/

	// 1. 아이템 사용, 2. 장비 해제
	cout << "[1. 아이템 사용]  " << "[2. 장비 해제]  " <<
		"\t [0. 뒤로가기]" << endl;

	int myChoice = input_choice();

	switch (myChoice)
	{
	case PAGE_ONE:
		//run_useItem() 콜한다.
		run_useItem();
		break;
	case PAGE_TWO:
		//run_releaseItem() 콜한다.
		run_releaseItem();
		break;
	case PAGE_EXIT:
		// 뒤로가기 누르면 아무것도 안한다.
		break;
	}// end of switch: myChoice로 아이템을 쓸지, 장비를 해제할지 정한다.
}

void Inventory::show_inventory()
{
	system("cls");

	// 살껀지 팔껀지 고르는 거임.
	cout << "*** 인벤토리 *** " << endl;
	cout << endl;

	// 보여줄게 있다면 쭉 보여주고, 없다면 인벤토리가 비었다고 알린다.
	cout << "[소지금: " << _money << " 원] \t";
	cout << "[뒤로가기: q, Q]" << endl;

	if (_mItem_inven.size() == 0)
	{
		show_itemList(_mItem_inven, PAGE_TWO);
		cout << "인벤토리가 비어있다. " << endl;
	}
	else
	{
		show_itemList(_mItem_inven, PAGE_TWO);
	}

	// 여기서 장비창 보여줌.
	cout << endl;
	cout << "*** 장비창 *** " << endl;
	cout << endl;

	// 장비창 초기화, 업데이트
	_equip.update_(_mItem_inven, _mItem_equip);
	_equip.show_equip();
}

void Inventory::run_useItem()
{
	while (true)
	{
		string myInput;

		cout << "[사용할 아이템]: ";
		cin >> myInput;

		if (myInput.compare("q") == 0 ||
			myInput.compare("Q") == 0 ||
			myInput.compare("ㅂㅂ") == 0)
		{
			/*cout << "나가기 테스트" << endl;
			Sleep(1000);*/
			break;
		}// end of if: myIput이 q, Q, ㅂㅂ 라면 탈출한다.

		// 인벤토리, 장비창 이터레이터 선언
		itemList_t::iterator mIter_inven;
		itemList_t::iterator mIter_equip;
		itemList_t::iterator mIter_shop;
		mIter_shop = _mItem_shop.find(myInput);
		// 인벤토리에서 사용할 아이템의 타입
		string itemType = "";
		// 내가 장비하고 있는 아이템의 타입
		string keyEquipItem = "";

		// 내가 사용할 아이템이 inventory에 존재한다면
		if (is_existKey_itemList(myInput, _mItem_inven) == true)
		{
			mIter_inven = _mItem_inven.find(myInput);
			itemType = mIter_inven->second.get_type();

			if (is_existType_itemList(itemType, _mItem_equip) == false)
			{
				insert_item_equip(myInput);
			}// end of if: 장비창에 같은 type 아이템이 없다면
			else
			{
				// 장착한 아이템을 delete 하고
				keyEquipItem = get_keyEquipItem(itemType);
				delete_item_equip(keyEquipItem);

				// 사용할 아이템을 insert 한다.
				insert_item_equip(myInput);
			}// end of else: 장비창에 같은 type 아이템을 끼고 있다면

			// 사용 메세지
			cout << mIter_shop->second.get_key() <<
				" (을/를)사용했다." << endl;

			Sleep(1000);
			//continue;
		}// end of if: 내가 사용할 아이템이 inventory에 존재한다면
		else
		{
			show_warnMessage(WARN_INVALID_INPUT);
			Sleep(1000);
		}// end of else: inven에 없다면, 잘못 입력한 것.

		// 지웠으면 여기서 인벤토리를 다시 보여준다.
		system("cls");
		show_inventory();

	}// end of while:사용할 아이템 loop
	//Sleep(1000)
}

void Inventory::run_releaseItem()
{
	//cout << "release item" << endl;
	while (true)
	{
		string myInput;

		cout << "[해제할 아이템]: ";
		cin >> myInput;

		if (myInput.compare("q") == 0 ||
			myInput.compare("Q") == 0 ||
			myInput.compare("ㅂㅂ") == 0)
		{
			/*cout << "나가기 테스트" << endl;
			Sleep(1000);*/
			break;
		}// end of if: myIput이 q, Q, ㅂㅂ 라면 탈출한다.

		// 사용할 이터레이터 선언
		itemList_t::iterator mIter_shop;
		mIter_shop = _mItem_shop.find(myInput);

		// 내가 해제할 아이템이 equip에 존재한다면
		if (is_existKey_itemList(myInput, _mItem_equip) == true)
		{
			delete_item_equip(myInput);
			
			// 해제 메세지
			cout << mIter_shop->second.get_key() <<
				" (을/를)해제했다." << endl;

			Sleep(1000);
		}// end of if: 내가 해제할 아이템이 equip에 존재한다면
		else
		{
			show_warnMessage(WARN_INVALID_INPUT);
			Sleep(1000);
			//continue;
		}// end of else: 내가 해제할 아이템이 equip애 없다면 -> 잘못 입력함.

		// 여기서 인벤토리를 다시 보여준다.
		system("cls");
		show_inventory();
	}// end of while: 해제할 아이템 loop
}

void Inventory::delete_item_inventory(string key)
{
	// 갯수를 확인해서 0이면 erase, 아니면, 갯수만 -1
	itemList_t::iterator mIter;
	mIter = _mItem_inven.find(key);

	int itemCount = 0;
	itemCount = mIter->second.get_count();

	if (itemCount == 0)
	{
		// 아이템 카운트가 없다면 Delete
		_mItem_inven.erase(mIter);
	}// end of if: 아이템이 1개 뿐(count는 0)이라면
	else
	{
		// 기존 숫자에서 1개를 뺀다.
		mIter->second.set_count(itemCount - 1);
	}// end of else: 아이템이 여러개라면
}

void Inventory::insert_item_inventory(string key)
{
	// 없다면 그냥 올린다.
	itemList_t::iterator mIter;
	itemList_t::iterator mIter_shop;
	mIter = _mItem_inven.find(key);
	mIter_shop = _mItem_shop.find(key);

	int itemCount = 0;

	if (mIter != _mItem_inven.end())
	{
		// 인벤토리에 있다면 count만 ++, insert할 필요 없다.
		itemCount = mIter->second.get_count();
		mIter->second.set_count(itemCount + 1);
	}// end of if: 인벤토리에 아이템이 이미 존재한다면
	else
	{
		// 인벤토리에 새 아이템을 그냥 올린다.
		_mItem_inven.insert(
			make_pair(key, mIter_shop->second)
		);

	}// end of else: 인벤토리에 아이템이 없다면
}

void Inventory::delete_item_equip(string key)
{
	itemList_t::iterator mIter_equip;
	mIter_equip = _mItem_equip.find(key);

	// 장비창에서 빠지는 액션은 
	// 1. 인벤토리에 insert 
	insert_item_inventory(key);
	// 2. 장비창에서 delete
	_mItem_equip.erase(mIter_equip);
}

void Inventory::insert_item_equip(string key)
{
	itemList_t::iterator mIter_shop;
	mIter_shop = _mItem_shop.find(key);

	// 장비창에 넣는 액션은
	// 1. 인벤토리에서 delete
	delete_item_inventory(key);
	// 2. 장비창에서 insert
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
	// 소지금과 인벤토리 리스트를 받아서 업데이트한다.
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
		}// end of if: 장비창에 같은 타입의 아이템을 차고 있다면
	}// end of for: 장비창을 전부 찾는다.

	return key;
}

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}
