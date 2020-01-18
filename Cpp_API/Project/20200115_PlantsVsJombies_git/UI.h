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
	// �õ��ũ�� ������ �ִ� �õ�ī���� ��Ʈ��
	mCardRects_t _cardRects;
	mCardRects_t::iterator _itCardRects;

	// ���� ������ �ִ� �������� ��Ʈ����
	vMapSpaces_t _mapSpaces;
	vMapSpaces_t::iterator _itMapSpaces;
	// ���� ������ �ִ� ���� ��Ʈ����
	vMapLines_t _mapLines;
	vMapLines_t::iterator _itMapLines;
public:
	// ���� �������� ��Ʈ���͸� �ѱ��.
	vector<RECT> get_mapSpaces();
	vector<RECT>::iterator get_itMapSpaces();
	// ���� ���� ��Ʈ���͸� �ѱ��.
	vector<RECT> get_mapLines();
	vector<RECT>::iterator get_itMapLines();
	// �õ�ī���� ��Ʈ ���� �ѱ��.
	map<string, RECT> get_cardRects();
	map<string, RECT>::iterator get_itCardRects();

	RECT make_mouseRect();
	void check_clickCard();
	// ���� ���� ���͸� ó���Ѵ�.
	void show_mapSpaces();
	void init_mapSpaces();
	void delete_mapSpaces();
	// ���� ���� ���͸� ó���Ѵ�.
	void show_mapLines();
	void init_mapLines();
	void delete_mapLines();
	// �õ�ī���� ��Ʈ ���� ó���Ѵ�.
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

