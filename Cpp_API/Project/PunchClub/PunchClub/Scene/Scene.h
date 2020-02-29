#pragma once
#include "Base/GameNode.h"
class Scene : public GameNode
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Scene();
	~Scene();
};

