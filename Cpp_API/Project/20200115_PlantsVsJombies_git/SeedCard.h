#pragma once
#include "gameNode.h"
class SeedCard: public gameNode
{
private:
	image * _img;
	RECT _rect;
	image * _plantImage;
	int _maxFrameX;
	int _maxFrameY;
	int _width;
	int _height;
	string _type;
	string _kindOfPlant;
	string _kindOfCardBack;
	// ī�� ������ Rect ��
	RECT _oneFrameRect;
	int _currentFrameX;
	int _currentFrameY;
public:
	RECT get_oneFrameRect();
	RECT make_oneFrameRect();
	void show_oneFrameRect();
	void init_plantImage();
	void set_seedCard(string strKey, int x, int y);
public:
	SeedCard();
	~SeedCard();
	HRESULT init();
	void release();
	void update();
	void render();
};

