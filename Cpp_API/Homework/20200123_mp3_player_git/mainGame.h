#pragma once
#include"gameNode.h"
#include "MP3.h"
class mainGame :  public gameNode
{
private:
	MP3 * _mp3;
public:
	mainGame();
	~mainGame();
	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�
};

