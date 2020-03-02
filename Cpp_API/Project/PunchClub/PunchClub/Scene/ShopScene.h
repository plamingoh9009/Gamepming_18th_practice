#pragma once
#include "Scene.h"
class ShopScene: public Scene
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	ShopScene();
	~ShopScene();
};

