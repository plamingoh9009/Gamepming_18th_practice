#pragma once
#include "Carrot.h"
#include "Jar.h"
#include "Spike.h"
class ItemControl: public gameNode
{
private:
	typedef vector<Item *> vItems;
private:
	vItems _items;
	vItems::iterator _itemsIter;
	bool _fDebug;
protected:
	void draw_items();
	void delete_itemsAll();
	// 당근 초기화
	void init_carrots();
	// 항아리 초기화
	void init_jars();
	// 압정 초기화
	void init_spikes();
	// 디버그 모드
	void show_itemRects();
public:
	ItemControl();
	~ItemControl();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

