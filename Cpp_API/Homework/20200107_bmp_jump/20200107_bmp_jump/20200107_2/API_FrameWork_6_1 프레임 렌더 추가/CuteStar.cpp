#include "stdafx.h"
#include "CuteStar.h"

#define SIZE_CHARACTOR_Y 78
#define GROUND_CUTESTAR (WINSIZEY - SIZE_CHARACTOR_Y)
#define MOVE_DISTANCE 8

HRESULT CuteStar::init()
{
	_ptcuteStar.x = WINSIZEX / 2;
	_ptcuteStar.y = WINSIZEY - SIZE_CHARACTOR_Y;

	_cuteStarIdle = new image;
	_cuteStarIdle->init("images/별_귀요미_IdleX2.bmp",
		_ptcuteStar.x, _ptcuteStar.y,
		400, SIZE_CHARACTOR_Y, 5, 1, true, RGB(255, 0, 255));

	_cuteStarMove = new image;
	_cuteStarMove->init("images/별_귀요미_MoveX2.bmp",
		_ptcuteStar.x, _ptcuteStar.y,
		640, SIZE_CHARACTOR_Y * 2, 8, 2, true, RGB(255, 0, 255));

	_countIdle = 0;
	_indexIdle = 0;

	// 귀요미가 움직일지 아닐지 정한다.
	_countMove = 0;
	_indexMove = 0;

	_isMove = false;
	_isJump = false;
	_posJump = 0;

	_position = 0;

	// 장애물은 여기서 정의한다.
	_wall[0] = RectMake(298, 213, 87, 234);
	_wall[1] = RectMake(810, 213, 45, 234);
	_wall[2] = RectMake(874, 213, 23, 234);

	// 땅바닥을 여기서 정의한다.
	_ground = GROUND_CUTESTAR;
	_isWallToStep = false;

	return S_OK;
}

void CuteStar::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_isMove = true;

		if (KEYMANAGER->isOnceKeyDown(VK_UP) && _isJump == false)
		{
			_isJump = true;
			JumpStar(VK_LEFT);
			_position = POS_LEFT;
		}//end of if: 점프키를 눌렀을 때
		else
		{
			MoveStar(VK_LEFT);
		}
	}//end of if: 왼쪽 화살표키 눌렀을 때
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_isMove = true;

		if (KEYMANAGER->isOnceKeyDown(VK_UP) && _isJump == false)
		{
			_isJump = true;
			JumpStar(VK_RIGHT);
			_position = POS_RIGHT;
		}
		else
		{
			MoveStar(VK_RIGHT);
		}
	}//end of if: 오른쪽 화살표키 눌렀을 때
	else if (KEYMANAGER->isOnceKeyDown(VK_UP) && _isJump == false)
	{
		_isMove = true;

		_isJump = true;
		JumpStar(VK_LEFT);
		_position = POS_UP;
	}//end of if: 위쪽 화살표키를 눌렀을 때
	else
	{
		//귀요미가 Idle 상태일 때
		_isMove = false;
		IdleStar();
	}

	// 여기서 장애물을 밟았을 때를 정의한다.
	RECT wall = WallToStep();

	if (IsRectEmpty(&wall) == false)
	{
		_isWallToStep = true;
		// 중력을 장애물 위로 적용한다.
		_ground = wall.top - SIZE_CHARACTOR_Y;

	}//end of if: 장애물을 밟았다면
	else
	{
		_isWallToStep = false;
		_ground = GROUND_CUTESTAR;
	}//end of else: 장애물을 밟지 않았다면

	// 여기서 중력이 항상 적용된다.
	if (_isJump == false || _posJump == 0)
	{
		Gravity();

		if (_isJump == true)
		{
			StillMove(static_cast<KEY_POSITION>(_position));
		}//end of if: 아직 땅에 닿지 않았다면 진행방향으로 관성을 적용한다.
	}
	else
	{
		ReverseGravity();
		StillMove(static_cast<KEY_POSITION>(_position));
	}
}

void CuteStar::render(HDC hdc)
{
	if (_isMove == false)
	{
		_cuteStarIdle->frameRender(hdc,
			_ptcuteStar.x, _ptcuteStar.y,
			_cuteStarIdle->getFrameX(), _cuteStarIdle->getFrameY());
	}//end of if: 귀요미가 Idle 상태일 때
	else
	{
		_cuteStarMove->frameRender(hdc,
			_ptcuteStar.x, _ptcuteStar.y,
			_cuteStarMove->getFrameX(), _cuteStarMove->getFrameY());
	}//end of else: 귀요미가 Move 상태일 때

	//// 여기서 장애물을 그린다.
	//for (int i = 0; i < 3; i++)
	//{
	//	RectangleMake(hdc, _wall[0]);
	//	RectangleMake(hdc, _wall[1]);
	//	RectangleMake(hdc, _wall[2]);
	//}

	if (_isWallToStep == true)
	{
		TextOut(hdc, 20, 20, "장애물 밟았다 !!!", strlen("장애물 밟았다 !!!"));
		wsprintf(str, "top: %d, bottom: %d",
			_ptcuteStar.y, _ptcuteStar.y + _cuteStarMove->getFrameHeight());
		TextOut(hdc, 20, 40, str, strlen(str));
		wsprintf(str, "wall top: %d", _wall[0].top, strlen(str));
		TextOut(hdc, 20, 60, str, strlen(str));
	}
}

