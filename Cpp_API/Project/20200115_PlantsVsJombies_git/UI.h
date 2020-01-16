#pragma once
#include "gameNode.h"
#include "Map.h"
#include "SeedBank.h"
#include "FlagMeter.h"
class UI: public gameNode
{
private:
	typedef vector<RECT> vCardRects_t;
	typedef vector<RECT> vMapSpaces_t;
private:
	Map * _map;
	SeedBank * _bank;
	FlagMeter * _flagMeter;
	// 시드뱅크가 가지고 있는 시드카드의 렉트벡터
	vCardRects_t _cardRects;
	vCardRects_t::iterator _itCardRects;
	// 맵이 가지고 있는 공간정보 렉트벡터
	vMapSpaces_t _mapSpaces;
	vMapSpaces_t::iterator _itMapSpaces;
public:
	RECT make_mouseRect();
	void check_clickCard();
	void show_mapSpaces();
	void init_mapSpaces();
	void delete_mapSpaces();
	void show_cardRects();
	void init_cardRects();
	void delete_cardRects();
public:
	UI();
	~UI();
	HRESULT init();
	void release();
	void update();
	void render();
};

