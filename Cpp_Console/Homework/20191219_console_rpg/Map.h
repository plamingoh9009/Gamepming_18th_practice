#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <conio.h>

using namespace std;

class Map
{
private:
	// 맵을 활성화 하기 위한 변수다.
	int _map[12][12];
	int _mapWall[12][12];
	enum _mapStat 
	{
		MAP_PATH = 0,
		MAP_CHARACTOR,
		// WALL은 벽
		MAP_OBJECT_WALL,
		MAP_OBJECT_TREE_LEAF,
		MAP_OBJECT_TREE_STEM,
		// EDGE는 가장자리
		MAP_EDGE,
		MAP_EDGE_POINT,
		// DOOR는 문
		MAP_DOOR
	};
	enum _keyArrow
	{
		KEY_UP = 72,
		KEY_LEFT = 75,
		KEY_RIGHT = 77,
		KEY_DOWN = 80
	};
	int _posCharactor[2];
	bool _isStageOver;
public:
	// 맵의 기능이다. 원하는 기능은 
	// 1. 무슨 스테이지인지 받아서 맵 초기화
	//  1-1) 1 스테이지에서는 캐릭터, 오브젝트를 그려야 함.
	//  1-2) 2 스테이지에서는 캐릭터, 보스몹을 그려야 함.
	// 2. 초기화 된 맵을 그리기
	virtual void init_(int stage);
	void update_map(int myKey);
	void draw_map();
	bool get_isStageOver();
	void set_isStageOver(bool isStageOver);
protected:
	// 초기화에 사용되는 함수다.
	void initMaptoZero();
	void initWall();
	void initEdge();
	void initDoor();
	void initTree();
	void initCharactor();
	void mapping_();

	// 맵 업데이트에 사용되는 함수다.
	bool isMoveOK(int myKey);
	bool isPortal(int myKey);

	// 소멸자에서 사용
	virtual void exit_();
public:
	Map();
	~Map();
};

