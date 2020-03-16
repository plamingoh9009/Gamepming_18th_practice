#pragma once
#include "Base/GameNode.h"
#include "Base/SingletonBase.h"
// UI
#include "Cursor.h"
#include "Icons/Icon.h"
#include "HudBack.h"
#include "Button.h"
// 클릭했을 때
#include "Window.h"
// 싸울 때
#include "Gauge.h"
enum UI_TYPE
{
	UI_NONE,
	UI_LEAGUE_WAIT,
	UI_LEAGUE_FIGHT
};
class InGameUI: public GameNode, public SingletonBase<InGameUI>
{
private:
	// 오브젝트에 값을 넣기 위해서 필요하다
	Object * _obj;
private:
	// Cursor
	Cursor * _cursor = nullptr;
	// Icons
	Icon * _icn_hud_map = nullptr;
	Icon * _icn_league = nullptr;
	Icon * _icn_skilltree = nullptr;

	HudBack * _hud_back;
	// 빨간 버튼은 렌더를 할지, 말지 정할 수 있다.
	Button * _red_button;
	bool _fRedButton;
	// 냉장고 인벤토리
	Window * _inven_friger;
	bool _fInven_friger;
	// 리그 창
	Window * _window_league;
	// 리그에서 쓰는 게이지 클래스
	Gauge * _gauge;
	// 현재 UI에 무엇을 띄울 것인지 기준
	UI_TYPE _type = UI_NONE;
protected:
	void run_red_button();
	// Icons
	HRESULT init_icons();
	void delete_icons();
	void draw_icons();
	void update_icons();

	void update_league();
	void update_friger();
	// 게이지
	void init_gauges();
	void draw_gauges();
	void update_gauges();
	void delete_gauges();
public:
	void set_fRedButton(bool fResult) { _fRedButton = fResult; }
	void set_fInven_friger(bool fResult) { _fInven_friger = fResult; }
public:
	virtual HRESULT init();
	virtual HRESULT init(UI_TYPE type);
	virtual void release();
	virtual void update();
	virtual void render();
public:
	InGameUI();
	~InGameUI();
};
#define INGAME_UI	InGameUI::get_singleton()