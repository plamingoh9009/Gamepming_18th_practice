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

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(HDC hdc);//�׸��°�
};

