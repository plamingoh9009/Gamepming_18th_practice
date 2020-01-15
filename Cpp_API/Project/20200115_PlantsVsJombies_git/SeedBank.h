#pragma once
#include "gameNode.h"
class SeedBank: public gameNode
{
private:
	image * _img;
	RECT _rect;
public:
	SeedBank();
	~SeedBank();
	HRESULT init();
	void release();
	void update();
	void render();
};

