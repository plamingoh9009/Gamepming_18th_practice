#pragma once
#include "Base/GameNode.h"
#include "Object/Object.h"
class UI: public GameNode
{
protected:
	Object * _obj;	// �÷��̾�� ���� ������ ������Ʈ Ŭ������.
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	UI();
	~UI();
};

