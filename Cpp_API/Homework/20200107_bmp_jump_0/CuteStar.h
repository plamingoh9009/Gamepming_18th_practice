#pragma once
#include "gameNode.h"

enum KEY_POSITION {
	POS_EMPTY,
	POS_LEFT,
	POS_RIGHT,
	POS_UP
};

class CuteStar : public gameNode
{
private:
	// 여기서 장애물을 선언한다.
	RECT _wall[3];
	LONG _ground;
	bool _isWallToStep;

	char str[128];

	// 여기서 귀요미를 선언한다.
	POINT _ptcuteStar;
	image * _cuteStarIdle;
	image * _cuteStarMove;

	int _countIdle;
	int _indexIdle;
	int _countMove;
	int _indexMove;

	bool _isMove;
	bool _isJump;
	int _posJump;

	int _position;

public:
	HRESULT init();
	void update();
	void render(HDC);
	void release();

	void IdleStar();
	void MoveStar(LPARAM);
	void JumpStar(LPARAM);

	void Gravity();
	void ReverseGravity();
	void StillMove(KEY_POSITION);

	RECT WallToStep();
public:
	CuteStar();
	~CuteStar();
};

