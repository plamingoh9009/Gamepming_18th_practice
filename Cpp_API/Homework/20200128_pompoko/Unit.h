#pragma once
#include "gameNode.h"
class Unit:public gameNode
{
protected:
	RECT _rect;
	int _width;
	int _height;
	// �����̱� ���� ����
	int _moveCounter;
	int _moveDelay;
	// ���� ������ ó���ϱ� ���� ����
	RECT _wall;
public:
	// ���� �޴� �Լ�
	void set_wall(RECT wall) { _wall = wall; }
	// ���� ��ġ�� ����
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

