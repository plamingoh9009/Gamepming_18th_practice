#include "stdafx.h"
#include "Player.h"
// ========================================
// ***		Idle 이미지 업데이트			***
// ========================================
void Player::update_idle_img()
{
	_player_idle[_idleIndex]->frameUpdate(false);
	if (_player_idle[_idleIndex]->is_end_thirdSection())
	{
		change_idle_img();	// 이미지 변경하고

		// 위치 다시 잡아주고
		_player_rc = RectMakeCenter(_player_center.x, _player_center.y,
			_player_idle[_idleIndex]->get_frameWidth(),
			_player_idle[_idleIndex]->get_frameHeight());
	}
}
void Player::change_idle_img()
{
	// 확률은 가만히 1, 고개돌리기 왼쪽 2 오른쪽 2, 근육자랑 2
	int result;
	result = RAND->get_fromIntTo(1, 100);
	int max;
	max = 7;
	if (0 < result && result <= (100 * 1 / max)) { _idleIndex = 0; }
	else if ((100 * 1 / max) < result && result <= (100 * 3 / max)) { _idleIndex = 1; }
	else if ((100 * 3 / max) < result && result <= (100 * 5 / max)) { _idleIndex = 2; }
	else { _idleIndex = 3; }
}
void Player::follow_icon_player()
{
	POINT center;
	center.x = (LONG)(_player_rc.right + _hunger->get_width());
	center.y = (LONG)(_player_rc.top - _hunger->get_height());
	_hunger->set_center(center);
	_hunger->update();
}
void Player::move_player()
{
	_player_center.x = m_ptMouse.x;
	_player_center.y = m_ptMouse.y;
	_player_center.y -= (LONG)(_player_idle[_idleIndex]->get_frameHeight() * 0.5);
	_player_rc = RectMakeCenter(
		(int)(_player_center.x),
		(int)(_player_center.y),
		_player_idle[_idleIndex]->get_frameWidth(),
		_player_idle[_idleIndex]->get_frameHeight());
}
void Player::init_player()
{
	string path;
	path = _imgPath + "default_idle_01.bmp";
	_player_idle[0] = new Image;
	_player_idle[0]->init(path.c_str(),
		(int)(76 * GAME_MULTIPLE), (int)(76 * GAME_MULTIPLE), 2, 1);
	_player_idle[0]->set_frameSection(3, 0, 1, 0.1f, 0, 1, 0.1f, 0, 1, 0.5f);
	path = _imgPath + "default_idle_02.bmp";
	_player_idle[1] = new Image;
	_player_idle[1]->init(path.c_str(),
		(int)(114 * GAME_MULTIPLE), (int)(76 * GAME_MULTIPLE), 3, 1);
	_player_idle[1]->set_frameSection(3, 0, 0, 1.0f, 1, 2, 0.7f, 2, 2, 1.0f);
	path = _imgPath + "default_idle_03.bmp";
	_player_idle[2] = new Image;
	_player_idle[2]->init(path.c_str(),
		(int)(114 * GAME_MULTIPLE), (int)(76 * GAME_MULTIPLE), 3, 1);
	_player_idle[2]->set_frameSection(3, 0, 0, 1.0f, 1, 2, 0.7f, 2, 2, 1.0f);
	path = _imgPath + "default_idle_04.bmp";
	_player_idle[3] = new Image;
	_player_idle[3]->init(path.c_str(),
		(int)(250 * GAME_MULTIPLE), (int)(76 * GAME_MULTIPLE), 5, 1);
	_player_idle[3]->set_frameSection(3, 0, 0, 1.0f, 1, 4, 0.5f, 4, 4, 1.0f);
	// 초기 위치 잡기
	_player_center.x = (LONG)(WIN_HALF_W - WIN_HALF_W * 0.4);
	_player_center.y = (LONG)(WIN_HALF_H +
		_player_idle[_idleIndex]->get_height() * 0.5);
	_player_rc = RectMakeCenter(_player_center.x, _player_center.y,
		_player_idle[_idleIndex]->get_frameWidth(),
		_player_idle[_idleIndex]->get_frameHeight());
}
void Player::draw_player()
{
	_player_idle[_idleIndex]->frameRender(get_memDC(),
		_player_rc.left, _player_rc.top);
}
void Player::update_player()
{
	if (_fIdle) { update_idle_img(); }
	if (_fClick && _fObjMove)
	{
		if (m_ptMouse.y < WIN_HALF_H) {}
		else { move_player(); }
	}
}
void Player::delete_player()
{
	for (int i = 0; i < 4; i++)
	{
		_player_idle[i]->release();
		_player_idle[i] = nullptr;
	}
}
double Player::limit_stat(double stat, bool fZeroSet)
{
	if (stat < 0.0)
	{
		return 0.0;
	}
	else if (stat > 1000.0)
	{
		if (fZeroSet)
		{
			return 0.0;
		}
		else
		{
			return 1000.0;
		}
	}
	return stat;
}
void Player::hide_player()
{
	switch (_actionType ^ MYOBJECT::RUN_PLAYER)
	{
	case MYOBJECT::SOFA_PLAYER:
	case MYOBJECT::TV_PLAYER:
		// Training
	case MYOBJECT::TRM_PLAYER:
	case MYOBJECT::BBL_PLAYER:
	case MYOBJECT::TIR_PLAYER:
	case MYOBJECT::BP_PLAYER:
	case MYOBJECT::PB_PLAYER:
	case MYOBJECT::YCN_PLAYER:
		_fVisible = false;
		break;
	}
}
// ========================================
// ***		스탯 구슬 함수					***
// ========================================
void Player::make_bead(BEAD::TYPE type, bool isReverse)
{
	Bead * bead = new Bead(type, isReverse);
	bead->init();
	_beads.push_back(bead);
}
// ========================================
// ***			플레이어 행동				***
// ========================================
void Player::action()
{
	if (_actionType != MYOBJECT::RUN_EMPTY)
	{
		if (_fAction)
		{
			hide_player();
			// 일정 시간을 주고, 행동을 한다.
			_time += TIMEMANAGER->get_elapsedTime();
			if (1.0f <= _time)
			{
				switch (_actionType ^ MYOBJECT::RUN_PLAYER)
				{
				case MYOBJECT::WORK_PLAYER:
					Tired();
					_myStat.workGauge += 80;
					// 일하면 모든 상태가 전부 떨어지지만 스탯이 오른다.
					add_stat(10, -20, -10, -25);
					add_stat_forFight(PLAYER_SET::STR | PLAYER_SET::AGL | PLAYER_SET::STM);
					break;
				case MYOBJECT::SOFA_PLAYER:
					Tired();
					add_stat(10, -30, 2, 40);
					break;
				case MYOBJECT::TV_PLAYER:
					Tired();
					add_stat(10, -10, 30, 10);
					break;
					// Trainig
				case MYOBJECT::TRM_PLAYER:
					Tired();
					add_stat(PLAYER_SET::AS_FIGHT);
					add_stat_forFight(PLAYER_SET::STM);
					break;
				case MYOBJECT::BBL_PLAYER:
					Tired();
					add_stat(PLAYER_SET::AS_FIGHT);
					add_stat_forFight(PLAYER_SET::STR | PLAYER_SET::STM);
					break;
				case MYOBJECT::TIR_PLAYER:
					Tired();
					add_stat(PLAYER_SET::AS_FIGHT);
					add_stat_forFight(PLAYER_SET::STR | PLAYER_SET::AGL | PLAYER_SET::STM);
					break;
				case MYOBJECT::BP_PLAYER:
					Tired();
					add_stat(PLAYER_SET::AS_FIGHT);
					add_stat_forFight(PLAYER_SET::STR);
					break;
				case MYOBJECT::PB_PLAYER:
					Tired();
					add_stat(PLAYER_SET::AS_FIGHT);
					add_stat_forFight(PLAYER_SET::STR | PLAYER_SET::AGL | PLAYER_SET::STM);
					break;
				case MYOBJECT::YCN_PLAYER:
					Tired();
					add_stat(PLAYER_SET::AS_FIGHT);
					add_stat_forFight(PLAYER_SET::AGL | PLAYER_SET::STM);
					break;
				}
				_time = 0;
				_fClickReady = true;
			}
			// 여기서 액션을 초기화한다.
			if (_fActionInit)
			{
				switch (_actionType)
				{
				case MYOBJECT::WORK_PLAYER:
					_myStat.workGauge = limit_stat(_myStat.workGauge, true);
					break;
				default:
					_myStat.health = limit_stat(_myStat.health);
					_myStat.food = limit_stat(_myStat.food);
					_myStat.mood = limit_stat(_myStat.mood);
					_myStat.energy = limit_stat(_myStat.energy);
					break;
				}
				_fActionInit = false;
			}
		}//if: fAction이 True 라면 플레이어가 행동한다.
	}//if: actionType이 정의되어 있을 때
	if (_fAction == false)
	{
		_actionType = _actionType & MYOBJECT::RUN_PLAYER;
		_fVisible = true;
		_fObjClickLock = false;
	}//else: 액션을 멈추면 플레이어를 볼 수 있다.
}
//==========================================
//##			아이템 사용				  ##
//==========================================
void Player::use(SLOT::ITEM type)
{
	switch (type)
	{
	case SLOT::ITM_MEAT:
		add_stat(100, 400, 10, 0);
		break;
	case SLOT::ITM_SODA:
		add_stat(0, 90, 10, 0);
		break;
	case SLOT::ITM_PIZZA_BOX:
		add_stat(100, 170, 10, 0);
		break;
	}
}

