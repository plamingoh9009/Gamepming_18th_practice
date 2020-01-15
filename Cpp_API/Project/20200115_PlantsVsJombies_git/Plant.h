#pragma once
#include "gameNode.h"

class Plant: public gameNode
{
private:
	image * _img;
	int _width;
	int _height;
	int _maxFrameX;
	int _maxFrameY;
	string _type;
	RECT _rect;
	int _currentFrameX;
	int _currentFrameY;
	int _frameDelay;
	int _frameCount;
public:
	void set_plant(string strKey, int x, int y);
public:
	Plant();
	~Plant();
	HRESULT init();
	void release();
	void update();
	void render();
};

