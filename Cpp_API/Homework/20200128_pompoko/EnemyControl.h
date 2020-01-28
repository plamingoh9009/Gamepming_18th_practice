#pragma once
#include "gameNode.h"
#include "Enemy.h"
class EnemyControl: public gameNode
{
private:
	typedef vector<Enemy *> vEnemys;
private:
	vEnemys _enemys;
	vEnemys::iterator _enemysIter;
	// 벽
	RECT _wall;
protected:
	void init_enemys();
public:
	// 에너미 컨트롤
	void delete_enemysAll();
	void draw_enemys();
	void update_enemys();
public:
	EnemyControl();
	~EnemyControl();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

