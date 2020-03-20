#pragma once
#include "UI/Hint.h"
class Icon: public UI
{
private:
	ICON::TYPE _type;
	Image * _bg;
	Image * _fg;
	MyText _icon_txt;
	// ��Ʈ
	Hint * _hint;
	bool _fHint = false;
	// ���� �������� ��������
	bool _fLeague;
	// Fg Only
	bool _fFgOnly = false;
	bool _fIconText = false;
protected:
	void init_icons();
	void draw_icons();
	void delete_icons();
public:
	void draw_hint();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Icon(ICON::TYPE type);
	~Icon();
public:
	bool get_fLeague() { return _fLeague; }
	void set_fLeague(bool fResult) { _fLeague = fResult; }
	void set_center(POINT center);
	int get_width();
	int get_height();
	POINT get_center();
	bool get_fHint() { return _fHint; }
	void set_text_toIcon(string str, int size = 25, COLORREF color = RGB(254, 254, 254));
	string get_text_toIcon() { return _icon_txt.get_text(); }
};

