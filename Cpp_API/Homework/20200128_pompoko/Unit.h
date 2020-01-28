#pragma once
#include "gameNode.h"
class Unit:public gameNode
{
protected:
	RECT _rect;
	int _width;
	int _height;
	// 움직이기 위한 변수
	int _moveCounter;
	int _moveDelay;
	// 벽을 만나면 처리하기 위한 변수
	RECT _wall;
public:
	// 벽을 받는 함수
	void set_wall(RECT wall) { _wall = wall; }
	// 현재 위치를 리턴
	RECT get_rect() { return _rect; }
	void init_rect(int x, int y);
	void show_rect();
public:
	Unit();
	~Unit();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

