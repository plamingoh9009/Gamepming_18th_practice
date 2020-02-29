#pragma once
#include "Scene.h"
class HUD_Scene: public Scene
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	HUD_Scene();
	~HUD_Scene();
};

