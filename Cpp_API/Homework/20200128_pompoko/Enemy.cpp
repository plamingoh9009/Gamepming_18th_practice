#include "stdafx.h"
#include "Enemy.h"


void Enemy::move_right()
{
	_moveCounter++;
	if (_moveCounter >= _moveDelay)
	{
		_rect.left += 3;
		_rect.right += 3;
		_moveCounter = 0;
		_moveDelay = RND->getFromIntTo(2, 6);
	}
}
void Enemy::move_left()
{
	_moveCounter++;
	if (_moveCounter >= _moveDelay)
	{
		_rect.left -= 3;
		_rect.right -= 3;
		_moveCounter = 0;
		_moveDelay = RND->getFromIntTo(2, 6);
	}
}

Enemy::Enemy()
{
}
Enemy::~Enemy()
{
}
HRESULT Enemy::init()
{
	_width = 24;
	_height = 24;
	_moveCounter = 0;
	_moveDelay = 3;
	_fLeft = false;
	// �� �ʱ�ȭ
	_wall = RectMake(625, 129, 18, 344);
	return S_OK;
}
void Enemy::release()
{
}
void Enemy::update()
{
	// ���� ������ �÷��� �ٲ�.
	if (IntersectRect(&RECT(), &_rect, &_wall))
	{
		_fLeft = true;
	}
	else if (_rect.left <= 0)
	{
		_fLeft = false;
	}

	// �÷��׿� ���� �����δ�.
	if (_fLeft == true)
	{
		move_left();
	}
	else
	{
		move_right();
	}
}

void Enemy::render()
{
}
