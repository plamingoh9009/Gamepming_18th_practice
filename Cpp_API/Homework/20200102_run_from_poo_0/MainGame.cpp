#include "stdafx.h"
#include "MainGame.h"


HRESULT MainGame::init()
{
	GameNode::init();

	// �̻��� ������ ��ġ�� ���� -> ��ġ�� ������ �������� �����̾�� �Ѵ�.
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

	// �÷��̾ �ʱ�ȭ�Ѵ�.
	player = RectMake(WINSIZEX / 2, HEIGHT_GROUND - SIZE_PLAYER,
		SIZE_PLAYER, SIZE_PLAYER);
	_score = 0;

	// ��������, �������� ������.
	gameStartF = false;
	gameOverF = false;

	// ����� �޽����� �����Ѵ�.
	wsprintf(strTitle, "### �����ϱ� ���� ###");
	wsprintf(strEnd, "Game Over !!!");
	wsprintf(strScore, "����: %d", _score);

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
	// �̻����� �������� ����
	if (KEYMANAGER->isToggleKey(VK_SPACE) &&
		gameOverF == false)
	{
		gameStartF = true;

		//moveOneMissle(&box[missleTarget].rc);

		// �̻��� �迭�� �Լ��� �Ѱܼ� ��ġ�� �ٲ۴�. (���� �����´�)
		// ������ ���⼭ ������Ʈ �Ѵ�.
		_score += moveMissles(box);
		wsprintf(strScore, "����: %d", _score);
	}//end of if: �����̽��� ������ ���� �����Ѵ�.
	else
	{
		gameStartF = false;
	}//end of else: �� ���� ������ ������ �����.

	// ���⼭ ĳ���Ͱ� �����δ�.
	if (gameOverF == false)
	{
		run_playerMove(&player);
	}

	// ���ӿ����� �Ǵ��Ѵ�.
	check_gameOver();
}

void MainGame::render(HDC hdc)
{
	// ���ΰ��ӿ��� �׷��ִ� �κ��� ���

	// �̻����� �׸���.
	for (int i = 0; i < MAX_MISSLE; i++)
	{
		Rectangle(hdc, box[i].rc.left, box[i].rc.top,
			box[i].rc.right, box[i].rc.bottom);
	}

	// ������ �׷��ش�.
	if (gameStartF == false && gameOverF == false)
	{
		TextOut(hdc, WINSIZEX / 2 - 100, 20, strTitle, strlen(strTitle));
	}//end of if: ������ ���߰�, ���� ���ᰡ �ƴҶ�

	// ���� ���Ḧ �׷��ش�.
	if (gameOverF == true)
	{
		TextOut(hdc, WINSIZEX / 2 - 100,
			WINSIZEY / 2, strEnd, strlen(strEnd));
	}

	// ������ �׷��ش�.
	TextOut(hdc, WINSIZEX / 15, WINSIZEY / 15,
		strScore, strlen(strScore));
	// �� ĳ���͸� �׷��ش�.
	TextOut(hdc, player.left, player.top, "��", strlen("��"));
	//RectangleMake(hdc, player);

	// ���� �׷��ش�.
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
			// ������ ���߰�
			keybd_event(VK_SPACE, NULL, 0, 0);
			// ������ �����Ѵ�.
			gameOverF = true;
		}//end of if: ���� �浹�ߴٸ�
	}

	// ���� ���� �������¿��� ESC Ű�� ������ ���� ����.
	// �ٸ� Ű�� ������ ������ ������Ѵ�.
	if (gameOverF == true)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
		{
			release();
		}//end of if: esc�� �����ٸ�
		if (KEYMANAGER->isOnceKeyDown(0x52))
		{
			// ������ ������Ѵ�.
			init();
		}//end of if: space �ٸ� �����ٸ�
	}//end of if: ������ ������ ��
}

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}
