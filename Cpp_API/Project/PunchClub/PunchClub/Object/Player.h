#pragma once
#include "Unit.h"
#include "Base/SingletonBase.h"
#include "UI/uiEnum.h"
#include "UI/Icons/Icon.h"
#include "UI/Hint.h"
class Player : public Unit, public SingletonBase<Player>
{
private:
	typedef map<SLOT::ITEM, int> ItemList;
private:
	Image * _player_idle[4];
	RECT _player_rc;
	POINT _player_center;
	// �̹��� �ٲ� �� ���� ����
	bool _fIdle = true;
	int _idleIndex = 0;
	
	PlayerStat _myStat;		// �÷��̾� �ɷ�ġ
	ItemList _inven;		// �÷��̾��� �κ��丮
	MAPICON::TYPE _location = MAPICON::ICN_HOME;	// �÷��̾��� ù ��ġ�� ���̴�.
	Icon * _hunger;			// ����� �� ���� ������
	// �÷��̾��� Ÿ�̸�
	double _time = 0;
	// �÷��̾ ������ ���� �����ϴ� ������.
	PLAYER_ACTION _actionType = ACTION_EMPTY;
	bool _fAction = false;
	bool _fActionInit = false;
	bool _fClickReady = false;
	bool _fTired = false;
protected:
	void update_idle_img();
	void change_idle_img();
	void follow_icon_player();
	void move_player();
	void init_player();
	void draw_player();
	void update_player();
	void delete_player();
	double limit_stat(double stat, bool fZeroSet = false);
	bool is_tired() { return _fTired; }
protected:
	void action();
	void use(SLOT::ITEM itemType);
	void add_stat(double health, double food, double mood, double energy);
	inline void Tired()
	{
		_fAction = false;
		_fTired = true;
		_hunger->Visible();
	}
public:
	inline void action_start() { _fAction = true; }
	inline void action_pause() { _fAction = false; }
	inline void action_init() { _fActionInit = true; }
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
	PlayerStat get_stat() { return _myStat; }
	MAPICON::TYPE get_playerLocation() { return _location; }
	POINT get_playerCenter() { return _player_center; }
	void set_playerCenter(POINT center);
	void set_playerLocation(MAPICON::TYPE type) { _location = type; }
	void set_playerAction(PLAYER_ACTION type) { _actionType = type; }
	int how_many_items(SLOT::ITEM itemType);
	bool is_stop_action() { return !_fAction; }
};
#define PLAYER	Player::get_singleton()