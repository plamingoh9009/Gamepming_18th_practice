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
	// ��� �ʱ�ȭ
	void init_carrots();
	// �׾Ƹ� �ʱ�ȭ
	void init_jars();
	// ���� �ʱ�ȭ
	void init_spikes();
	// ����� ���
	void show_itemRects();
public:
	ItemControl();
	~ItemControl();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

