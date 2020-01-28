#pragma once
#include "Unit.h"
class Enemy: public Unit
{
private:
	bool _fLeft;
protected:
	void move_right();
	void move_left();
public:
	Enemy();
	~Enemy();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

