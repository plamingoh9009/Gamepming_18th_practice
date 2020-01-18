#pragma once
#include "gameNode.h"
#include "Map.h"
#include "SeedBank.h"
#include "FlagMeter.h"
class UI: public gameNode
{
private:
	typedef map<string, RECT> mCardRects_t;
	typedef vector<RECT> vMapSpaces_t;
	typedef vector<RECT> vMapLines_t;
private:
	Map * _map;
	SeedBank * _bank;
	FlagMeter * _flagMeter;
	// 시드뱅크가 가지고 있는 시드카드의 렉트맵
	mCardRects_t _cardRects;
	mCardRects_t::iterator _itCardRects;

	// 맵이 가지고 있는 공간정보 렉트벡터
	vMapSpaces_t _mapSpaces;
	vMapSpaces_t::iterator _itMapSpaces;
	// 맵이 가지고 있는 라인 렉트벡터
	vMapLines_t _mapLines;
	vMapLines_t::iterator _itMapLines;
public:
	// 맵의 공간정보 렉트벡터를 넘긴다.
	vector<RECT> get_mapSpaces();
	vector<RECT>::iterator get_itMapSpaces();
	// 맵의 라인 렉트벡터를 넘긴다.
	vector<RECT> get_mapLines();
	vector<RECT>::iterator get_itMapLines();
	// 시드카드의 렉트 맵을 넘긴다.
	map<string, RECT> get_cardRects();
	map<string, RECT>::iterator get_itCardRects();

	RECT make_mouseRect();
	void check_clickCard();
	// 맵의 공간 벡터를 처리한다.
	void show_mapSpaces();
	void init_mapSpaces();
	void delete_mapSpaces();
	// 맵의 라인 벡터를 처리한다.
	void show_mapLines();
	void init_mapLines();
	void delete_mapLines();
	// 시드카드의 렉트 맵을 처리한다.
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

