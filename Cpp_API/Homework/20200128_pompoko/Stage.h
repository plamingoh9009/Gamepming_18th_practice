#pragma once
#include "gameNode.h"
#include "ItemControl.h"
#include "EnemyControl.h"
class Stage: public gameNode
{
private:
	image * _mapImg;
	ItemControl * _itemControl;
	EnemyControl * _enemyControl;
	// ���������� ��
	RECT _wall;
public:
	void show_wallRect();
public:
	Stage();
	~Stage();
	HRESULT init();
	void release();
	void update();
	void render();
};

