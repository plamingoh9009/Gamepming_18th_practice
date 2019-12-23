#include "Shop.h"



void Shop::init_()
{
	// 여기서 상점에 필요한 것들 초기화
	set_items();
}

void Shop::run_()
{
	// 여기서 상점이 어떤 꼴인지 보여줌.
	show_shopPage();

	// 여기서 루프를 돌면 안됨. 1번만 돌리고 MainGame의 run_()으로 빠져나간다.
	// 구매창, 판매창은 무한루프를 돈다.
	int myChoice = input_choice();

	switch (myChoice)
	{
	case PAGE_ONE:
		// PAGE_ONE: 구매창을 보여준다.
		run_pageBuy();
		break;
	case PAGE_TWO:
		// PAGE_TWO: 판매창을 보여준다.
		run_pageSell();
		break;
	case PAGE_EXIT:
		// 뒤로가기는 아무것도 안하면 된다.
		break;
	}// end of switch: myChoice로 내가 뭘 살지 정한다.
}

itemList_t Shop::get_mItem_shop()
{
	return _mItem_shop;
}

void Shop::update_(int money, itemList_t mItem_inven)
{
	// 돈과 인벤토리 목록을 받아서 멤버에 저장한다.
	_money = money;
	_mItem_inven = mItem_inven;
}

void Shop::set_items()
{
	// 상점에서 보여줄 아이템 리스트 초기화
	//cout << "지금 템 만드는 중" << endl;

	Item weapon1;
	weapon1.set_key("그리스월드의_걸작");
	weapon1.set_type("무기");
	weapon1.set_descripttion("전설 도검");
	weapon1.set_damage(104);
	weapon1.set_price(2300);
	_mItem_shop.insert(make_pair(weapon1.get_key(), weapon1));

	Item armor1;
	armor1.set_key("장송곡_판금_갑옷");
	armor1.set_type("방어구");
	armor1.set_descripttion("전설 가슴 방어구");
	armor1.set_armor(51);
	armor1.set_bonusHp(85);
	armor1.set_price(1700);
	_mItem_shop.insert(make_pair(armor1.get_key(), armor1));

	Item accessorie1;
	accessorie1.set_key("제피리아_목걸이");
	accessorie1.set_type("장신구");
	accessorie1.set_descripttion("전설 목걸이");
	accessorie1.set_damage(7);
	accessorie1.set_armor(15);
	accessorie1.set_bonusHp(12);
	accessorie1.set_bonusMp(10);
	accessorie1.set_price(4000);
	_mItem_shop.insert(make_pair(accessorie1.get_key(), accessorie1));

	Sleep(1000);
}

itemList_t Shop::get_mItem_inven()
{
	return _mItem_inven;
}

int Shop::get_money()
{
	return _money;
}

void Shop::show_shopPage()
{
	system("cls");

	// 살껀지 팔껀지 고르는 거임.
	cout << "*** 상점 *** " << endl;
	cout << endl;
	cout << "[1. 구매]  " << "[2. 판매]  " <<
		"[0. 뒤로가기]" << endl;
}

