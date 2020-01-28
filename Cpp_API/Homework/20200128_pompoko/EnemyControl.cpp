#include "stdafx.h"
#include "EnemyControl.h"

void EnemyControl::init_enemys()
{
	Enemy * enemy;
	enemy = new Enemy;
	enemy->init();
	enemy->init_rect(0, 148);
	_enemys.push_back(enemy);
	enemy = nullptr;
	enemy = new Enemy;
	enemy->init();
	enemy->init_rect(0, 320);
	_enemys.push_back(enemy);
	enemy = nullptr;
}
void EnemyControl::delete_enemysAll()
{
	_enemysIter = _enemys.begin();
	for (;_enemysIter != _enemys.end();)
	{
		_enemysIter = _enemys.erase(_enemysIter);
	}
	swap(_enemys, vEnemys());
}
void EnemyControl::draw_enemys()
{
	_enemysIter = _enemys.begin();
	for (;_enemysIter != _enemys.end(); _enemysIter++)
	{
		(*_enemysIter)->show_rect();
	}
}
void EnemyControl::update_enemys()
{
	_enemysIter = _enemys.begin();
	for (;_enemysIter != _enemys.end(); _enemysIter++)
	{
		(*_enemysIter)->update();
	}
}
EnemyControl::EnemyControl()
{
}
EnemyControl::~EnemyControl()
{
}

HRESULT EnemyControl::init()
{
	init_enemys();
	return S_OK;
}
void EnemyControl::release()
{
	delete_enemysAll();
}
void EnemyControl::update()
{
	update_enemys();
}
void EnemyControl::render()
{
	draw_enemys();
}
