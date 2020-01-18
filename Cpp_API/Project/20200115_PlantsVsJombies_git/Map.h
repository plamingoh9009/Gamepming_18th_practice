#pragma once
#include "gameNode.h"
class Map: public gameNode
{
private:
	typedef vector<RECT> vLines_t;
	typedef vector<RECT> vSpaces_t;
private:
	// ������ �̹��� ����
	image * _img;
	RECT _rect;
	// ���� �� ������ �� ���� ����
	bool _isShowMapAll;
	int _distance;
	const int _SPEED = 3;
	// ���� 5�� ���� ������ ��� ����
	vLines_t _lines;
	vLines_t::iterator _itLines;
	// �ʿ� �Ĺ��� ��ġ�� �� �ִ� �簢�� 9x5�� ����
	vSpaces_t _spaces;
	vSpaces_t::iterator _itSpaces;
	// �ʹݿ� �����̸� �ֱ� ���� ����
	int _delay;
public:
	vector<RECT> get_spaces();
	vector<RECT>::iterator get_itSpaces();
	vector<RECT> get_lines();
	vector<RECT>::iterator get_itLines();
	void show_lines();
	void delete_lines();
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