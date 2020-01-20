#pragma once
#include "gameNode.h"
class SunPoint: public gameNode
{
private:
	image * _img;
	RECT _rect;
	int _width, _height;
	// �ذ� �Ʒ��� �������� ���� ����
	int _distance = 20;
	int _fallCount, _fallDelay, _fallSpeed;
protected:
	void move_defaultMove();
public:
	void show_rect();
	void init_rect();
public:
	SunPoint();
	~SunPoint();
	HRESULT init();
	void release();
	void update();
	void render();
};

