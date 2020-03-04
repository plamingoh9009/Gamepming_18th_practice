#pragma once
#include "UI.h"
class RedButton: public UI
{
private:
	Image * _red_button;
	RECT _red_button_rc;
	POINT _red_button_center;
	Image * _del_icon;
	RECT _del_icon_rc;
protected:
	void init_red_button();
	void init_red_button(int x, int y);
	void draw_red_button();
	void delete_red_button();
public:
	virtual HRESULT init();
	virtual HRESULT init(int right, int top);
	virtual void release();
	virtual void update();
	virtual void render();
public:
	RedButton();
	~RedButton();
	RECT get_rc() { return _red_button_rc; }
};

