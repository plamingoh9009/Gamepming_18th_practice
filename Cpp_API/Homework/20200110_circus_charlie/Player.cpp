#include "stdafx.h"
#include "Player.h"


void Player::stayMoved(position pos)
{
	switch (pos)
	{
	case POS_LEFT:
		_distance_moved -= SPEED_PLAYER;
		break;
	case POS_RIGHT:
		_distance_moved += SPEED_PLAYER;
		break;
	}
}
void Player::gravity()
{
	int y = _img->getY();
	int bottom = y + _sizePlayer.y;

	if (bottom < GROUND)
	{
		y += SPEED_GRAVITY;
		_img->setY(y);
	}//end of if: 플레이어가 땅에 닿지 않았다면 +
	else
	{
		_fIsGround = true;
	}// 플레이어가 땅에 닿았다면

}
void Player::gravityReverse()
{
	int y = _img->getY();

	if (y > _distance_jump)
	{
		y -= SPEED_GRAVITY;
		_img->setY(y);
	}
	else
	{
		_fJump = false;
	}
}

bool Player::get_fPlayerMove()
{
	return _fPlayerMove;
}
void Player::set_fPlayerMove(bool f)
{
	_fPlayerMove = f;
}

int Player::get_posInitX()
{
	return _posInit.x;
}
int Player::get_playerX()
{
	return _img->getX();
}
POINT Player::get_sizePlayer()
{
	return _sizePlayer;
}
void Player::set_distance_moved(int distance)
{
	_distance_moved = distance;
}
int Player::get_distance_moved()
{
	return _distance_moved;
}

void Player::moveJump()
{
	_fJump = true;
	_fIsGround = false;

	// 점프모션 고정
	_count = 0;
	_index = 0;
	_img->setFrameX(_index);

	_distance_jump = _img->getY() - 50;
}
void Player::moveRight()
{
	_count++;

	if (_count >= _SPEED_FRAME)
	{
		_count = 0;

		if (_index <= 0)
		{
			_index = 2;
		}
		else
		{
			_index--;
		}
	}
	_img->setFrameX(_index);

	// 움직인 거리
	_distance_moved += SPEED_PLAYER;
}
void Player::movePlayerRight()
{
	int x = _img->getX();
	int playerL = x;
	int playerR = playerL + _sizePlayer.x;
	_count++;

	if (playerR >= WINSIZEX + _posInit.x)
	{
		// 움직이지 않는다.
	}//if: 플레이어 right가 오른쪽 끝에 닿으면 
	else
	{
		// 움직인다.
		if (_count >= _SPEED_FRAME)
		{
			_count = 0;

			if (_index <= 0)
			{
				_index = 2;
			}
			else
			{
				_index--;

			}
		}
		_img->setFrameX(_index);

		// 움직인 거리
		x += SPEED_PLAYER;
		_img->setX(x);

	}//else: 플레이어 right가 오른쪽 끝에 닿지 않으면

}
void Player::moveLeft()
{
	_count++;

	if (_count >= _SPEED_FRAME + 5)
	{
		_count = 0;

		if (_index <= 1)
		{
			_index = 2;
		}
		else
		{
			_index--;
		}
	}
	_img->setFrameX(_index);

	// 움직인 거리
	_distance_moved -= SPEED_PLAYER;
}
void Player::movePlayerLeft()
{
	int x = _img->getX();
	int playerL = x;
	_count++;

	if (playerL <= 0)
	{
		// 움직이지 않는다.
	}//if: 플레이어 left가 왼쪽 끝에 닿으면
	else
	{
		if (_count >= _SPEED_FRAME + 5)
		{
			_count = 0;

			if (_index <= 1)
			{
				_index = 2;
			}
			else
			{
				_index--;
			}
		}
		_img->setFrameX(_index);

		// 움직인 거리
		x -= SPEED_PLAYER;
		_img->setX(x);

	}


}

Player::Player()
{
}
Player::~Player()
{
}

HRESULT Player::init(loadIndex stage)
{
	switch (stage)
	{
	case LOAD_STAGE1:
		_img = IMAGEMANAGER->addFrameImage("플레이어", "images/플레이어_리사이즈.bmp",
			_sizePlayer.x, _sizePlayer.y, 3, 1, true, COLOR_MAGENTA);
		break;
	default:
		break;
	}

	// 프레임 초기화
	_img->setFrameX(2);
	_img->setFrameY(0);
	// 위치 초기화
	_posInit.x = WINSIZEX * 0.15;
	_posInit.y = GROUND - _sizePlayer.y;
	_img->setX(_posInit.x);
	_img->setY(_posInit.y);
	// 프레임 인덱스 초기화
	_count = 0;
	_index = 2;	// 대기상태
	_maxFrame = 3;

	// 움직인 거리다.
	_distance_moved = 0;
	_fJump = false;
	_fIsGround = true;

	// 플레이어가 직접 움직일지 정하는 변수
	_fPlayerMove = false;
	return S_OK;
}

