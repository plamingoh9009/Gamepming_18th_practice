#pragma once
#include "Map.h"

class MainGame
{
private:
	// ���� �����
	bool _isGameOver;
	
public:
	// main���� ���� ������ �Լ� ����
	virtual void init_();
	virtual void run_();
protected:
	// main���� �����ϸ� �ȵǴ� �Լ� ����
	virtual void exit_();
	int inputKey();

public:
	MainGame();
	~MainGame();
};

