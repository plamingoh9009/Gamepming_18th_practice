#pragma once
#include "Item.h"
class Spike: public Item
{
public:
	Spike();
	~Spike();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

