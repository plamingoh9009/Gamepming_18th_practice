#pragma once
#include "gameNode.h"
#include "Status.h"

class Map : public gameNode
{
private:
	image * _img;
	const POINT _sizeMap = {1506, 512};

	Status * _myStat;
public:
	POINT get_sizeMap();
public:
	Map();
	~Map();

	HRESULT init();
	void release();
	void update();
	void render();
	void render(int);
};

