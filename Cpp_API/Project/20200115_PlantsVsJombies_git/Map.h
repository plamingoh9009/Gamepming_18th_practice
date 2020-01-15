#pragma once
#include "gameNode.h"
class Map: public gameNode
{
private:
	// ������ �̹��� ����
	image * _img;
	RECT _rect;
	// ���� �� ������ �� ���� ����
	bool _isShowMapAll;
	int _distance;
	const int _SPEED = 3;
	// �ʿ� �Ĺ��� ��ġ�� �� �ִ� �簢�� 9x5��
	RECT _space[5][9];
	// �ʹݿ� �����̸� �ֱ� ���� ����
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

