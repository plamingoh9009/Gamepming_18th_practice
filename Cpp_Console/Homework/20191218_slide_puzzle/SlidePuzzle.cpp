#include "SlidePuzzle.h"



void SlidePuzzle::init_()
{
	// 퍼즐을 사용할 보드 숫자를 초기화한다.
	int number = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			_board[i][k] = number + 1;
			_answerBoard[i][k] = number + 1;
			number++;
		}
	}
	_board[4][4] = 0;
	_answerBoard[4][4] = 0;

	// _isGameOver를 초기화한다.
	_isGameOver = false;
}

void SlidePuzzle::run_()
{
	// 게임이 여기서 시작된다.
	// 보드를 여기서 섞는다.
	suffle_board();

	while (_isGameOver == false)
	{
		// 게임이 돌아가는 동안 보드를 새로 그리고, 
		// 입력 받은 좌표를 업데이트 한다.
		show_board();
		update_();

		// 게임이 끝났는지 아닌지 확인해서 끝이면 종료한다.
		if (is_gameOver() == true)
		{
			// 게임의 승리 메시지를 띄우면서 종료
			show_board();
			cout << "Player Win !!!" << endl;
			system("pause");
			break;
		}
	}
}

void SlidePuzzle::exit_()
{
	// 게임이 종료될 때 호출한다.
	// 게임의 종료를 알리는 함수다.
	cout << "게임을 안전하게 종료합니다." << endl;
	Sleep(2000);
}

void SlidePuzzle::update_()
{
	// 입력을 받아서 보드를 업데이트 하는 함수다.
	// 1. 먼저 입력을 받은 다음에
	// 2. 업데이트를 계산한다.
	// 3. 만약 계산값이 range를 벗어나면
	// 4. 아무일도 일어나지 않는다.

	// 입력 받는 부분
	int key = 0;
	if (_kbhit() == 1)
	{
		// _kbhit 값이 있으면 방향키를 받았는지 확인한다.
		key = _getch();
		// 방향키 받았는지 확인
		if (key == 224)
		{
			key = _getch();
		}

		// 입력이 a 이면 정답으로 셋팅한다.
		if (key == (int)'A' || key == (int)'a')
		{
			init_();
		}
		// 입력이 -1이면 게임을 종료한다.
		if (key == (int)'Q' || key == (int)'q')
		{
			_isGameOver = true;
		}

		/*cout << key << endl;
		system("pause");*/
		/*cout << isValid(key) << endl;
		system("pause");*/
		// 키 값을 받은 경우 여기서 isValid 함수로 벽인지 아닌지 확인
		if (isValid(key) == true)
		{
			// 벽이 아니라면 swap_ 함수로 보드판의 값을 스왑한다.
			swap_(key);
		}
	}// end of if: 키 값이 있을 경우
	else
	{
		// 키 값이 없을 경우 좀 기다린다.
		// 키 값이 없을 때 보드를 다시 한 번 그려주면 중간 버퍼를 줄일 수 있다.
		show_board();
		Sleep(1000);
	}
}

void SlidePuzzle::suffle_board()
{
	// 보드를 랜덤하게 섞는 함수다. 배열을 완전 랜덤으로 섞으면
	// 절대 못깨는 배열이 나올 수 있으니까 랜덤으로 생성하는 타겟은
	// 방향키 !!!
	//cout << "Call Suffle Board" << endl;

	// rand() 시드값을 초기화 한다.
	srand((unsigned int)time(NULL));

	int keySet[4] = { KEY_LEFT, KEY_UP, KEY_RIGHT, KEY_DOWN };

	// 몇개의 방향키를 생성할지 정한다.
	int i = 0;
	while(i < 500)
	{
		// 랜덤 방향키 생성
		int key = rand() % 4;
		
		if (isValid(keySet[key]))
		{
			// 벽이 아닌 경우 스왑한다.
			swap_(keySet[key]);
			// 스왑에 성공한 경우만 카운트를 올린다.
			i++;
		}
		// 스왑에 실패한 경우 카운트를 세지 않는다.
	}
}