void Player::add_stat(double health, double food, double mood, double energy)
{
	_myStat.health += health;
	_myStat.food += food;
	_myStat.mood += mood;
	_myStat.energy += energy;
	// Make status beads
	if (health < 0) { make_bead(BEAD::BD_HEALTH, true); }
	else { make_bead(BEAD::BD_HEALTH); }
	if (health < 0) { make_bead(BEAD::BD_FOOD, true); }
	else { make_bead(BEAD::BD_HEALTH); }
	if (health < 0) { make_bead(BEAD::BD_MOOD, true); }
	else { make_bead(BEAD::BD_HEALTH); }
	if (health < 0) { make_bead(BEAD::BD_ENERGY, true); }
	else { make_bead(BEAD::BD_HEALTH); }
}
void Player::add_stat(int effectsStat)
{
	if (effectsStat & PLAYER_SET::AS_FIGHT)
	{
		add_stat(10, -22.5, -5, -33.75);
	}
}
void Player::add_stat_forFight(int effectsStat, bool isLostExp)
{
	int str_percent, agl_percent, stm_percent;
	int str = (int)(_myStat.str / 1000 - 1);
	int agl = (int)(_myStat.agl / 1000 - 1);
	int stm = (int)(_myStat.stm / 1000 - 1);
	int correction = 30;
	// Make percentage
	int percent = 75;
	str_percent = RAND->get_fromIntTo(1, 100);
	agl_percent = RAND->get_fromIntTo(1, 100);
	stm_percent = RAND->get_fromIntTo(1, 100);
	if (isLostExp)
	{
		// Empty yet..
	}//if: subtraction
	else
	{
		if (str_percent <= percent &&
			effectsStat & PLAYER_SET::STR)
		{
			_myStat.str += (STAT_EXP - str * correction);
		}
		if (agl_percent <= percent &&
			effectsStat & PLAYER_SET::AGL)
		{
			_myStat.agl += (STAT_EXP - str * correction);
		}
		if (stm_percent <= percent &&
			effectsStat & PLAYER_SET::STM)
		{
			_myStat.stm += (STAT_EXP - str * correction);
		}
	}//else: add
}

