#pragma once
#include "GameNode.h"
class MainGame : public GameNode
{
private:
	//RECT rc;
	struct tagRect
	{
		RECT rc;
		bool touch;
	};
	tagRect box[5];
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
public:
	MainGame();
	~MainGame();
};

