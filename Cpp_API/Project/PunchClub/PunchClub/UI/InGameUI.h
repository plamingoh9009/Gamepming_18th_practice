#pragma once
#include "Base/GameNode.h"
#include "Base/SingletonBase.h"
// UI
#include "Icon.h"
#include "HudBack.h"
#include "RedButton.h"
// 클릭했을 때
#include "Inventory.h"
class InGameUI: public GameNode, public SingletonBase<InGameUI>
{
private:
	Icon * _icons;
	HudBack * _hud_back;
	// 빨간 버튼은 렌더를 할지, 말지 정할 수 있다.
	RedButton * _red_button;
	bool _fRedButton;
	// 냉장고 인벤토리
	Inventory * _inven_friger;
	bool _fInven_friger;
	// 다른 업데이트를 정지할지 말지
	bool _fUI_on = false;
protected:
	void run_red_button();
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