#pragma once
#include "gameNode.h"
#include "LoadOption.h"

#define	GROUND			WINSIZEY * 0.8926
#define SPEED_GRAVITY	1
#define SPEED_PLAYER	3

enum position
{
	POS_EMPTY,
	POS_LEFT,
	POS_RIGHT
};
class Player : public gameNode
{
private:
	char str[128];
	image * _img;

	POINT _posInit;

	POINT _sizePlayer = {247, 94};
	const int _SPEED_FRAME = 10;
	int _maxFrame;
	int _count;
	int _index;

	// 이동거리
	int _distance_moved;

	// 점프 변수
	bool _fJump;
	bool _fIsGround;
	int _distance_jump;

	// 맵이 멈출 경우 캐릭터가 움직인다.
	bool _fPlayerMove;
public:
	void stayMoved(position);
	void gravity();
	void gravityReverse();

	bool get_fPlayerMove();
	void set_fPlayerMove(bool);
	int get_posInitX();
	int get_playerX();
	POINT get_sizePlayer();
	void set_distance_moved(int);
	int get_distance_moved();
	
	void moveJump();
	void moveRight();
	void movePlayerRight();
	void moveLeft();
	void movePlayerLeft();
public:
	Player();
	~Player();

	HRESULT init(loadIndex);
	void release();
	void update();
	void update(int indexMap);
	void render();
};

