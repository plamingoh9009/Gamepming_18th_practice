#pragma once
#include "gameNode.h"
class FlagMeter: public gameNode
{
private:
	image * _img;
	RECT _rect;
public:
	FlagMeter();
	~FlagMeter();
	HRESULT init();
	void release();
	void update();
	void render();
};

