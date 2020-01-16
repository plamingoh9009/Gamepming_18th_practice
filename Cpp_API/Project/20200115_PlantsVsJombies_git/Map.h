#pragma once
#include "gameNode.h"
class Map: public gameNode
{
private:
	typedef vector<RECT> vSpaces;
private:
	// ������ �̹��� ����
	image * _img;
	RECT _rect;
	// ���� �� ������ �� ���� ����
	bool _isShowMapAll;
	int _distance;
	const int _SPEED = 3;
	// �ʿ� �Ĺ��� ��ġ�� �� �ִ� �簢�� 9x5�� ����
	vSpaces _spaces;
	vSpaces::iterator _itSpaces;
	// �ʹݿ� �����̸� �ֱ� ���� ����
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