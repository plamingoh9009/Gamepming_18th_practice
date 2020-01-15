#pragma once
#include "gameNode.h"
#include "UI.h"
#include "ObjectControl.h"
class Stage: public gameNode
{
private:
	UI * _ui;
	ObjectControl * _objControl;
public:
	Stage();
	~Stage();
	HRESULT init();
	void release();
	void update();
	void render();
};

