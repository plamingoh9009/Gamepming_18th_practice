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
	void update_uiToObjControl();
	void update_objControlToUi();
public:
	Stage();
	~Stage();
	HRESULT init();
	void release();
	void update();
	void render();
};