void Player::Tired()
{
	if (_myStat.food < 120 || _myStat.energy < 120)
	{
		action_pause();
		_fTired = true;
		_fClick = false;
		_hunger->Visible();
	}
}

void Player::buy_item(SLOT::ITEM itemType)
{
	int price = 0;
	switch (itemType)
	{
	case SLOT::ITM_MEAT:
		price = PRICE_MEAT;
		break;
	case SLOT::ITM_PIZZA_BOX:
		price = PRICE_PIZZA_BOX;
		break;
	case SLOT::ITM_SODA:
		price = PRICE_SODA;
		break;
	}//switch: Define item's price;
	auto iter = _inven.find(itemType);
	if (_myStat.money >= price)
	{
		if (iter == _inven.end())
		{
			_inven.insert(make_pair(itemType, 1));
			_myStat.money -= price;
		}
		else
		{
			if (iter->second < 7)
			{
				iter->second++;
				_myStat.money -= price;
			}
		}
	}//if: Enough money, could buy goods
}
void Player::use_item(SLOT::ITEM itemType)
{
	auto iter = _inven.find(itemType);
	if (iter != _inven.end())
	{
		if (iter->second > 0)
		{
			iter->second--;
			use(itemType);
		}
	}
}

HRESULT Player::init()
{
	set_imgPath("Object/Player/");
	init_player();
	// 배고플 때 쓰는 아이콘
	_hunger = new Icon(ICON::ICN_HUNGER);
	_hunger->init();
	return S_OK;
}
void Player::release()
{
	delete_player();
	Release(_hunger);
}
void Player::update()
{
	update_player();
	follow_icon_player();
	action();
}
void Player::render()
{
	if (_fVisible)
	{
		Draw(_hunger);
		draw_player();
	}
}
Player::Player()
{
	// 처음에 피자 2판 주고 시작
	buy_item(SLOT::ITM_PIZZA_BOX);
	buy_item(SLOT::ITM_PIZZA_BOX);
}
Player::~Player()
{
}

void Player::set_playerCenter(POINT center)
{
	_player_rc = RectMakeCenter(center.x, center.y,
		_player_idle[_idleIndex]->get_frameWidth(),
		_player_idle[_idleIndex]->get_frameHeight());
	_player_center = center;
}
int Player::how_many_items(SLOT::ITEM itemType)
{
	auto iter = _inven.find(itemType);
	if (iter != _inven.end())
	{
		return iter->second;
	}
	return 0;
}
