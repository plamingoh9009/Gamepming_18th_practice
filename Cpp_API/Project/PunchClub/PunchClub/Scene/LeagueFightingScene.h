#pragma once
#include "Scene.h"
class LeagueFightingScene: public Scene
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	LeagueFightingScene();
	~LeagueFightingScene();
};

