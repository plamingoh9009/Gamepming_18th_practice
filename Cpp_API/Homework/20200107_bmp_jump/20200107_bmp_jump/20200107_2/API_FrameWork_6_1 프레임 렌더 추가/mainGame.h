#pragma once
#include"gameNode.h"

class mainGame :  public gameNode
{
private:
	image* _bgImage;
	CuteStar _cuteStar;
	//image* _rockman;

	bool _isLeft;	// 왼쪽임
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(HDC hdc);//그리는곳

	
};

