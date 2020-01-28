#include "stdafx.h"
#include "ItemControl.h"

//============================================
//##			아이템 처리 함수				##
//============================================
void ItemControl::draw_items()
{
	_itemsIter = _items.begin();
	for (;_itemsIter != _items.end();_itemsIter++)
	{
		(*_itemsIter)->render();
	}
}
void ItemControl::delete_itemsAll()
{
	_itemsIter = _items.begin();
	for (;_itemsIter != _items.end();)
	{
		_itemsIter = _items.erase(_itemsIter);
	}
	swap(_items, vItems());
}
//============================================
//##			당근 초기화					##
//============================================
void ItemControl::init_carrots()
{
	Carrot * carrot = new Carrot;
	carrot->init();
	carrot->init_rect(110, 148);
	_items.push_back(carrot);
	carrot = nullptr;

	carrot = new Carrot;
	carrot->init();
	carrot->init_rect(467, 148);
	_items.push_back(carrot);
	carrot = nullptr;

	carrot = new Carrot;
	carrot->init();
	carrot->init_rect(556, 234);
	_items.push_back(carrot);
	carrot = nullptr;

	carrot = new Carrot;
	carrot->init();
	carrot->init_rect(177, 320);
	_items.push_back(carrot);
	carrot = nullptr;

	carrot = new Carrot;
	carrot->init();
	carrot->init_rect(556, 320);
	_items.push_back(carrot);
	carrot = nullptr;

	carrot = new Carrot;
	carrot->init();
	carrot->init_rect(21, 406);
	_items.push_back(carrot);
	carrot = nullptr;

	carrot = new Carrot;
	carrot->init();
	carrot->init_rect(556, 406);
	_items.push_back(carrot);
	carrot = nullptr;

	carrot = new Carrot;
	carrot->init();
	carrot->init_rect(199, 491);
	_items.push_back(carrot);
	carrot = nullptr;
}
//============================================
//##			항아리 초기화					##
//============================================
void ItemControl::init_jars()
{
	Jar * jar = new Jar;
	jar->init();
	jar->init_rect(21, 148);
	_items.push_back(jar);
	jar = nullptr;

	jar = new Jar;
	jar->init();
	jar->init_rect(377, 148);
	_items.push_back(jar);
	jar = nullptr;

	jar = new Jar;
	jar->init();
	jar->init_rect(21, 234);
	_items.push_back(jar);
	jar = nullptr;

	jar = new Jar;
	jar->init();
	jar->init_rect(399, 406);
	_items.push_back(jar);
	jar = nullptr;
}
//============================================
//##			압정 초기화					##
//============================================
void ItemControl::init_spikes()
{
	Spike * spike;
	spike = new Spike;
	spike->init();
	spike->init_rect(534, 173);
	_items.push_back(spike);
	spike = nullptr;
	spike = new Spike;
	spike->init();
	spike->init_rect(312, 259);
	_items.push_back(spike);
	spike = nullptr;
	spike = new Spike;
	spike->init();
	spike->init_rect(312, 345);
	_items.push_back(spike);
	spike = nullptr;
	spike = new Spike;
	spike->init();
	spike->init_rect(512, 516);
	_items.push_back(spike);
	spike = nullptr;
}
//============================================
//##			디버그 모드					##
//============================================
void ItemControl::show_itemRects()
{
	_itemsIter = _items.begin();
	for (;_itemsIter != _items.end();_itemsIter++)
	{
		(*_itemsIter)->show_rect();
	}
}

ItemControl::ItemControl()
{
}
ItemControl::~ItemControl()
{
}
HRESULT ItemControl::init()
{
	init_carrots();
	init_jars();
	init_spikes();
	return S_OK;
}

void ItemControl::release()
{
	delete_itemsAll();
	IMAGEMANAGER->deleteImage("Jar");
	IMAGEMANAGER->deleteImage("Carrot");
}
void ItemControl::update()
{
	if (KEYMANAGER->isToggleKey(0x31))
	{
		_fDebug = true;
	}
	else
	{
		_fDebug = false;
	}
}
void ItemControl::render()
{
	draw_items();
	if (_fDebug == true)
	{
		show_itemRects();
	}
}
