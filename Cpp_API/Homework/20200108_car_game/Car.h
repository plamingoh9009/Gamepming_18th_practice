#pragma once
#include "gameNode.h"

enum POSITION
{
	KEY_EMPTY,
	KEY_LEFT,
	KEY_RIGHT
};
class Car : public gameNode
{
private:
	image * _player;
	POINT _posPlayer;
	POSITION _backInRoad;

	int _speed;
	bool _b_speed_up;

	// 자동차의 제원이다.
	const int _CAR_W = 16 * 2;
	const int _CAR_H = 22 * 2;
	// 자동차의 스피드를 보정하는 값이다. (실제로는 큰 값이 필요함.)
	const int _SPEED_FOR_CALC = 150;
	// 자동차의 최고 속도다.
	const int _MAX_SPEED = 10;

	// 자동차의 좌, 우 마젠타 영역 보정을 위한 값이다.
	const int _MAGENTA_BAND = static_cast<const int> (_CAR_W * 0.2);

public:
	const int get_MAGENTA_BAND();
	const int get_CAR_H();
	const int get_CAR_W();
	POINT get_posPlayer();
	int get_speed();
	const int get_SPEED_FOR_CALC();
	const int get_MAX_SPEED();

	// 화살표키를 눌렀을 때 차가 움직인다.
	void upSpeed();
	void downSpeed();
	void downSpeed(int speed);
	void moveBackInRoad(POSITION);
	bool isMoveOK();
public:
	Car();
	~Car();

	HRESULT init();
	void update();
	void render(HDC hdc);
	void release();

	void renderTest(HDC);
};

