#pragma once
#include "Base/GameNode.h"
class Object: public GameNode
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);
public:
	Object();
	~Object();
};

