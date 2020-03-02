#pragma once
#include "Base/GameNode.h"
#include "Base/SingletonBase.h"
// UI
#include "Icon.h"
#include "HudBack.h"
#include "RedButton.h"
class InGameUI: public GameNode, public SingletonBase<InGameUI>
{
private:
	Icon * _icons;
	HudBack * _hud_back;
	// ���� ��ư�� ������ ����, ���� ���� �� �ִ�.
	RedButton * _red_button;
	bool _fRedButton = false;
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