#include "MainGame.h"

void MainGame::init_()
{
	_shop = new Shop();
	_shop->init_();
	_inven = new Inventory();
	_inven->init_();
	_status = new Status();
	_status->init_();
	_isRunOver = false;

	// ���������͸� �ʱ�ȭ �Ѵ�.
	_money = _inven->get_money();
	_mItem_shop = _shop->get_mItem_shop();
}

void MainGame::run_()
{
	// ���� ������ �����ְ� ���� ���� ��
	int myChoice = 0;
	while (_isRunOver != true)
	{
		show_mainPage();
		myChoice = input_choice();

		switch (myChoice)
		{
		case PAGE_ONE:
			// PAGE_ONE: �������� ����.
			move_toShop();
			break;
		case PAGE_TWO:
			// PAGE_TWO: �κ��丮�� ����.
			move_toInven();
			break;
		case PAGE_EXIT:
			// PAGE_EXIT: �׳� ������.
			_isRunOver = true;
			break;
		}// end of switch: myChoice�� PAGE_CHOICE �� ó��
	}// end of while: _isRunOver�� true �ƴ� ����
}

void MainGame::show_mainPage()
{
	system("cls");

	// ���⼭ ĳ���� ����â�� �����ش�.
	// �����ֱ� ���� �κ��丮���� ���â�� �޾ƿ´�.
	_mItem_equip = _inven->get_mItem_equip();
	_status->update_(_mItem_equip);
	_status->run_();

	// ����â ������, �κ��丮 ������ ���.
	cout << "*** Main Page ***" << endl;
	cout << endl;
	cout << "[1. ����]  " << "[2. �κ��丮]  " << 
		"[0. ����]" << endl;
}

void MainGame::move_toShop()
{
	// ������Ʈ�� �� �ڿ� ������ ������
	_shop->update_(_money, _mItem_inven);
	_shop->run_();
	// �������� ����, �ǸŰ� ���� �� MainGame�� ������Ʈ�Ѵ�.
	_mItem_inven = _shop->get_mItem_inven();
	_money = _shop->get_money();
	// ������ ������ ����� �κ��丮�� ������Ʈ ��.
}

void MainGame::move_toInven()
{
	// �κ��� ������
	//cout << "�κ���" << endl;
	_inven->update_(_money, _mItem_inven, _mItem_shop);
	_inven->run_();
	// �κ��丮���� ������ ���, ��� ������ ���� �� MainGame�� ������Ʈ�Ѵ�.
	_mItem_inven = _inven->get_mItem_inven();
	_money = _inven->get_money();
	// ������ ������ ����� �κ��丮�� ������Ʈ ��.
	//Sleep(1000);
}

void MainGame::exit_()
{
	std::cout << "���α׷��� �����ϴ� ���Դϴ�." << std::endl;
	Sleep(1000);
}

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	delete _shop;
	delete _inven;
	delete _status;

	exit_();
}
