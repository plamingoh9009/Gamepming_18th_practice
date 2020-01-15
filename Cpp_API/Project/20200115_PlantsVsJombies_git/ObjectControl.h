#pragma once
#include "gameNode.h"
#include "Plant.h"
class ObjectControl: public gameNode
{
private:
	Plant * _plant;
public:
	ObjectControl();
	~ObjectControl();
	HRESULT init();
	void release();
	void update();
	void render();
};

