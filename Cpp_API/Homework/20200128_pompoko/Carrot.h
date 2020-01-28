#pragma once
#include "Item.h"
class Carrot: public Item
{
public:
	Carrot();
	~Carrot();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

