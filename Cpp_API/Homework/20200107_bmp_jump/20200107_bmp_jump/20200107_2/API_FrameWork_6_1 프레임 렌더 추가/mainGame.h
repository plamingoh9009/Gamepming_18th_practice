#pragma once
#include"gameNode.h"

class mainGame :  public gameNode
{
private:
	image* _bgImage;
	CuteStar _cuteStar;
	//image* _rockman;

	bool _isLeft;	// ������
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(HDC hdc);//�׸��°�

	
};

