#pragma once
#include "UI/Hint.h"
class Icon: public UI
{
private:
	Image * _bg;
	Image * _fg;
	ICON::TYPE _type;
	// ��Ʈ
	Hint * _hint;
	bool _fHint = false;
	// ���� �������� ��������
	bool _fLeague;
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
	Icon();
	Icon(ICON::TYPE type);
	~Icon();
public:
	bool get_fLeague() { return _fLeague; }
	void set_fLeague(bool fResult) { _fLeague = fResult; }
	void set_center(POINT center);
	int get_width() { return _bg->get_width(); }
	int get_height() { return _bg->get_height(); }
	POINT get_center() { return _bg->get_center(); }
	bool get_fHint() { return _fHint; }
};

