#pragma once
#include "GameNode.h"

// 미사일 정보
#define MAX_MISSLE 30
#define SIZE_MISSLE 30
// 플레이어 정보
#define SIZE_PLAYER 15

struct missle
{
	RECT rc;
	bool touch;
};

// 땅 정보
#define HEIGHT_GROUND (WINSIZEY / 10) * 9

static int _score;

class MainGame : public GameNode
{
private:
	missle box[MAX_MISSLE];
	RECT player;

	char strTitle[128];
	char strEnd[128];
	char strScore[128];

	bool gameStartF;
	bool gameOverF;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	// 내가 만든 함수
	void check_gameOver();
public:
	MainGame();
	~MainGame();
};

