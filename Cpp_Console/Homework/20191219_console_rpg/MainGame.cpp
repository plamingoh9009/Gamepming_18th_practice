#include "MainGame.h"



void MainGame::init_()
{
	_isGameOver = false;
}

void MainGame::run_()
{
	// 메인에서 게임을 실행하면 호출되는 함수다.
	// 1. 여기서 맵을 호출한다.
	Map stage1_town;
	stage1_town.init_(1);

	// loop를 사용해서 키입력 받고, 다시 그린다.
	int myKey = 0;
	bool isStageOver = stage1_town.get_isStageOver();
	while (isStageOver == false)
	{
		// 루프를 돌려서 키를 입력받고, 업데이트 하고, 그린다.
		myKey = inputKey();
		stage1_town.update_map(myKey);

		// 탈출조건은 q를 입력받았을 때
		if (myKey == 'q' || myKey == 'Q')
		{
			isStageOver = true;
			stage1_town.set_isStageOver(true);
		}
	}
}

void MainGame::exit_()
{
	cout << "프로그램을 안전하게 종료합니다." << endl;
	Sleep(1000);
}

int MainGame::inputKey()
{
	int myKey = 0;
	if (_kbhit())
	{
		// 키 입력이 있을 경우 스위치 문을 써서 각 방향키에 맞게 리턴한다.
		myKey = _getch();
		if (myKey == 224)
		{
			myKey = _getch();
			return myKey;
			/*cout << "True" << endl;*/
		}// end of if: 방향키 입력 받았다면
		else if (myKey == 'q' || myKey == 'Q')
		{
			return myKey;
		}// end of if: 종료키를 입력 받았다면
	}
	else
	{
		// 키 입력이 없을 경우
		//Sleep(300);
	}
	return 0;
}

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	exit_();
}

