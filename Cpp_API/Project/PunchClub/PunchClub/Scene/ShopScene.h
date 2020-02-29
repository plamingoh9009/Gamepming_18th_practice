#pragma once
#include "Scene.h"
class ShopScene: public Scene
{
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	ShopScene();
	~ShopScene();
};

