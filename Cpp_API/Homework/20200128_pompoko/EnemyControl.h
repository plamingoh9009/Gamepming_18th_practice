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
	// ��
	RECT _wall;
protected:
	void init_enemys();
public:
	// ���ʹ� ��Ʈ��
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

