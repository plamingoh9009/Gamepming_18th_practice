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

	// �ڵ����� �����̴�.
	const int _CAR_W = 16 * 2;
	const int _CAR_H = 22 * 2;
	// �ڵ����� ���ǵ带 �����ϴ� ���̴�. (�����δ� ū ���� �ʿ���.)
	const int _SPEED_FOR_CALC = 150;
	// �ڵ����� �ְ� �ӵ���.
	const int _MAX_SPEED = 10;

	// �ڵ����� ��, �� ����Ÿ ���� ������ ���� ���̴�.
	const int _MAGENTA_BAND = static_cast<const int> (_CAR_W * 0.2);

public:
	const int get_MAGENTA_BAND();
	const int get_CAR_H();
	const int get_CAR_W();
	POINT get_posPlayer();
	int get_speed();
	const int get_SPEED_FOR_CALC();
	const int get_MAX_SPEED();

	// ȭ��ǥŰ�� ������ �� ���� �����δ�.
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

