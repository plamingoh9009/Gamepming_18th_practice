#pragma once
#include "GameScene.h"
class Title: public GameScene
{
public:
	Title();
	~Title();
	HRESULT init();
	void release();
	void update();
	void render();
};

