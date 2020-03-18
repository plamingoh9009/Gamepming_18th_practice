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
		if(m_ptMouse.y < WIN_HALF_H) {}
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
// ========================================
// ***		플레이어 상태 업데이트			***
// ========================================
void Player::sleep_toSofa()
{
	_health += 0.5f;
	_food -= 3.0f;
	_energy += 1.0f;
	_mood += 0.2f;
}
void Player::watch_tv()
{
	_health -= 0.2f;
	_food -= 1.0f;
	_energy += 1.0f;
	_mood += 3.0f;
}

HRESULT Player::init()
{
	set_imgPath("Object/Player/");
	init_player();
	return S_OK;
}
void Player::release()
{
	delete_player();
}
void Player::update()
{
	update_player();
}
void Player::render()
{
	draw_player();
}
Player::Player()
{
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
