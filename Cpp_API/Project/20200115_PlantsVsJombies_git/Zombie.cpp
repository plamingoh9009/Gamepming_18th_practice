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
// **			좀비가 자동으로 할 일				 **
// ================================================
void Zombie::walk_toLeft()
{
	_walkCount++;
	if (_walkCount >= _walkDelay)
	{
		// 좀비를 렌더할 때 쓰는 정보 업데이트
		_rect.left -= _walkSpeed;
		_rect.right -= _walkSpeed;
		// 좀비 타격점 정보 업데이트
		_zombieHitPoint.left -= _walkSpeed;
		_zombieHitPoint.right -= _walkSpeed;
		// 좀비 사정거리 정보 업데이트
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
// **		좀비 위치 초기화는 여기서				 **
// ================================================
void Zombie::init_zombiePosition(vector<RECT> lines)
{
	// 좀비의 오른쪽 끝이 -> 각 라인의 오른쪽 끝 중에 하나여야 한다.
	int range = (int)(lines.size());
	int idx = RND->getInt(range);
	// 렉트 셋팅
	_rect.right = lines[idx].right;
	_rect.bottom = lines[idx].bottom;
	_rect.left = _rect.right - _img->getFrameWidth();
	_rect.top = _rect.bottom - _img->getFrameHeight();
	// 좀비 피격지점 셋팅
	_zombieHitPoint = lines[idx];
	// 좀비 타격지점 셋팅
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
	// 프레임 돌릴 정보
	_currentFrameX = 0;
	_currentFrameY = 0;
	_frameDelay = 8;
	_frameCount = 0;
	// 좀비가 걷기위한 정보
	_walkDelay = 5;
	_walkCount = 0;
	_walkSpeed = 1;
	// 좀비가 싸우기 위한 정보
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
	}//if: 식물이 근처에 있다면
	else 
	{
		walk_toLeft();
	}//else: 식물이 근처에 없다면 그저 걷는다.
	check_deadZombie();
	run_frame();
}
void Zombie::render()
{
	IMAGEMANAGER->frameRender("Zombie", getMemDC(),
		_rect.left, _rect.top, _currentFrameX, _currentFrameY);
}
