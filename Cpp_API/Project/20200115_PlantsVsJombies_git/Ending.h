#pragma once
#include "GameScene.h"
class Ending: GameScene
{
public:
	Ending();
	~Ending();
	HRESULT init();
	void release();
	void update();
	void render();
};

