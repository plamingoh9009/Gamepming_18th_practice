#pragma once
#include "gameNode.h"
class Map : public gameNode
{
private:
	image *_bgImage;
public:
	HRESULT init();
	void update();
	void render(HDC hdc);
	void render(HDC hdc, int speed_loop);
	void release();
public:
	Map();
	~Map();
};

