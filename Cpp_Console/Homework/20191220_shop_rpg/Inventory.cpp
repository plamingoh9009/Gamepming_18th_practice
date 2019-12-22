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

		// 내가 사용할 아이템이 inven에 존재한다면
		itemList_t::iterator mIter_inven = _mItem_inven.find(myInput);

		if (mIter_inven != _mItem_inven.end())
		{
			// 사용 메세지
			cout << mIter_inven->second.get_key() <<
				" (을/를)사용했다." << endl;

			// 갯수를 확인해서 0이면
			if (mIter_inven->second.get_count() == 0)
			{
				// 장비창에 올리고, 인벤에서 지운다. (지우는게 나중)
				_mItem_equip.insert(
					make_pair(myInput, mIter_inven->second)
				);

				// 인벤토리에서 실제로 지움
				_mItem_inven.erase(mIter_inven);
			}
			else
			{
				// 인벤토리에서 갯수가 0이 아니면 count-- 한다.
				mIter_inven->second.set_count(
					mIter_inven->second.get_count() - 1
				);

				// count를 뺀 것을 장비창에 올린다.
				_mItem_equip.insert(
					make_pair(myInput, mIter_inven->second)
				);
			}

			Sleep(1000);
			//continue;
		}
		else
		{
			show_warnMessage(WARN_INVALID_INPUT);
			system("pause");
			//continue;
		}// end of else: 잘못 입력했다면 루프를 더 돈다.

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


		itemList_t::iterator mIter_equip = _mItem_equip.find(myInput);
		itemList_t::iterator mIter_inven = _mItem_inven.find(myInput);

		// 내가 해제할 아이템이 equip에 존재한다면
		if (mIter_equip != _mItem_equip.end())
		{
			// 해제 메세지
			cout << mIter_equip->second.get_key() <<
				" (을/를)해제했다." << endl;

			if (mIter_inven == _mItem_inven.end())
			{
				// 아이템이 인벤토리에 없는 경우 -> 
				// 인벤토리에 insert, 장비창에서 erase하면 ㅇㅋ
				_mItem_inven.insert(
					make_pair(myInput, mIter_equip->second)
				);

				// 장비창에서 지운다.
				_mItem_equip.erase(mIter_equip);
			}// end of if: 내가 해제할 아이템이 inven에 없다면
			else
			{
				// count를 + 1 한다.
				mIter_inven->second.set_count(
					mIter_inven->second.get_count() + 1
				);

				// 장비창에서 지운다.
				_mItem_equip.erase(mIter_equip);
			}// end of else: 해제할 아이템이 inven에 이미 존재한다면

			Sleep(1000);
		}// end of if: 내가 해제할 아이템이 equip에 존재한다면
		else
		{
			show_warnMessage(WARN_INVALID_INPUT);
			continue;
		}// end of else: 내가 해제할 아이템이 equip애 없다면 -> 잘못 입력함.

		// 여기서 인벤토리를 다시 보여준다.
		system("cls");
		show_inventory();
	}// end of while: 해제할 아이템 loop
}

int Inventory::get_money()
{
	return _money;
}

itemList_t Inventory::get_mItem_inven()
{
	return _mItem_inven;
}

void Inventory::set_money(int money)
{
	_money = money;
}

void Inventory::update_(int money, itemList_t mItem_inven)
{
	// 소지금과 인벤토리 리스트를 받아서 업데이트한다.
	_money = money;
	_mItem_inven = mItem_inven;
}

Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}
