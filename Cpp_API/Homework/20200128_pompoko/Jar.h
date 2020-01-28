#pragma once
#include "Item.h"
class Jar: public Item
{
public:
	Jar();
	~Jar();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

