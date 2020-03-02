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
	void draw_red_button();
	void delete_red_button();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	RedButton();
	~RedButton();
};

