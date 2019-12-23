#include "Shop.h"



void Shop::init_()
{
	// ���⼭ ������ �ʿ��� �͵� �ʱ�ȭ
	set_items();
}

void Shop::run_()
{
	// ���⼭ ������ � ������ ������.
	show_shopPage();

	// ���⼭ ������ ���� �ȵ�. 1���� ������ MainGame�� run_()���� ����������.
	// ����â, �Ǹ�â�� ���ѷ����� ����.
	int myChoice = input_choice();

	switch (myChoice)
	{
	case PAGE_ONE:
		// PAGE_ONE: ����â�� �����ش�.
		run_pageBuy();
		break;
	case PAGE_TWO:
		// PAGE_TWO: �Ǹ�â�� �����ش�.
		run_pageSell();
		break;
	case PAGE_EXIT:
		// �ڷΰ���� �ƹ��͵� ���ϸ� �ȴ�.
		break;
	}// end of switch: myChoice�� ���� �� ���� ���Ѵ�.
}

itemList_t Shop::get_mItem_shop()
{
	return _mItem_shop;
}

void Shop::update_(int money, itemList_t mItem_inven)
{
	// ���� �κ��丮 ����� �޾Ƽ� ����� �����Ѵ�.
	_money = money;
	_mItem_inven = mItem_inven;
}

void Shop::set_items()
{
	// �������� ������ ������ ����Ʈ �ʱ�ȭ
	//cout << "���� �� ����� ��" << endl;

	Item weapon1;
	weapon1.set_key("�׸���������_����");
	weapon1.set_type("����");
	weapon1.set_descripttion("���� ����");
	weapon1.set_damage(104);
	weapon1.set_price(2300);
	_mItem_shop.insert(make_pair(weapon1.get_key(), weapon1));

	Item armor1;
	armor1.set_key("��۰�_�Ǳ�_����");
	armor1.set_type("��");
	armor1.set_descripttion("���� ���� ��");
	armor1.set_armor(51);
	armor1.set_bonusHp(85);
	armor1.set_price(1700);
	_mItem_shop.insert(make_pair(armor1.get_key(), armor1));

	Item accessorie1;
	accessorie1.set_key("���Ǹ���_�����");
	accessorie1.set_type("��ű�");
	accessorie1.set_descripttion("���� �����");
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

	// �첫�� �Ȳ��� ���� ����.
	cout << "*** ���� *** " << endl;
	cout << endl;
	cout << "[1. ����]  " << "[2. �Ǹ�]  " <<
		"[0. �ڷΰ���]" << endl;
}

void Shop::run_pageBuy()
{
	while (true)
	{
		show_pageBuy();

		// ���⼭ �Է��� �޾Ƽ� ���ϴ� �������� �����Ѵ�.
		// ������ �������� �κ��丮�� �������� MainGame���� �Ѱ��ִ� mItem_inven�� 
		// �̿��Ѵ�.
		string myInput = "";

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

		// ���� ���� ����Ʈ�� �������� ���� �Ѵٸ� -> ���� ��
		// �� �� ���� ������ ���� ���� ������ ����

		itemList_t::iterator mIter_shop = _mItem_shop.find(myInput);
		itemList_t::iterator mIter_inven = _mItem_inven.find(myInput);

		// shop�� Ű ���� �����Ѵٸ�
		if (mIter_shop != _mItem_shop.end())
		{
			// ���⼭ ���� ��
			if (mIter_shop->second.get_price() <= _money)
			{
				// ���� ������ ��� -> ���� count�� �ø� �� -> �κ��丮 Ȯ��.
				if (mIter_inven != _mItem_inven.end())
				{
					// �κ��丮�� Ű ���� �ִٸ� insert X
					mIter_inven->second.set_count(
						mIter_inven->second.get_count() + 1);
				}
				else
				{
					// �κ��丮�� Ű ���� ���ٸ� insert
					_mItem_inven.insert(
						make_pair(myInput, mIter_shop->second)
					);
				}
				// ���� �� ������ ����
				_money -= mIter_shop->second.get_price();
				cout << mIter_shop->second.get_key() <<
					" (��/��)�����ߴ�." << endl;
				Sleep(1000);
				continue;
			}/* end of if: ���Ű��� �ϴٸ� -> item�� price�� _money ���� �۰ų�
			���ٸ�*/
			else
			{
				// ���� ���ڸ��� �� �� ����. ������ �̸�, ���� �� ������
				cout << mIter_shop->second.get_key() << "�� ����: " <<
					mIter_shop->second.get_price() << endl;
				cout << "������ " << _money - mIter_shop->second.get_price() <<
					" �� �� ���ڸ��ϴ�." << endl;
				system("pause");
				break;
			}
		}// end of if: ������ �����Ѵٸ� -> shop�� key���� �����Ѵٸ�
		else
		{
			show_warnMessage(WARN_INVALID_INPUT);
			Sleep(1000);
			//continue;
		}// end of else: �߸� �Է��ߴٸ�
	}// end of while: �������� �����ϴ� ����
}

