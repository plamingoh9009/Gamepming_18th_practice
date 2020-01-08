#pragma once
#include "gameNode.h"
class OtherCar : public gameNode
{
private:
	image *	_carImage[2];
	POINT	_posCar;
	int		_kind;

	int _test1;
	int _test2;
public:
	POINT get_posCar();
	void init_posCar();
public:
	OtherCar();
	~OtherCar();

	HRESULT init();
	void update(int maxSpeed, int speed_player);
	void render(HDC hdc);
	void release();

	void renderTest(HDC);
};

