#pragma once
#include "gameNode.h"
class Item: public gameNode
{
protected:
	image * _img;
	RECT _rect;
	string _type;
	int _width;
	int _height;
	bool _fEat;
	bool _fDebug;
public:
	void init_rect(LONG x, LONG y);
	void show_rect();
public:
	Item();
	~Item();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

