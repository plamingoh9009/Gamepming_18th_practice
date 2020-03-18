#pragma once
#include "Unit.h"
#include "Base/SingletonBase.h"
#define MAX_HUD	100;
class Player: public Unit, public SingletonBase<Player>
{
private:
	Image * _player_idle[4];
	RECT _player_rc;
	POINT _player_center;
	// 이미지 바꿀 때 쓰는 변수
	bool _fIdle = true;
	int _idleIndex = 0;
	// 플레이어 능력치
	float _health = MAX_HUD;
	float _food = MAX_HUD;
	float _energy = MAX_HUD;
	float _mood = MAX_HUD;
protected:
	void update_idle_img();
	void change_idle_img();
protected:
	void move_player();
	void init_player();
	void draw_player();
	void update_player();
	void delete_player();
public:
	void sleep_toSofa();
	void watch_tv();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);
public:
	Player();
	~Player();
public:
	void set_playerCenter(POINT center);
};
#define PLAYER	Player::get_singleton()