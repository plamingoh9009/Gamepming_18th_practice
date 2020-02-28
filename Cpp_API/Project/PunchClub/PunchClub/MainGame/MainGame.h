#pragma once
#include "Base/GameNode.h"
class MainGame: public GameNode
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);
public:
	MainGame();
	~MainGame();
};

