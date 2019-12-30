#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <map>

using namespace std;

enum PAGE_CHOICE
{
	PAGE_EXIT = 0,
	PAGE_ONE,
	PAGE_TWO,
	PAGE_THREE,
	PAGE_END
};
enum WARN_MESSAGE
{
	WARN_INVALID_INPUT
};

class GameBase
{
private:
	
protected:
	virtual int input_choice();
	virtual void show_warnMessage(WARN_MESSAGE myCase);
public:
	GameBase();
	~GameBase();
};

