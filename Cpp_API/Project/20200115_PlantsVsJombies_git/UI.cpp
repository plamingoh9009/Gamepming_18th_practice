#include "stdafx.h"
#include "UI.h"

void UI::set_fClickCardToBank(bool fResult)
{
	_bank->set_fClickCard(fResult);
}
void UI::set_cardTypeToBank(string cardType)
{
	_bank->set_cardType(cardType);
}

vector<RECT> UI::get_mapSpaces()
{
	return vector<RECT>(_mapSpaces);
}
vector<RECT>::iterator UI::get_itMapSpaces()
{
	return vector<RECT>::iterator(_itMapSpaces);
}
vector<RECT> UI::get_mapLines()
{
	return vector<RECT>(_mapLines);
}
vector<RECT>::iterator UI::get_itMapLines()
{
	return vector<RECT>::iterator(_itMapLines);
}
map<string, RECT> UI::get_cardRects()
{
	return map<string, RECT>(_cardRects);
}
map<string, RECT>::iterator UI::get_itCardRects()
{
	return map<string, RECT>::iterator(_itCardRects);
}

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
// ================================================
// **			맵의 공간 정보 처리함수				 **
// ================================================
void UI::show_mapSpaces()
{
	_itMapSpaces = _mapSpaces.begin();
	for (;_itMapSpaces != _mapSpaces.end();_itMapSpaces++)
	{
		FrameRect(getMemDC(), &(*_itMapSpaces), RGB(0, 0, 0));
	}
}
void UI::init_mapSpaces()
{
	// 여기서 맵의 공간 벡터를 가져와서 내 Rect vector를 만든다.
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
// ================================================
// **			맵의 라인 정보 처리함수				 **
// ================================================
void UI::show_mapLines()
{
	_itMapLines = _mapLines.begin();
	for (;_itMapLines != _mapLines.end();_itMapLines++)
	{
		FrameRect(getMemDC(), &(*_itMapLines),
			CreateSolidBrush(RGB(64, 0, 64)));
	}
}
void UI::init_mapLines()
{
	// 여기서 맵의 라인 정보를 가져와서 내 RECT vector를 만든다.
	_mapLines = _map->get_lines();
	_itMapLines = _map->get_itLines();
}
void UI::delete_mapLines()
{
	// 렉트는 동적할당 하지 않았기 때문에 erase만 한다.
	_itMapLines = _mapLines.begin();
	for (;_itMapLines != _mapLines.end();)
	{
		_mapLines.erase(_itMapLines++);
	}
	_mapLines.clear();
}
// ================================================
// **			카드 공간 정보 처리함수				 **
// ================================================
void UI::show_cardRects()
{
	_itCardRects = _cardRects.begin();
	for (;_itCardRects != _cardRects.end();_itCardRects++)
	{
		FrameRect(getMemDC(), &_itCardRects->second,
			RGB(0, 0, 0));
	}
}
void UI::init_cardRects()
{
	// 여기서 시드뱅크의 카드벡터를 가져와서 내 Rect map을 만든다.
	map<string, SeedCard*> seedCards = _bank->get_seedCards();
	map<string, SeedCard*>::iterator itSeedCards =
		_bank->get_itSeedCards();
	string strKey;
	RECT rect;
	itSeedCards = seedCards.begin();
	for (;itSeedCards != seedCards.end();itSeedCards++)
	{
		strKey = itSeedCards->first;
		rect = itSeedCards->second->get_oneFrameRect();
		_cardRects.insert(make_pair(strKey, rect));
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
	// 햇빛을 초기화한다.
	_sunControl = new SunPointControl;
	_sunControl->init();
	// 시드카드 rect 벡터를 초기화한다.
	init_cardRects();
	// 맵의 공간 벡터를 초기화한다.
	init_mapSpaces();
	// 맵의 라인 벡터를 초기화한다.
	init_mapLines();
	return S_OK;
}
void UI::release()
{
	_map->release();
	_map = nullptr;
	_bank->release();
	_bank = nullptr;
	_flagMeter->release();
	_flagMeter = nullptr;
	_sunControl->release();
	_sunControl = nullptr;
	// 카드와 맵 Rect 벡터를 지운다.
	delete_cardRects();
	delete_mapSpaces();
	delete_mapLines();
}
void UI::update()
{
	_map->update();
	_bank->update();
	_flagMeter->update();
	_sunControl->update();
}
void UI::render()
{
	_map->render();
	_bank->render();
	_flagMeter->render();
	_sunControl->render();

	if (KEYMANAGER->isToggleKey(0x32)) 
	{ 
		show_cardRects(); 
		_sunControl->show_sunPointRects();
	}
	//if: 2번을 누르면
	if (KEYMANAGER->isToggleKey(0X31))
	{
		show_mapSpaces();
		show_mapLines();
	}//if: 1번을 누르면
}