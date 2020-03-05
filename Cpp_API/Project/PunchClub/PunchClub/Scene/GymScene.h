#pragma once
#include "Scene.h"
#include "UI/InGameUI.h"
class GymScene: public Scene
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	GymScene();
	~GymScene();
};

