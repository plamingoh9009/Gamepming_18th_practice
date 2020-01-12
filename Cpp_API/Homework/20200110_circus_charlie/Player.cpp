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
	}//end of if: �÷��̾ ���� ���� �ʾҴٸ� +
	else
	{
		_fIsGround = true;
	}// �÷��̾ ���� ��Ҵٸ�

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

	// ������� ����
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

	// ������ �Ÿ�
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
		// �������� �ʴ´�.
	}//if: �÷��̾� right�� ������ ���� ������ 
	else
	{
		// �����δ�.
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

		// ������ �Ÿ�
		x += SPEED_PLAYER;
		_img->setX(x);

	}//else: �÷��̾� right�� ������ ���� ���� ������

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

	// ������ �Ÿ�
	_distance_moved -= SPEED_PLAYER;
}
void Player::movePlayerLeft()
{
	int x = _img->getX();
	int playerL = x;
	_count++;

	if (playerL <= 0)
	{
		// �������� �ʴ´�.
	}//if: �÷��̾� left�� ���� ���� ������
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

		// ������ �Ÿ�
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
		_img = IMAGEMANAGER->addFrameImage("�÷��̾�", "images/�÷��̾�_��������.bmp",
			_sizePlayer.x, _sizePlayer.y, 3, 1, true, COLOR_MAGENTA);
		break;
	default:
		break;
	}

	// ������ �ʱ�ȭ
	_img->setFrameX(2);
	_img->setFrameY(0);
	// ��ġ �ʱ�ȭ
	_posInit.x = WINSIZEX * 0.15;
	_posInit.y = GROUND - _sizePlayer.y;
	_img->setX(_posInit.x);
	_img->setY(_posInit.y);
	// ������ �ε��� �ʱ�ȭ
	_count = 0;
	_index = 2;	// ������
	_maxFrame = 3;

	// ������ �Ÿ���.
	_distance_moved = 0;
	_fJump = false;
	_fIsGround = true;

	// �÷��̾ ���� �������� ���ϴ� ����
	_fPlayerMove = false;
	return S_OK;
}

void Player::release()
{
	IMAGEMANAGER->deleteImage("�÷��̾�");
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
			}//end of if: ���� ���� ��Ҵٸ�
			else
			{
				stayMoved(POS_RIGHT);
			}
		}//end of if: ����Ű ������ ��
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
	}// ������Ű ������ ��
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_fJump == true)
		{
			if (_fIsGround == true)
			{
				moveJump();
			}//end of if: ���� ���� ��Ҵٸ�
			else
			{
				stayMoved(POS_LEFT);
			}
		}//end of if: ����Ű ������ ��
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
	}// ����Ű ������ ��

	if (KEYMANAGER->isOnceKeyDown(VK_UP) && _fIsGround == true)
	{
		moveJump();
	}// ����Ű ������ ��


	// �߷��� �����Ѵ�.
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
			}//end of if: ���� ���� ��Ҵٸ�
			else
			{
				stayMoved(POS_RIGHT);
			}
		}//end of if: ����Ű ������ ��
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
	}// ������Ű ������ ��
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _fPlayerMove == true)
	{
		if (_fJump == true)
		{
			if (_fIsGround == true)
			{
				moveJump();
			}//end of if: ���� ���� ��Ҵٸ�
			else
			{
				stayMoved(POS_RIGHT);
			}
		}//if: ����Ű ������ ��
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
		}//else: ����Ű �ȴ����� ��
	}//if: �÷��̾ ���������� ���� ������ ��

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)
		&& _fPlayerMove == false && indexMap <= 1)
	{
		if (_fJump == true)
		{
			if (_fIsGround == true)
			{
				moveJump();
			}//end of if: ���� ���� ��Ҵٸ�
			else
			{
				stayMoved(POS_LEFT);
			}
		}//end of if: ����Ű ������ ��
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
	}// ����Ű ������ ��
	else if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _fPlayerMove == true)
	{
		if (_fJump == true)
		{
			if (_fIsGround == true)
			{
				moveJump();
			}//end of if: ���� ���� ��Ҵٸ�
			else
			{
				stayMoved(POS_LEFT);
			}
		}//end of if: ����Ű ������ ��
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
	}// ����Ű ������ ��

	// ���� ������ ���� ���Ѵ�.
	// �÷��̾ ���� �������� ���� ���Ѵ�.
	if (indexMap < 1 || MAX_LOOP_MAP < indexMap)
	{
		_fPlayerMove = true;
	}//if: indexMap�� 1���� �۰ų�, 1���� Ŭ ���
	else
	{
		_fPlayerMove = false;
	}

	// �߷��� �����Ѵ�.
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
	IMAGEMANAGER->frameRender("�÷��̾�", getMemDC(), _img->getX(), _img->getY(),
		_img->getFrameX(), _img->getFrameY());
}
