#pragma once
#include "Object.h"
class Unit: Object
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);
public:
	Unit();
	~Unit();
};

