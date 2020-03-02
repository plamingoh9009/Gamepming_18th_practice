#pragma once
#include "Base/GameNode.h"

typedef vector<string> vSceneList;
class Scene : public GameNode
{
protected:
	static vSceneList _sceneList;
protected:
	void add_currentScene_toList(SCENE_TYPE sceneType);
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Scene();
	~Scene();
};

