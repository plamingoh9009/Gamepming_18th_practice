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
	// ���� Ȱ��ȭ �ϱ� ���� ������.
	int _map[12][12];
	int _mapWall[12][12];
	enum _mapStat 
	{
		MAP_PATH = 0,
		MAP_CHARACTOR,
		// WALL�� ��
		MAP_OBJECT_WALL,
		MAP_OBJECT_TREE_LEAF,
		MAP_OBJECT_TREE_STEM,
		// EDGE�� �����ڸ�
		MAP_EDGE,
		MAP_EDGE_POINT,
		// DOOR�� ��
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
	// ���� ����̴�. ���ϴ� ����� 
	// 1. ���� ������������ �޾Ƽ� �� �ʱ�ȭ
	//  1-1) 1 �������������� ĳ����, ������Ʈ�� �׷��� ��.
	//  1-2) 2 �������������� ĳ����, �������� �׷��� ��.
	// 2. �ʱ�ȭ �� ���� �׸���
	virtual void init_(int stage);
	void update_map(int myKey);
	void draw_map();
	bool get_isStageOver();
	void set_isStageOver(bool isStageOver);
protected:
	// �ʱ�ȭ�� ���Ǵ� �Լ���.
	void initMaptoZero();
	void initWall();
	void initEdge();
	void initDoor();
	void initTree();
	void initCharactor();
	void mapping_();

	// �� ������Ʈ�� ���Ǵ� �Լ���.
	bool isMoveOK(int myKey);
	bool isPortal(int myKey);

	// �Ҹ��ڿ��� ���
	virtual void exit_();
public:
	Map();
	~Map();
};

