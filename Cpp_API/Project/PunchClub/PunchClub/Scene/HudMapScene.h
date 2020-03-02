#pragma once
#include "Scene.h"
class HudMapScene: public Scene
{
private:
	Image * _bg;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	HudMapScene();
	~HudMapScene();
};

