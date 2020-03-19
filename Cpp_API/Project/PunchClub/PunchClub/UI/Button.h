#pragma once
#include "UI.h"

class Button: public UI
{
private:
	BUTTON::TYPE _type;
	Image * _button = nullptr;
	BUTTON::ICON _iconType;
	Image * _icon = nullptr;
	// 텍스트
	MyText _text;
	bool _fText = false;
	// 윈도우 닫기
	bool _fCloseWindow = false;
protected:
	HRESULT init_red_button();
	// long red
	HRESULT init_long_red_button();
	void update_long_red_button();
	// Delete red
	HRESULT init_delete_red_button();
	void update_delete_red_button();
	// long green
	HRESULT init_long_green_button();
	void update_long_green_button();
	// Bus green
	HRESULT init_bus_green_button();
	void update_bus_green_button();
	// Green
	HRESULT init_green_button();
	void update_green_button();
	// Green inven
	HRESULT init_green_inven();
	void update_green_inven();
	// Text
	void draw_text_toButton();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Button(BUTTON::TYPE type);
	~Button();
	RECT get_rc() { return _button->get_rect(); }
	int get_width() { return _button->get_width(); }
	int get_height() { return _button->get_height(); }
	int get_icon_width() { return _icon->get_width(); }
	int get_icon_height() { return _icon->get_height(); }
	POINT get_center() { return _button->get_center(); }
	void set_text_toButton(string text, int size=25, MYTEXT::TYPE type = MYTEXT::TXT_TITLE);
	void set_icon_toButton(BUTTON::ICON type, POINT center);
	void set_center(POINT center);
	void set_pos_toRT_edge(RECT rc);
	bool is_closeWindow() { return _fCloseWindow; }
};

