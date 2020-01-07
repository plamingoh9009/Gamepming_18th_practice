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
	_cuteStarIdle->init("images/��_�Ϳ��_IdleX2.bmp",
		_ptcuteStar.x, _ptcuteStar.y,
		400, SIZE_CHARACTOR_Y, 5, 1, true, RGB(255, 0, 255));

	_cuteStarMove = new image;
	_cuteStarMove->init("images/��_�Ϳ��_MoveX2.bmp",
		_ptcuteStar.x, _ptcuteStar.y,
		640, SIZE_CHARACTOR_Y * 2, 8, 2, true, RGB(255, 0, 255));

	_countIdle = 0;
	_indexIdle = 0;

	// �Ϳ�̰� �������� �ƴ��� ���Ѵ�.
	_countMove = 0;
	_indexMove = 0;

	_isMove = false;
	_isJump = false;
	_posJump = 0;

	_position = 0;

	// ��ֹ��� ���⼭ �����Ѵ�.
	_wall[0] = RectMake(298, 213, 87, 234);
	_wall[1] = RectMake(810, 213, 45, 234);
	_wall[2] = RectMake(874, 213, 23, 234);

	// ���ٴ��� ���⼭ �����Ѵ�.
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
		}//end of if: ����Ű�� ������ ��
		else
		{
			MoveStar(VK_LEFT);
		}
	}//end of if: ���� ȭ��ǥŰ ������ ��
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
	}//end of if: ������ ȭ��ǥŰ ������ ��
	else if (KEYMANAGER->isOnceKeyDown(VK_UP) && _isJump == false)
	{
		_isMove = true;

		_isJump = true;
		JumpStar(VK_LEFT);
		_position = POS_UP;
	}//end of if: ���� ȭ��ǥŰ�� ������ ��
	else
	{
		//�Ϳ�̰� Idle ������ ��
		_isMove = false;
		IdleStar();
	}

	// ���⼭ ��ֹ��� ����� ���� �����Ѵ�.
	RECT wall = WallToStep();

	if (IsRectEmpty(&wall) == false)
	{
		_isWallToStep = true;
		// �߷��� ��ֹ� ���� �����Ѵ�.
		_ground = wall.top - SIZE_CHARACTOR_Y;

	}//end of if: ��ֹ��� ��Ҵٸ�
	else
	{
		_isWallToStep = false;
		_ground = GROUND_CUTESTAR;
	}//end of else: ��ֹ��� ���� �ʾҴٸ�

	// ���⼭ �߷��� �׻� ����ȴ�.
	if (_isJump == false || _posJump == 0)
	{
		Gravity();

		if (_isJump == true)
		{
			StillMove(static_cast<KEY_POSITION>(_position));
		}//end of if: ���� ���� ���� �ʾҴٸ� ����������� ������ �����Ѵ�.
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
	}//end of if: �Ϳ�̰� Idle ������ ��
	else
	{
		_cuteStarMove->frameRender(hdc,
			_ptcuteStar.x, _ptcuteStar.y,
			_cuteStarMove->getFrameX(), _cuteStarMove->getFrameY());
	}//end of else: �Ϳ�̰� Move ������ ��

	//// ���⼭ ��ֹ��� �׸���.
	//for (int i = 0; i < 3; i++)
	//{
	//	RectangleMake(hdc, _wall[0]);
	//	RectangleMake(hdc, _wall[1]);
	//	RectangleMake(hdc, _wall[2]);
	//}

	if (_isWallToStep == true)
	{
		TextOut(hdc, 20, 20, "��ֹ� ��Ҵ� !!!", strlen("��ֹ� ��Ҵ� !!!"));
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
	// �Ϳ�̰� ������ �ִ� ���¸� �����Ѵ�.
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
	// ����Ű�� ������ ���� ������ Ű�� ������ ��
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

		// ����Ű�� ������ �� �ö󰡴� �ڵ�
		_posJump = _ptcuteStar.y - distance;

		// �������� ���� ���
		_cuteStarMove->setFrameY(0);
		_indexMove = 6;
		_cuteStarMove->setFrameX(_indexMove);
		break;
	case VK_RIGHT:

		// ����Ű�� ������ �� �ö󰡴� �ڵ�
		_posJump = _ptcuteStar.y - distance;

		// �������� ���� ���
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
	}//end of if: ���� ���� ���� �ʾ��� ��
	else
	{
		_isJump = false;
	}//end of else: ���� ���� ����� ��
}

void CuteStar::ReverseGravity()
{
	LONG distance = static_cast<LONG>(MOVE_DISTANCE * 0.5);

	if (_ptcuteStar.y > _posJump)
	{
		_ptcuteStar.y -= distance;
	}//end of if: ���� ���� ��ġ���� ���� ������ ��
	else
	{
		_posJump = 0;
	}//end of else: ���� ���� ��ġ�� �������� ��
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
			}//end of if: ��ֹ��� �� �ؿ� �ִٸ�
		}//end of if: ��ֹ��� �´�Ұ�
	}
	return wallResult;
}

CuteStar::CuteStar()
{
}


CuteStar::~CuteStar()
{
}