void Player::release()
{
	IMAGEMANAGER->deleteImage("플레이어");
	SAFE_DELETE(_img);
}

void Player::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_fJump == true)
		{
			if (_fIsGround == true)
			{
				moveJump();
			}//end of if: 발이 땅에 닿았다면
			else
			{
				stayMoved(POS_RIGHT);
			}
		}//end of if: 점프키 눌렀을 때
		else
		{
			if (_fIsGround == true)
			{
				moveRight();
			}
			else
			{
				stayMoved(POS_RIGHT);
			}
		}
	}// 오른쪽키 눌렀을 때
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_fJump == true)
		{
			if (_fIsGround == true)
			{
				moveJump();
			}//end of if: 발이 땅에 닿았다면
			else
			{
				stayMoved(POS_LEFT);
			}
		}//end of if: 점프키 눌렀을 때
		else
		{
			if (_fIsGround == true)
			{
				moveLeft();
			}
			else
			{
				stayMoved(POS_LEFT);
			}
		}
	}// 왼쪽키 눌렀을 때

	if (KEYMANAGER->isOnceKeyDown(VK_UP) && _fIsGround == true)
	{
		moveJump();
	}// 위쪽키 눌렀을 때


	// 중력을 적용한다.
	if (_fJump == true)
	{
		gravityReverse();
	}
	if (_fJump == false)
	{
		gravity();
	}
}
void Player::update(int indexMap)

{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)
		&& _fPlayerMove == false && indexMap > 0)
	{
		if (_fJump == true)
		{
			if (_fIsGround == true)
			{
				moveJump();
			}//end of if: 발이 땅에 닿았다면
			else
			{
				stayMoved(POS_RIGHT);
			}
		}//end of if: 점프키 눌렀을 때
		else
		{
			if (_fIsGround == true)
			{
				moveRight();
			}
			else
			{
				stayMoved(POS_RIGHT);
			}
		}
	}// 오른쪽키 눌렀을 때
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _fPlayerMove == true)
	{
		if (_fJump == true)
		{
			if (_fIsGround == true)
			{
				moveJump();
			}//end of if: 발이 땅에 닿았다면
			else
			{
				stayMoved(POS_RIGHT);
			}
		}//if: 점프키 눌렀을 때
		else
		{
			if (_fIsGround == true)
			{
				movePlayerRight();
			}
			else
			{
				stayMoved(POS_RIGHT);
			}
		}//else: 점프키 안눌렀을 때
	}//if: 플레이어가 오른쪽으로 직접 움직일 때

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)
		&& _fPlayerMove == false && indexMap <= 1)
	{
		if (_fJump == true)
		{
			if (_fIsGround == true)
			{
				moveJump();
			}//end of if: 발이 땅에 닿았다면
			else
			{
				stayMoved(POS_LEFT);
			}
		}//end of if: 점프키 눌렀을 때
		else
		{
			if (_fIsGround == true)
			{
				moveLeft();
			}
			else
			{
				stayMoved(POS_LEFT);
			}
		}
	}// 왼쪽키 눌렀을 때
	else if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _fPlayerMove == true)
	{
		if (_fJump == true)
		{
			if (_fIsGround == true)
			{
				moveJump();
			}//end of if: 발이 땅에 닿았다면
			else
			{
				stayMoved(POS_LEFT);
			}
		}//end of if: 점프키 눌렀을 때
		else
		{
			if (_fIsGround == true)
			{
				movePlayerLeft();
			}
			else
			{
				stayMoved(POS_LEFT);
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_UP) && _fIsGround == true)
	{
		moveJump();
	}// 위쪽키 눌렀을 때

	// 맵을 멈출지 말지 정한다.
	// 플레이어가 직접 움직일지 말지 정한다.
	if (indexMap < 1 || MAX_LOOP_MAP < indexMap)
	{
		_fPlayerMove = true;
	}//if: indexMap이 1보다 작거나, 1보다 클 경우
	else
	{
		_fPlayerMove = false;
	}

	// 중력을 적용한다.
	if (_fJump == true)
	{
		gravityReverse();
	}
	if (_fJump == false)
	{
		gravity();
	}
}

void Player::render()
{
	IMAGEMANAGER->frameRender("플레이어", getMemDC(), _img->getX(), _img->getY(),
		_img->getFrameX(), _img->getFrameY());
}
