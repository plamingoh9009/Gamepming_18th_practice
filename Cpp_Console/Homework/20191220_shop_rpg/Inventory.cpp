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

		// ���� ����� �������� inven�� �����Ѵٸ�
		itemList_t::iterator mIter_inven = _mItem_inven.find(myInput);

		if (mIter_inven != _mItem_inven.end())
		{
			// ��� �޼���
			cout << mIter_inven->second.get_key() <<
				" (��/��)����ߴ�." << endl;

			// ������ Ȯ���ؼ� 0�̸�
			if (mIter_inven->second.get_count() == 0)
			{
				// ���â�� �ø���, �κ����� �����. (����°� ����)
				_mItem_equip.insert(
					make_pair(myInput, mIter_inven->second)
				);

				// �κ��丮���� ������ ����
				_mItem_inven.erase(mIter_inven);
			}
			else
			{
				// �κ��丮���� ������ 0�� �ƴϸ� count-- �Ѵ�.
				mIter_inven->second.set_count(
					mIter_inven->second.get_count() - 1
				);

				// count�� �� ���� ���â�� �ø���.
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
		}// end of else: �߸� �Է��ߴٸ� ������ �� ����.

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


		itemList_t::iterator mIter_equip = _mItem_equip.find(myInput);
		itemList_t::iterator mIter_inven = _mItem_inven.find(myInput);

		// ���� ������ �������� equip�� �����Ѵٸ�
		if (mIter_equip != _mItem_equip.end())
		{
			// ���� �޼���
			cout << mIter_equip->second.get_key() <<
				" (��/��)�����ߴ�." << endl;

			if (mIter_inven == _mItem_inven.end())
			{
				// �������� �κ��丮�� ���� ��� -> 
				// �κ��丮�� insert, ���â���� erase�ϸ� ����
				_mItem_inven.insert(
					make_pair(myInput, mIter_equip->second)
				);

				// ���â���� �����.
				_mItem_equip.erase(mIter_equip);
			}// end of if: ���� ������ �������� inven�� ���ٸ�
			else
			{
				// count�� + 1 �Ѵ�.
				mIter_inven->second.set_count(
					mIter_inven->second.get_count() + 1
				);

				// ���â���� �����.
				_mItem_equip.erase(mIter_equip);
			}// end of else: ������ �������� inven�� �̹� �����Ѵٸ�

			Sleep(1000);
		}// end of if: ���� ������ �������� equip�� �����Ѵٸ�
		else
		{
			show_warnMessage(WARN_INVALID_INPUT);
			continue;
		}// end of else: ���� ������ �������� equip�� ���ٸ� -> �߸� �Է���.

		// ���⼭ �κ��丮�� �ٽ� �����ش�.
		system("cls");
		show_inventory();
	}// end of while: ������ ������ loop
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
	// �����ݰ� �κ��丮 ����Ʈ�� �޾Ƽ� ������Ʈ�Ѵ�.
	_money = money;
	_mItem_inven = mItem_inven;
}

Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}
