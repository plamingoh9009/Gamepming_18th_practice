#pragma once
#include "UI.h"
class PrefightSkillSet: public UI
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	PrefightSkillSet();
	~PrefightSkillSet();
};