void CuteStar::release()
{
	SAFE_DELETE(_cuteStarIdle);
	SAFE_DELETE(_cuteStarMove);
}

void CuteStar::IdleStar()
{
	// 귀요미가 가만히 있는 상태를 정의한다.
	_countIdle++;
	_cuteStarIdle->setFrameY(0);

	if (_countIdle == 5)
	{
		_countIdle = 0;
		_indexIdle++;

		if (_indexIdle >= _cuteStarIdle->getMaxFrameX())
		{
			_indexIdle = 0;
		}
		_cuteStarIdle->setFrameX(_indexIdle);
	}
}

void CuteStar::MoveStar(LPARAM position)
{
	// 왼쪽키를 눌렀을 때랑 오른쪽 키를 눌렀을 때
	int distance = MOVE_DISTANCE;

	if (position == VK_LEFT)
	{
		_ptcuteStar.x -= distance;

		_countMove++;
		_cuteStarMove->setFrameY(0);

		if (_countMove == 8)
		{
			_countMove = 0;
			_indexMove++;

			if (_indexMove >= _cuteStarMove->getMaxFrameX())
			{
				_indexMove = 0;
			}
			_cuteStarMove->setFrameX(_indexMove);
		}
	}
	if (position == VK_RIGHT)
	{
		_ptcuteStar.x += distance;

		_countMove++;
		_cuteStarMove->setFrameY(1);

		if (_countMove == 8)
		{
			_countMove = 0;
			_indexMove--;

			if (_indexMove < 0)
			{
				_indexMove = 7;
			}
			_cuteStarMove->setFrameX(_indexMove);
		}
	}
}

void CuteStar::JumpStar(LPARAM position)
{
	LONG distance = MOVE_DISTANCE * 8;

	switch (position)
	{
	case VK_LEFT:

		// 점프키를 눌렀을 때 올라가는 코드
		_posJump = _ptcuteStar.y - distance;

		// 점프했을 때의 모션
		_cuteStarMove->setFrameY(0);
		_indexMove = 6;
		_cuteStarMove->setFrameX(_indexMove);
		break;
	case VK_RIGHT:

		// 점프키를 눌렀을 때 올라가는 코드
		_posJump = _ptcuteStar.y - distance;

		// 점프했을 때의 모션
		_cuteStarMove->setFrameY(1);
		_indexMove = 1;
		_cuteStarMove->setFrameX(_indexMove);
		break;
	}
}

void CuteStar::Gravity()
{
	LONG distance = static_cast<LONG>(MOVE_DISTANCE * 0.5);
	
	if (_ptcuteStar.y < _ground)
	{
		_ptcuteStar.y += distance;
	}//end of if: 내가 땅에 닿지 않았을 때
	else
	{
		_isJump = false;
	}//end of else: 내가 땅에 닿았을 때
}

void CuteStar::ReverseGravity()
{
	LONG distance = static_cast<LONG>(MOVE_DISTANCE * 0.5);

	if (_ptcuteStar.y > _posJump)
	{
		_ptcuteStar.y -= distance;
	}//end of if: 내가 점프 위치까지 가지 못했을 때
	else
	{
		_posJump = 0;
	}//end of else: 내가 점프 위치에 도달했을 때
}

void CuteStar::StillMove(KEY_POSITION position)
{
	int distance = 2;
	switch (position)
	{
	case POS_LEFT:
		_ptcuteStar.x -= distance;
		break;
	case POS_RIGHT:
		_ptcuteStar.x += distance;
		break;
	default:
		break;
	}
}

RECT CuteStar::WallToStep()
{
	RECT wallResult, temp, me;
	wallResult = RECT();

	me.left = _ptcuteStar.x;
	me.top = _ptcuteStar.y;
	me.right = me.left + _cuteStarMove->getFrameWidth();
	me.bottom = me.top + _cuteStarMove->getFrameHeight();

	for (int i = 0; i < 3; i++)
	{
		if (IntersectRect(&temp, &_wall[i], &me))
		{
			if (me.bottom <= _wall[i].top+2)
			{
				wallResult = _wall[i];
			}//end of if: 장애물이 내 밑에 있다면
		}//end of if: 장애물과 맞닿았고
	}
	return wallResult;
}

CuteStar::CuteStar()
{
}


CuteStar::~CuteStar()
{
}
