#pragma once
#include "Base/GameNode.h"
#include "Base/SingletonBase.h"
// UI
#include "Icon.h"
#include "HudBack.h"
#include "RedButton.h"
// Ŭ������ ��
#include "Window.h"
class InGameUI: public GameNode, public SingletonBase<InGameUI>
{
private:
	// ������Ʈ�� ���� �ֱ� ���ؼ� �ʿ��ϴ�
	Object * _obj;
private:
	Icon * _icons;
	HudBack * _hud_back;
	// ���� ��ư�� ������ ����, ���� ���� �� �ִ�.
	RedButton * _red_button;
	bool _fRedButton;
	// ����� �κ��丮
	Window * _inven_friger;
	bool _fInven_friger;
	// ���� â
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