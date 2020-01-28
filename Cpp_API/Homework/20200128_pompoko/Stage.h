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
	// 못지나가는 벽
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

