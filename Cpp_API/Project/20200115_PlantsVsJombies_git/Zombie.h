#pragma once
#include "gameNode.h"
class Zombie: public gameNode
{
private:
	// 이미지 정보
	image * _img;
	RECT _rect;
	int _width;
	int _height;
	int _maxFrameX;
	int _maxFrameY;
	// 프레임을 재생할 정보
	int _currentFrameX;
	int _currentFrameY;
	int _frameDelay;
	int _frameCount;
public:
	void init_zombiePosition();
public:
	Zombie();
	~Zombie();
	HRESULT init();
	void release();
	void update();
	void render();
};

