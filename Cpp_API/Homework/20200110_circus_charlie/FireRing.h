#pragma once
#include "gameNode.h"
#include "LoadOption.h"

class FireRing : public gameNode
{
private:
	image * _img[2];
	POINT _sizeRing = { 30, 198 };

	const int _SPEED_RING = 1;
	const int _TICK_RINGMOVE = 2;

	int _count;
public:
	void moveLeft();
	void reinit_ring();
public:
	FireRing();
	~FireRing();

	HRESULT init();
	void release();
	void update();
	void render();
	void render(indexRing);
};

