#pragma once
#include "gameNode.h"
class Map: public gameNode
{
private:
	typedef vector<RECT> vSpaces;
private:
	// 가져올 이미지 변수
	image * _img;
	RECT _rect;
	// 맵을 쭉 보여줄 때 쓰는 변수
	bool _isShowMapAll;
	int _distance;
	const int _SPEED = 3;
	// 맵에 식물을 설치할 수 있는 사각형 9x5개 벡터
	vSpaces _spaces;
	vSpaces::iterator _itSpaces;
	// 초반에 딜레이를 주기 위한 변수
	int _delay;
public:
	vector<RECT> get_spaces();
	vector<RECT>::iterator get_itSpaces();
	void show_spaces();
	void init_spaces();
	void delete_spaces();
	void show_mapAll();
public:
	Map();
	~Map();
	HRESULT init();
	void release();
	void update();
	void render();
};