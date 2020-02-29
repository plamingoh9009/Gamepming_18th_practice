#pragma once
#include "Base/GameNode.h"
class UI: public GameNode
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	UI();
	~UI();
};

