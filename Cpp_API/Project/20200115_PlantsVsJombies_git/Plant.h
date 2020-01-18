#pragma once
#include "gameNode.h"

class Plant: public gameNode
{
private:
	// 식물 객체를 나타내는 정보
	image * _img;
	RECT _rect;
	int _width;
	int _height;
	int _maxFrameX;
	int _maxFrameY;
	string _type;
	int _currentFrameX;
	int _currentFrameY;
	int _frameDelay;
	int _frameCount;
	// 마우스를 따라가는지 정하는 변수
	bool _fMouseFollow;
	// 식물 한 프레임 정보
	RECT _oneFrameRect;
	// 식물이 심어진 공간 정보
	RECT _plantPoint;
	
public:
	RECT get_oneFrameRect() { return _oneFrameRect; }
	RECT make_oneFrameRect();
	void show_plantRect();
	void move_plant(LONG, LONG);
	void follow_mouseMove();
	void run_frameImg();
	bool is_plantInRect(RECT);
	void set_plantPoint(RECT);
	bool get_fMouseFollow() { return _fMouseFollow; }
	void set_fMouseFollow(bool flag) { _fMouseFollow = flag; }
	void set_plant(string strKey, int x, int y);
public:
	Plant();
	~Plant();
	HRESULT init();
	void release();
	void update();
	void render();
};

