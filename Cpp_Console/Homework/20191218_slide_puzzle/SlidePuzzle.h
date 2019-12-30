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
	// ���⼭ �ʿ��� ������ �����Ѵ�.
	// ���� ���带 �����Ѵ�.
	int _board[5][5];
	int _answerBoard[5][5];
	// Ű���� ����Ű ���� ������ ���̴�.
	enum _inputKey
	{
		KEY_LEFT = 75,
		KEY_UP = 72,
		KEY_RIGHT = 77,
		KEY_DOWN = 80
	};
	// ������ ������ ���� �����ϴ� ������.
	bool _isGameOver;
public:
	// ���ο��� ȣ���� �Լ���.
	void init_();
	void run_();

protected:
	// run_() ���� �����ϴ� �Լ���.
	void update_();
	void suffle_board();
	void show_board();
	bool is_gameOver();

	// update_() ���� �����ϴ� �Լ���.
	bool isValid(int key);
	void swap_(int key);

	// ���� 0�� ��ġ�� ��� �ִ��� �����ϴ� �Լ���.
	int* get_zeroPos();

	// �Ҹ��ڰ� ȣ���� �Լ���.
	void exit_();
public:
	SlidePuzzle();
	~SlidePuzzle();
};

