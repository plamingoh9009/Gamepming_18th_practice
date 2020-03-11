#pragma once
#include "Base/GameNode.h"
#include "uiEnum.h"
#include "Object/Object.h"
class UI: public GameNode
{
protected:
	Object * _obj;	// 플레이어와 값을 공유할 오브젝트 클래스다.
	static MAPICON::TYPE _mapIcon_on;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	UI();
	~UI();
};

