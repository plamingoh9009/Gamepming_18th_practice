#pragma once
#include "Map.h"

class MainGame
{
private:
	// 변수 선언부
	bool _isGameOver;
	
public:
	// main에서 접근 가능한 함수 선언
	virtual void init_();
	virtual void run_();
protected:
	// main에서 접근하면 안되는 함수 선언
	virtual void exit_();
	int inputKey();

public:
	MainGame();
	~MainGame();
};

