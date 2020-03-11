#pragma once
#include "Base/GameNode.h"
#include "uiEnum.h"
#include "Object/Object.h"
class UI: public GameNode
{
protected:
	Object * _obj;	// �÷��̾�� ���� ������ ������Ʈ Ŭ������.
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