void SlidePuzzle::show_board()
{
	// 숫자와 특수문자를 편히 보여주기 위한 변수다.
	string number = "";
	// 업데이트 된 보드를 보여주는 함수다.
	system("cls");
	cout << "*** Sliding Puzzle Game ***" << endl;
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << "==================" << endl;
		//cout << "----------------------------" << endl;
		for (int k = 0; k < 5; k++)
		{
			//cout << "| ";
			// _board 값이 0이면 특수문자, 숫자면 그대로
			// number에 넣는다.
			if (_board[i][k] == 0)
			{
				number = "■";
			}
			else
			{
				number = to_string(_board[i][k]);
			}
			cout << setw(2) << number << "  ";
		}
		cout << endl;
		//cout << endl;
	}
	cout << "==================" << endl;
	//cout << "----------------------------" << endl;
}

bool SlidePuzzle::is_gameOver()
{
	bool gameOver = false;
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			if (_board[i][k] != _answerBoard[i][k])
			{
				// 정답 보드와 같지 않으면 loop 탈출
				gameOver = false;
				return gameOver;
			}
		}
	}
	// 루프를 멀쩡히 탈출했다면 _board가 정답과 같다.
	gameOver = true;

	return gameOver;
}

bool SlidePuzzle::isValid(int key)
{
	bool myValid = false;

	// 현재 0이 어디에 있는지 알아낸다.
	int* zeroPos = get_zeroPos();
	/*cout << zeroPos[0] << " " << zeroPos[1] << endl;
	system("pause");*/
	// 스왑할 수 있는지 아닌지 여부를 리턴한다.
	switch (key)
	{
		// zeroPos[1] 이 x 축
		// zeroPos[0] 이 y 축이다.
	case KEY_LEFT:
		// 왼쪽일 경우 (x축 - 1)이 0보다 크거나 같아야 한다.
		if (zeroPos[1] - 1 >= 0)
		{
			myValid = true;
		}
		break;
	case KEY_UP:
		// 위쪽일 경우 (y축 - 1)이 0보다 크거나 같아야 한다.
		if (zeroPos[0] - 1 >= 0)
		{
			myValid = true;
		}
		break;
	case KEY_RIGHT:
		// 오른쪽일 경우 (x축 + 1)이 4보다 작거나 같아야 한다.
		if (zeroPos[1] + 1 <= 4)
		{
			myValid = true;
		}
		break;
	case KEY_DOWN:
		// 아래쪽일 경우 (y축 + 1)이 4보다 크거나 같아야 한다.
		if (zeroPos[0] + 1 <= 4)
		{
			myValid = true;
		}
		break;
	}
	return myValid;
}

void SlidePuzzle::swap_(int key)
{
	// 0 의 위치를 찾은 다음에 key 값을 가지고 어느 방향으로 스왑할지 정한다.
	int *zeroPos = get_zeroPos();
	int x = zeroPos[1];
	int y = zeroPos[0];
	switch (key)
	{
		// zeroPos[1] 이 x축
		// zeroPos[0] 이 y축이다.
	case KEY_LEFT:
		// (x축 - 1) 과 스왑한다.
		_board[y][x] = _board[y][x - 1];
		_board[y][x - 1] = 0;
		break;
	case KEY_UP:
		// (y축 - 1) 과 스왑한다.
		_board[y][x] = _board[y - 1][x];
		_board[y - 1][x] = 0;
		break;
	case KEY_RIGHT:
		// (x축 + 1) 과 스왑한다.
		_board[y][x] = _board[y][x + 1];
		_board[y][x + 1] = 0;
		break;
	case KEY_DOWN:
		// (y축 + 1) 과 스왑한다.
		_board[y][x] = _board[y + 1][x];
		_board[y + 1][x] = 0;
		break;
	}
}

int * SlidePuzzle::get_zeroPos()
{
	int zeroPos[2] = { 0, 0 };
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			if (_board[i][k] == 0)
			{
				zeroPos[0] = i;
				zeroPos[1] = k;
			}
		}
	}
	return zeroPos;
}

SlidePuzzle::SlidePuzzle()
{
}


SlidePuzzle::~SlidePuzzle()
{
	exit_();
}
