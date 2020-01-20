#include "stdafx.h"
#include "Zombie.h"

void Zombie::init_zombieAttackRange(RECT hitPoint)
{
	int width = 10;
	_zombieAttackRange.left = hitPoint.left - width;
	_zombieAttackRange.right = hitPoint.left;
	_zombieAttackRange.top = hitPoint.top;
	_zombieAttackRange.bottom = hitPoint.bottom;
}
void Zombie::check_deadZombie()
{
	if (_hp < 1)
	{
		_fDeadZombie = true;
	}
}

void Zombie::attack_plant()
{
	_attackCount++;
	if (_attackCount >= _attackDelay)
	{
		_fZombieAttack = true;
		_lostPlantHp += _damage;
		_attackCount = 0;
	}
}

void Zombie::init_lostPlantHp()
{
	_fZombieAttack = false;
	_lostPlantHp = 0;
}
bool Zombie::is_zombieAttack()
{
	return _fZombieAttack;
}

// ================================================
// **			���� �ڵ����� �� ��				 **
// ================================================
void Zombie::walk_toLeft()
{
	_walkCount++;
	if (_walkCount >= _walkDelay)
	{
		// ���� ������ �� ���� ���� ������Ʈ
		_rect.left -= _walkSpeed;
		_rect.right -= _walkSpeed;
		// ���� Ÿ���� ���� ������Ʈ
		_zombieHitPoint.left -= _walkSpeed;
		_zombieHitPoint.right -= _walkSpeed;
		// ���� �����Ÿ� ���� ������Ʈ
		_zombieAttackRange.left -= _walkSpeed;
		_zombieAttackRange.right -= _walkSpeed;
		_walkCount = 0;
	}
}
void Zombie::run_frame()
{
	_frameCount++;
	if (_frameCount >= _frameDelay)
	{
		_currentFrameX++;
		if (_currentFrameX >= _maxFrameX)
		{
			_currentFrameX = 0;
		}
		_frameCount = 0;
	}
}

void Zombie::show_zombieRect()
{
	FrameRect(getMemDC(), &_rect,
		CreateSolidBrush(RGB(255, 0, 0)));
}
void Zombie::show_zombieHitPoint()
{
	FrameRect(getMemDC(), &_zombieHitPoint,
		CreateSolidBrush(RGB(255, 0, 0)));
}
void Zombie::show_zombieAttackRange()
{
	FrameRect(getMemDC(), &_zombieAttackRange,
		CreateSolidBrush(RGB(255, 0, 0)));
}
// ================================================
// **		���� ��ġ �ʱ�ȭ�� ���⼭				 **
// ================================================
void Zombie::init_zombiePosition(vector<RECT> lines)
{
	// ������ ������ ���� -> �� ������ ������ �� �߿� �ϳ����� �Ѵ�.
	int range = (int)(lines.size());
	int idx = RND->getInt(range);
	// ��Ʈ ����
	_rect.right = lines[idx].right;
	_rect.bottom = lines[idx].bottom;
	_rect.left = _rect.right - _img->getFrameWidth();
	_rect.top = _rect.bottom - _img->getFrameHeight();
	// ���� �ǰ����� ����
	_zombieHitPoint = lines[idx];
	// ���� Ÿ������ ����
	init_zombieAttackRange(_zombieHitPoint);
}

void Zombie::hit_zombie(int lostHp)
{
	_hp -= lostHp;
}

Zombie::Zombie()
{
}
Zombie::~Zombie()
{
}
HRESULT Zombie::init()
{
	_img = IMAGEMANAGER->addFrameImage("Zombie",
		"images/zombies/Zombie_Walk.bmp", 1080, 110,
		12, 1, true, COLOR_MAGENTA);
	_width = 1080;
	_height = 110;
	_maxFrameX = 12;
	_maxFrameY = 1;
	// ������ ���� ����
	_currentFrameX = 0;
	_currentFrameY = 0;
	_frameDelay = 8;
	_frameCount = 0;
	// ���� �ȱ����� ����
	_walkDelay = 5;
	_walkCount = 0;
	_walkSpeed = 1;
	// ���� �ο�� ���� ����
	_fPlantInRange = false;
	_fDeadZombie = false;
	_fZombieAttack = false;
	_hp = 10;
	_damage = 1;
	_lostPlantHp = 0;
	_attackCount = 0;
	_attackDelay = 100;
	return S_OK;
}
void Zombie::release()
{
	_img = nullptr;
}
void Zombie::update()
{
	if (_fPlantInRange == true) 
	{
		attack_plant();
	}//if: �Ĺ��� ��ó�� �ִٸ�
	else 
	{
		walk_toLeft();
	}//else: �Ĺ��� ��ó�� ���ٸ� ���� �ȴ´�.
	check_deadZombie();
	run_frame();
}
void Zombie::render()
{
	IMAGEMANAGER->frameRender("Zombie", getMemDC(),
		_rect.left, _rect.top, _currentFrameX, _currentFrameY);
}
