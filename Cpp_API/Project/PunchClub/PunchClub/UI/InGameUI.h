#pragma once
#include "Base/GameNode.h"
#include "Base/SingletonBase.h"
// UI
#include "Icon.h"
#include "HudBack.h"
#include "Button.h"
// Ŭ������ ��
#include "Window.h"
// �ο� ��
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
	// ������Ʈ�� ���� �ֱ� ���ؼ� �ʿ��ϴ�
	Object * _obj;
private:
	Icon * _icons;
	HudBack * _hud_back;
	// ���� ��ư�� ������ ����, ���� ���� �� �ִ�.
	Button * _red_button;
	bool _fRedButton;
	// ����� �κ��丮
	Window * _inven_friger;
	bool _fInven_friger;
	// ���� â
	Window * _window_league;
	// ���׿��� ���� ������ Ŭ����
	Gauge * _gauge;
	// ���� UI�� ������ ��� ������ ����
	UI_TYPE _type = UI_NONE;
protected:
	void run_red_button();
	void update_league();
	void update_friger();
	// ������
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