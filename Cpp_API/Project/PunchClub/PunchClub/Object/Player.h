#pragma once
#include "Unit.h"
#include "Base/SingletonBase.h"
#include "UI/uiEnum.h"
#include "UI/Icons/Icon.h"
#include "UI/Hint.h"
#include "UI/Bead.h"
class Player : public Unit, public SingletonBase<Player>
{
private:
	typedef map<SLOT::ITEM, int> ItemList;	// Item list => Inventory
	typedef vector<Bead *> Beads;
	const double STAT_EXP = 100;	// Gain exp when player training
private:
	Image * _player_idle[4];
	Image * _player_img;
	Image * _player_img_shdw;
	RECT _player_rc;
	POINT _player_center;
	// 이미지 바꿀 때 쓰는 변수
	bool _fIdle = true;
	int _idleIndex = 0;
	
	PlayerStat _myStat;		// 플레이어 능력치
	ItemList _inven;		// 플레이어의 인벤토리
	Beads _beads;			// 플레이어의 스탯 구슬
	MAPICON::TYPE _location = MAPICON::ICN_HOME;	// 플레이어의 첫 위치는 집이다.
	Icon * _hunger;			// 배고플 때 쓰는 아이콘
	// 플레이어의 타이머
	double _time = 0;
	// 플레이어가 무엇을 할지 결정하는 변수다.
	int _actionType = MYOBJECT::RUN_EMPTY;
	bool _fAction = false;
	bool _fActionInit = false;
	bool _fClickReady = false;
	bool _fTired = false;
	bool _fVisible = true;
protected:
	void update_idle_img();
	void change_idle_img();
	void follow_icon_player();
	// Player functions
	void init_player();
	void draw_player();
	void update_player();
	void delete_player();
	void move_player();
	void hide_player();
	// Bead
	void make_bead(BEAD::TYPE type, int plusCnt, bool isReverse = false);
	
	double limit_stat(double stat, bool fZeroSet = false);
protected:
	void action();
	void use(SLOT::ITEM itemType);
	void add_stat(double health, double food, double mood, double energy);
	void add_stat(int effectsStat);
	void add_stat_forFight(int effectsStat, bool isLostExp = false);
public:
	inline void action_start() { _fAction = true; }
	inline void action_pause() { _fAction = false; }
	inline void action_init() { _fActionInit = true; }
	void Tired();
public:
	inline void add_money(int money) { _myStat.money += money; }
	void buy_item(SLOT::ITEM itemType);
	void use_item(SLOT::ITEM itemType);
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);
public:
	Player();
	~Player();
public:
	inline PlayerStat get_stat() { return _myStat; }
	inline MAPICON::TYPE get_playerLocation() { return _location; }
	inline POINT get_playerCenter() { return _player_center; }
	inline int get_playerHeight() { return (int)(_player_rc.right - _player_rc.left); }
	int get_actionType() { return _actionType; }
	Beads get_beads() { return _beads; }
	void set_playerCenter(POINT center);
	void set_playerLocation(MAPICON::TYPE type) { _location = type; }
	void set_playerAction(int type) { _actionType = type; }
	int how_many_items(SLOT::ITEM itemType);
	inline bool is_running_action() { return _fAction; }
	inline bool is_tired() { return _fTired; }
	inline bool is_click_ready() { return _fClickReady; }
};
#define PLAYER	Player::get_singleton()