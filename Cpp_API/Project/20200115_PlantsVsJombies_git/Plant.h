#pragma once
#include "gameNode.h"

class Plant: public gameNode
{
private:
	// �Ĺ� ��ü�� ��Ÿ���� ����
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
	// ���콺�� ���󰡴��� ���ϴ� ����
	bool _fMouseFollow;
	// �Ĺ� �� ������ ����
	RECT _oneFrameRect;
	// �Ĺ��� �ɾ��� ���� ����
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

