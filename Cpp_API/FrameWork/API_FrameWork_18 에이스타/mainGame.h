#pragma once
#include"gameNode.h"
#include"SubIsoMap.h"
#include"IsoMap.h"
#include"aStar.h"
//#define SUBWINOPEN 1
class mainGame : public gameNode
{
private:

	aStar * _astar;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);



};

