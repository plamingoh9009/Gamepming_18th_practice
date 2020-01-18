#pragma once
#include "gameNode.h"
class Zombie: public gameNode
{
private:
	// �̹��� ����
	image * _img;
	RECT _rect;
	int _width;
	int _height;
	int _maxFrameX;
	int _maxFrameY;
	// �������� ����� ����
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

