#pragma once
#include"gameNode.h"
#include "Map.h"
#include "Car.h"
#include "OtherCar.h"

class mainGame :  public gameNode
{
private:
	Map * _map;
	Car * _player;
	OtherCar * _other;

	int _speed_player;
	int _maxSpeed;

	int _mapMove;
public:
	void check_crush();

	void set_mapMove();
	void renderTest(HDC);
public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(HDC hdc);//그리는곳
};

