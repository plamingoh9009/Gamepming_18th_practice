#pragma once
#include "Base/GameNode.h"
// ���⿡ ���Ӿ� �߰�
#include "Scene/TitleScene.h"
#include "Scene/HomeScene.h"
#include "Scene/HUD_Scene.h"
#include "Scene/GymScene.h"
#include "Scene/ShopScene.h"
class MainGame: public GameNode
{
protected:
	void add_scenes_toManager();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);
public:
	MainGame();
	~MainGame();
};

