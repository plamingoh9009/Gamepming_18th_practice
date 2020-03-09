#pragma once
#include "Scene.h"
class LeagueWaitingScene: public Scene
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	LeagueWaitingScene();
	~LeagueWaitingScene();
};

