#pragma once
#include "Stage.h"
class mainGame :  public gameNode
{
private:
	Stage * _stage;
public:
	mainGame();
	~mainGame();
	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�
};

