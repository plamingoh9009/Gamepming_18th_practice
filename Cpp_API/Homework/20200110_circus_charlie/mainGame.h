#pragma once
#include"gameNode.h"
#include "GameLoad.h"

class mainGame :  public gameNode
{
private:
	GameLoad * _game;
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(HDC hdc);//�׸��°�
	
};

