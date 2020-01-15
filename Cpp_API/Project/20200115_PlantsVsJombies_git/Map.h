#pragma once
#include "gameNode.h"
class Map: public gameNode
{
private:
	// 가져올 이미지 변수
	image * _img;
	RECT _rect;
	// 맵을 쭉 보여줄 때 쓰는 변수
	bool _isShowMapAll;
	int _distance;
	const int _SPEED = 3;
	// 맵에 식물을 설치할 수 있는 사각형 9x5개
	RECT _space[5][9];
	// 초반에 딜레이를 주기 위한 변수
	int _delay;
public:
	void show_space();
	void init_space();
	void show_mapAll();
public:
	Map();
	~Map();
	HRESULT init();
	void release();
	void update();
	void render();
};

