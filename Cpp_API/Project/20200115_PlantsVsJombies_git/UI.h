#pragma once
#include "gameNode.h"
#include "Map.h"
#include "SeedBank.h"
#include "FlagMeter.h"
class UI: public gameNode
{
private:
	Map * _map;
	SeedBank * _bank;
	FlagMeter * _flagMeter;
public:
	UI();
	~UI();
	HRESULT init();
	void release();
	void update();
	void render();
};

