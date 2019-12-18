#pragma once
#include <iostream>

#include <iomanip>
#include <conio.h>
#include <time.h>
#include <string>

#include <Windows.h>
#include <Winuser.h>

using namespace std;

class SlidePuzzle
{
private:
	// 여기서 필요한 변수를 선언한다.
	// 퍼즐 보드를 선언한다.
	int _board[5][5];
	int _answerBoard[5][5];
	// 키보드 방향키 값을 선언한 것이다.
	enum _inputKey
	{
		KEY_LEFT = 75,
		KEY_UP = 72,
		KEY_RIGHT = 77,
		KEY_DOWN = 80
	};
	// 게임을 끝낼지 말지 결정하는 변수다.
	bool _isGameOver;
public:
	// 메인에서 호출할 함수다.
	void init_();
	void run_();

protected:
	// run_() 에서 동작하는 함수다.
	void update_();
	void suffle_board();
	void show_board();
	bool is_gameOver();

	// update_() 에서 동작하는 함수다.
	bool isValid(int key);
	void swap_(int key);

	// 현재 0의 위치가 어디에 있는지 리턴하는 함수다.
	int* get_zeroPos();

	// 소멸자가 호출할 함수다.
	void exit_();
public:
	SlidePuzzle();
	~SlidePuzzle();
};

