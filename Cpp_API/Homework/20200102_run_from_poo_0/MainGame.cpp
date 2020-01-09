#include "stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init()
{
	GameNode::init();

	// 미사일 랜덤한 위치에 셋팅 -> 위치는 언제나 윈도우의 위쪽이어야 한다.
	srand(static_cast<UINT>(time(NULL)));
	//POINT ptMissle;
	for (int i = 0; i < MAX_MISSLE; i++)
	{
		/*ptMissle.x = rand() % WINSIZEX;
		ptMissle.y = rand() % (WINSIZEY / 5);

		box[i].rc = RectMake(ptMissle.x, ptMissle.y, SIZE_MISSLE, SIZE_MISSLE);
		box[i].touch = false;*/
		initOneMissle(&box[i]);
	}

	// 플레이어를 초기화한다.
	player = RectMake(WINSIZEX / 2, HEIGHT_GROUND - SIZE_PLAYER,
		SIZE_PLAYER, SIZE_PLAYER);
	_score = 0;

	// 게임정지, 게임종료 변수다.
	gameStartF = false;
	gameOverF = false;

	// 출력할 메시지를 정의한다.
	wsprintf(strTitle, "### 똥피하기 게임 ###");
	wsprintf(strEnd, "Game Over !!!");
	wsprintf(strScore, "점수: %d", _score);

	return S_OK;
}

void MainGame::release()
{
	GameNode::release();
}

void MainGame::update()
{
	GameNode::update();

	int missleTarget = rand() % MAX_MISSLE;
	// 미사일이 내려오는 로직
	if (KEYMANAGER->isToggleKey(VK_SPACE) &&
		gameOverF == false)
	{
		gameStartF = true;

		//moveOneMissle(&box[missleTarget].rc);

		// 미사일 배열을 함수로 넘겨서 위치를 바꾼다. (점점 내려온다)
		// 점수도 여기서 업데이트 한다.
		_score += moveMissles(box);
		wsprintf(strScore, "점수: %d", _score);
	}//end of if: 스페이스바 누르면 게임 시작한다.
	else
	{
		gameStartF = false;
	}//end of else: 한 번더 누르면 게임을 멈춘다.

	// 여기서 캐릭터가 움직인다.
	if (gameOverF == false)
	{
		run_playerMove(&player);
	}

	// 게임오버를 판단한다.
	check_gameOver();
}

void MainGame::render(HDC hdc)
{
	// 메인게임에서 그려주는 부분을 담당

	// 미사일을 그린다.
	for (int i = 0; i < MAX_MISSLE; i++)
	{
		Rectangle(hdc, box[i].rc.left, box[i].rc.top,
			box[i].rc.right, box[i].rc.bottom);
	}

	// 제목을 그려준다.
	if (gameStartF == false && gameOverF == false)
	{
		TextOut(hdc, WINSIZEX / 2 - 100, 20, strTitle, strlen(strTitle));
	}//end of if: 게임이 멈추고, 게임 종료가 아닐때

	// 게임 종료를 그려준다.
	if (gameOverF == true)
	{
		TextOut(hdc, WINSIZEX / 2 - 100,
			WINSIZEY / 2, strEnd, strlen(strEnd));
	}

	// 점수를 그려준다.
	TextOut(hdc, WINSIZEX / 15, WINSIZEY / 15,
		strScore, strlen(strScore));
	// 내 캐릭터를 그려준다.
	TextOut(hdc, player.left, player.top, "옷", strlen("옷"));
	//RectangleMake(hdc, player);

	// 땅을 그려준다.
	MoveToEx(hdc, 0, HEIGHT_GROUND, NULL);
	LineTo(hdc, WINSIZEX, HEIGHT_GROUND);
}

void MainGame::check_gameOver()
{
	RECT temp;
	for (int i = 0; i < MAX_MISSLE; i++)
	{
		if (IntersectRect(&temp, &box[i].rc, &player))
		{
			// 게임을 멈추고
			keybd_event(VK_SPACE, NULL, 0, 0);
			// 게임을 종료한다.
			gameOverF = true;
		}//end of if: 만약 충돌했다면
	}

	// 만약 게임 오버상태에서 ESC 키를 누르면 게임 종료.
	// 다른 키를 누르면 게임을 재시작한다.
	if (gameOverF == true)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
		{
			release();
		}//end of if: esc를 누른다면
		if (KEYMANAGER->isOnceKeyDown(0x52))
		{
			// 게임을 재시작한다.
			init();
		}//end of if: space 바를 누른다면
	}//end of if: 게임이 끝났을 때
}

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}