void Shop::run_pageSell()
{
	while (true)
	{
		show_pageSell();

		// ���⼭ �Է��� �޾Ƽ� ���ϴ� �������� �Ǹ��Ѵ�.
		// �Ǹ��� �������� �κ��丮�� �������� MainGame���� �Ѱ��ִ� mItem_inven�� 
		// �̿��Ѵ�.
		string myInput = "";

		cout << "[�Ǹ��� ������]: " << endl;
		cin >> myInput;

		if (myInput.compare("q") == 0 ||
			myInput.compare("Q") == 0 ||
			myInput.compare("����") == 0)
		{
			/*cout << "������ �׽�Ʈ" << endl;
			Sleep(1000);*/
			break;
		}// end of if: myIput�� q, Q,  ��� Ż���Ѵ�.

		itemList_t::iterator mIter_shop = _mItem_shop.find(myInput);
		itemList_t::iterator mIter_inven = _mItem_inven.find(myInput);

		// ���� �κ��丮�� �������� ���� �Ѵٸ� -> �Ǹ� ����
		if (mIter_inven != _mItem_inven.end())
		{
			if (mIter_inven->second.get_count() != 0)
			{
				// �κ��丮�� count �� 0�� �ƴ϶�� count ++
				mIter_inven->second.set_count(
					mIter_inven->second.get_count() - 1);
			}
			else
			{
				// �κ��丮�� count �� 0�̶�� delete
				// map�� �� ���� key ���� �ƴ�, iterator�� erase �ؾ��Ѵ�.
				_mItem_inven.erase(mIter_inven);
				
			}
			// ������ ����
			_money += mIter_shop->second.get_price();

			cout << mIter_shop->second.get_key() <<
				" (��/��)�Ǹ��ߴ�." << endl;
			Sleep(1000);
			continue;
		}// end of if: �κ��丮�� �����Ѵٸ� -> inven�� key���� �����Ѵٸ�
		else
		{
			show_warnMessage(WARN_INVALID_INPUT);
			Sleep(1000);
			//continue;
		}// end of else: �߸� �Է��ߴٸ�
	}// end of while: �������� �Ǹ��ϴ� ����
}

void Shop::show_pageBuy()
{
	system("cls");
	cout << "*** ���� ������ ����Ʈ ***" << endl;
	cout << endl;

	cout << "[������: " << _money << " ��] \t";
	cout << "[�ڷΰ���: q, Q]" << endl;

	// _mItem_shop�� ������ �ִ� ����� �����ش�.
	show_itemList(_mItem_shop, PAGE_ONE);

	cout << "----------------------------------------";
	cout << "----------------------------------------" << endl;
	cout << endl;
}

void Shop::show_pageSell()
{
	system("cls");
	cout << "*** ������ ����Ʈ ***" << endl;
	cout << endl;

	cout << "[������: " << _money << " ��] \t";
	cout << "[�ڷΰ���: q, Q]" << endl;

	// _mItem_shop�� ������ �ִ� ����� �����ش�.
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
