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

	// 공유데이터를 초기화 한다.
	_money = _inven->get_money();
	_mItem_shop = _shop->get_mItem_shop();
}

void MainGame::run_()
{
	// 메인 페이지 보여주고 어디로 갈지 고름
	int myChoice = 0;
	while (_isRunOver != true)
	{
		show_mainPage();
		myChoice = input_choice();

		switch (myChoice)
		{
		case PAGE_ONE:
			// PAGE_ONE: 상점으로 간다.
			move_toShop();
			break;
		case PAGE_TWO:
			// PAGE_TWO: 인벤토리로 간다.
			move_toInven();
			break;
		case PAGE_EXIT:
			// PAGE_EXIT: 그냥 나간다.
			_isRunOver = true;
			break;
		}// end of switch: myChoice로 PAGE_CHOICE 값 처리
	}// end of while: _isRunOver가 true 아닐 동안
}

void MainGame::show_mainPage()
{
	system("cls");

	// 여기서 캐릭터 스탯창을 보여준다.
	// 보여주기 전에 인벤토리에서 장비창을 받아온다.
	_mItem_equip = _inven->get_mItem_equip();
	_status->update_(_mItem_equip);
	_status->run_();

	// 상점창 갈건지, 인벤토리 볼건지 물어봄.
	cout << "*** Main Page ***" << endl;
	cout << endl;
	cout << "[1. 상점]  " << "[2. 인벤토리]  " << 
		"[0. 종료]" << endl;
}

void MainGame::move_toShop()
{
	// 업데이트를 한 뒤에 상점을 보여줌
	_shop->update_(_money, _mItem_inven);
	_shop->run_();
	// 상점에서 구매, 판매가 끝난 후 MainGame을 업데이트한다.
	_mItem_inven = _shop->get_mItem_inven();
	_money = _shop->get_money();
	// 구매한 아이템 목록을 인벤토리에 업데이트 함.
}

void MainGame::move_toInven()
{
	// 인벤을 보여줌
	//cout << "인벤임" << endl;
	_inven->update_(_money, _mItem_inven, _mItem_shop);
	_inven->run_();
	// 인벤토리에서 아이템 사용, 장비 해제가 끝난 후 MainGame을 업데이트한다.
	_mItem_inven = _inven->get_mItem_inven();
	_money = _inven->get_money();
	// 구매한 아이템 목록을 인벤토리에 업데이트 함.
	//Sleep(1000);
}

void MainGame::exit_()
{
	std::cout << "프로그램을 종료하는 중입니다." << std::endl;
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
