#pragma once
#include "Unit.h"
#include "Base/SingletonBase.h"
#include "UI/uiEnum.h"
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
	PlayerStat _stat;
	// 플레이어의 첫 위치는 집이다.
	MAPICON::TYPE _location = MAPICON::ICN_HOME;
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
	void add_money(int money) { _stat.money += money; }
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
	PlayerStat get_stat() { return _stat; }
	MAPICON::TYPE get_playerLocation() { return _location; }
	void set_playerLocation(MAPICON::TYPE type) { _location = type; }
};
#define PLAYER	Player::get_singleton()