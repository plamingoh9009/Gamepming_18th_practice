#pragma once
#include "UI.h"
enum BTN_TYPE
{
	BTN_NONE,
	BTN_RED,
	BTN_RED_LONG,
	BTN_BLUE_LONG
};
class Button: public UI
{
private:
	BTN_TYPE _type;
	Image * _red_button;
	// Long Red Button
	Image * _btn_red_long;
	// Long Blue Button
	Image * _btn_blue_long;
	// Icon
	Image * _del_icon;
	Image * _show_icon;
	// 위치
	RECT _button_rc;
	RECT _fore_rc;
	POINT _button_center;
	// 텍스트
	string _text = "";
	bool _fText = false;
	POINT _text_pos;
protected:
	void init_red_button();
	void init_red_button(int x, int y);
	void draw_red_button();
	void delete_red_button();
	// long red
	void init_long_red_button(POINT center);
	void draw_long_red_button();
	void update_long_red_button();
	void delete_long_red_button();
	// Text
	void draw_text_toButton();
public:
	virtual HRESULT init();
	virtual HRESULT init(BTN_TYPE type, int right, int top);
	virtual HRESULT init(BTN_TYPE type, POINT center);
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Button();
	~Button();
	RECT get_rc() { return _button_rc; }
	void set_text_toButton(string text);
};

