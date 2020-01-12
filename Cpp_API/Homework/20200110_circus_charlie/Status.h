#pragma once
#include "gameNode.h"
class Status : public gameNode
{
private:
	image * _img;
	
	POINT _sizeStat = { 660, 70 };

public:
	Status();
	~Status();

	HRESULT init();
	void release();
	void update();
	void render();
};

