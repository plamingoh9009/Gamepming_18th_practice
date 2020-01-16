#include "stdafx.h"
#include "UI.h"

RECT UI::make_mouseRect()
{
	return RectMake(m_ptMouse.x, m_ptMouse.y, 5, 5);
}
void UI::check_clickCard()
{
	// 마우스 위치를 Rect 형태로 가져온다.
	RECT mouseRect = make_mouseRect();
	_itCardRects = _cardRects.begin();
	for (;_itCardRects != _cardRects.end();_itCardRects++)
	{

	}
}

void UI::init_mapSpaces()
{
	// 여기서 맵의 공간 배열을 가져와서 내 Rect vector를 만든다.
	_mapSpaces = _map->get_spaces();
	_itMapSpaces = _map->get_itSpaces();
}
void UI::delete_mapSpaces()
{
	_itMapSpaces = _mapSpaces.begin();
	for (;_itMapSpaces != _mapSpaces.end();)
	{
		_mapSpaces.erase(_itMapSpaces++);
	}
	_mapSpaces.clear();
}
void UI::show_mapSpaces()
{
	_itMapSpaces = _mapSpaces.begin();
	for (;_itMapSpaces != _mapSpaces.end();_itMapSpaces++)
	{
		Rectangle(getMemDC(), _itMapSpaces->left, _itMapSpaces->top,
			_itMapSpaces->right, _itMapSpaces->bottom);
	}
}

void UI::show_cardRects()
{
	_itCardRects = _cardRects.begin();
	for (;_itCardRects != _cardRects.end();_itCardRects++)
	{
		Rectangle(getMemDC(), _itCardRects->left, _itCardRects->top,
			_itCardRects->right, _itCardRects->bottom);
	}
}
void UI::init_cardRects()
{
	// 여기서 시드뱅크의 카드벡터를 가져와서 내 Rect vector를 만든다.
	int size = 0;
	vector<SeedCard*> vSeedCards = _bank->get_seedCards();
	vector<SeedCard*>::iterator itSeedCards = _bank->get_itSeedCards();
	
	RECT rect;
	itSeedCards = vSeedCards.begin();
	for (;itSeedCards != vSeedCards.end();itSeedCards++)
	{
		rect = (*itSeedCards)->get_oneFrameRect();
		_cardRects.push_back(rect);
	}
}
void UI::delete_cardRects()
{
	_itCardRects = _cardRects.begin();
	for (;_itCardRects != _cardRects.end();)
	{
		_cardRects.erase(_itCardRects++);
	}
	_cardRects.clear();
}

UI::UI()
{
}
UI::~UI()
{
}
HRESULT UI::init()
{
	_map = new Map;
	_map->init();
	_bank = new SeedBank;
	_bank->init();
	_flagMeter = new FlagMeter;
	_flagMeter->init();
	// 시드카드 rect 벡터를 초기화한다.
	init_cardRects();
	// 맵의 공간 벡터를 초기화한다.
	init_mapSpaces();
	return S_OK;
}
void UI::release()
{
	_map->release();
	_bank->release();
	_flagMeter->release();
	// 카드와 맵 Rect 벡터를 지운다.
	delete_cardRects();
	delete_mapSpaces();
}
void UI::update()
{
	_map->update();
	_bank->update();
	_flagMeter->update();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{

	}
}
void UI::render()
{
	_map->render();
	_bank->render();
	_flagMeter->render();
	
	if (KEYMANAGER->isToggleKey(0x33)){	show_cardRects();}
	//if: 3번을 누르면
	if (KEYMANAGER->isToggleKey(0X31)) { show_mapSpaces(); }
	//if: 1번을 누르면
}