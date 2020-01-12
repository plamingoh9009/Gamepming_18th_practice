#pragma once
#include "gameNode.h"

class Title : public gameNode
{
private:
	const int _SPEED_FRAME = 6;
	image * _img;
	int _maxFrame;
	int _count;
	int _index;

	bool _fOffTitle;

public:
	bool get_fOffTitle();
	void run_title();
public:
	Title();
	~Title();

	HRESULT init();
	void release();
	void update();
	void render();
};