void Shop::run_pageBuy()
{
	while (true)
	{
		show_pageBuy();

		// 여기서 입력을 받아서 원하는 아이템을 구매한다.
		// 구매한 아이템을 인벤토리로 보낼때는 MainGame에서 넘겨주는 mItem_inven을 
		// 이용한다.
		string myInput = "";

		cout << "[구매할 아이템]: ";
		cin >> myInput;

		if (myInput.compare("q") == 0 ||
			myInput.compare("Q") == 0 ||
			myInput.compare("ㅂㅂ") == 0)
		{
			/*cout << "나가기 테스트" << endl;
			Sleep(1000);*/
			break;
		}// end of if: myIput이 q, Q, ㅂㅂ 라면 탈출한다.

		// 만약 상점 리스트에 아이템이 존재 한다면 -> 가격 비교
		// 비교 후 돈이 있으면 구매 ㅇㅋ 없으면 오류

		itemList_t::iterator mIter_shop = _mItem_shop.find(myInput);
		itemList_t::iterator mIter_inven = _mItem_inven.find(myInput);

		// shop에 키 값이 존재한다면
		if (mIter_shop != _mItem_shop.end())
		{
			// 여기서 가격 비교
			if (mIter_shop->second.get_price() <= _money)
			{
				// 구매 가능할 경우 -> 구매 count를 올린 후 -> 인벤토리 확인.
				if (mIter_inven != _mItem_inven.end())
				{
					// 인벤토리에 키 값이 있다면 insert X
					mIter_inven->second.set_count(
						mIter_inven->second.get_count() + 1);
				}
				else
				{
					// 인벤토리에 키 값이 없다면 insert
					_mItem_inven.insert(
						make_pair(myInput, mIter_shop->second)
					);
				}
				// 구매 후 소지금 차감
				_money -= mIter_shop->second.get_price();
				cout << mIter_shop->second.get_key() <<
					" (을/를)구매했다." << endl;
				Sleep(1000);
				continue;
			}/* end of if: 구매가능 하다면 -> item의 price가 _money 보다 작거나
			같다면*/
			else
			{
				// 돈이 모자르면 살 수 없다. 아이템 이름, 가격 내 소지금
				cout << mIter_shop->second.get_key() << "의 가격: " <<
					mIter_shop->second.get_price() << endl;
				cout << "소지금 " << _money - mIter_shop->second.get_price() <<
					" 원 이 모자릅니다." << endl;
				system("pause");
				break;
			}
		}// end of if: 상점에 존재한다면 -> shop에 key값이 존재한다면
		else
		{
			show_warnMessage(WARN_INVALID_INPUT);
			Sleep(1000);
			//continue;
		}// end of else: 잘못 입력했다면
	}// end of while: 아이템을 구매하는 루프
}

void Shop::run_pageSell()
{
	while (true)
	{
		show_pageSell();

		// 여기서 입력을 받아서 원하는 아이템을 판매한다.
		// 판매한 아이템을 인벤토리로 보낼때는 MainGame에서 넘겨주는 mItem_inven을 
		// 이용한다.
		string myInput = "";

		cout << "[판매할 아이템]: " << endl;
		cin >> myInput;

		if (myInput.compare("q") == 0 ||
			myInput.compare("Q") == 0 ||
			myInput.compare("ㅂㅂ") == 0)
		{
			/*cout << "나가기 테스트" << endl;
			Sleep(1000);*/
			break;
		}// end of if: myIput이 q, Q,  라면 탈출한다.

		itemList_t::iterator mIter_shop = _mItem_shop.find(myInput);
		itemList_t::iterator mIter_inven = _mItem_inven.find(myInput);

		// 만약 인벤토리에 아이템이 존재 한다면 -> 판매 가능
		if (mIter_inven != _mItem_inven.end())
		{
			if (mIter_inven->second.get_count() != 0)
			{
				// 인벤토리에 count 가 0이 아니라면 count ++
				mIter_inven->second.set_count(
					mIter_inven->second.get_count() - 1);
			}
			else
			{
				// 인벤토리에 count 가 0이라면 delete
				// map을 쓸 때는 key 값이 아닌, iterator로 erase 해야한다.
				_mItem_inven.erase(mIter_inven);
				
			}
			// 소지금 증가
			_money += mIter_shop->second.get_price();

			cout << mIter_shop->second.get_key() <<
				" (을/를)판매했다." << endl;
			Sleep(1000);
			continue;
		}// end of if: 인벤토리에 존재한다면 -> inven에 key값이 존재한다면
		else
		{
			show_warnMessage(WARN_INVALID_INPUT);
			Sleep(1000);
			//continue;
		}// end of else: 잘못 입력했다면
	}// end of while: 아이템을 판매하는 루프
}

void Shop::show_pageBuy()
{
	system("cls");
	cout << "*** 상점 아이템 리스트 ***" << endl;
	cout << endl;

	cout << "[소지금: " << _money << " 원] \t";
	cout << "[뒤로가기: q, Q]" << endl;

	// _mItem_shop이 가지고 있는 목록을 보여준다.
	show_itemList(_mItem_shop, PAGE_ONE);

	cout << "----------------------------------------";
	cout << "----------------------------------------" << endl;
	cout << endl;
}

void Shop::show_pageSell()
{
	system("cls");
	cout << "*** 아이템 리스트 ***" << endl;
	cout << endl;

	cout << "[소지금: " << _money << " 원] \t";
	cout << "[뒤로가기: q, Q]" << endl;

	// _mItem_shop이 가지고 있는 목록을 보여준다.
	show_itemList(_mItem_inven, PAGE_TWO);

	cout << "----------------------------------------";
	cout << "----------------------------------------" << endl;
	cout << endl;
}


Shop::Shop()
{
}


Shop::~Shop()
{
}
