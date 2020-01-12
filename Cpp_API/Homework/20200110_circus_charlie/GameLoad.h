#pragma once
#include "gameNode.h"
#include "Title.h"
#include "Map.h"
#include "Player.h"
#include "LoadOption.h"
#include "FireRing.h"

class GameLoad : public gameNode
{
private:
	char str[128];

	int _loadIndex;

	Title * _title;
	Map * _map;

	Player * _player;

	FireRing * _fireRing;

	int _indexMap;
public:
	void set_indexMap();
public:
	GameLoad();
	~GameLoad();

	HRESULT init();
	void release();
	void update();
	void render();
};

