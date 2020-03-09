#pragma once
#include "Base/GameNode.h"
#include "Base/SingletonBase.h"
// UI
#include "Icon.h"
#include "HudBack.h"
#include "RedButton.h"
// 클릭했을 때
#include "Window.h"
class InGameUI: public GameNode, public SingletonBase<InGameUI>
{
private:
	// 오브젝트에 값을 넣기 위해서 필요하다
	Object * _obj;
private:
	Icon * _icons;
	HudBack * _hud_back;
	// 빨간 버튼은 렌더를 할지, 말지 정할 수 있다.
	RedButton * _red_button;
	bool _fRedButton;
	// 냉장고 인벤토리
	Window * _inven_friger;
	bool _fInven_friger;
	// 리그 창
	Window * _window_league;
protected:
	void run_red_button();
	void update_league();
	void update_friger();
public:
	void set_fRedButton(bool fResult) { _fRedButton = fResult; }
	void set_fInven_friger(bool fResult) { _fInven_friger = fResult; }
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	InGameUI();
	~InGameUI();
};
#define INGAME_UI	InGameUI::get_singleton()