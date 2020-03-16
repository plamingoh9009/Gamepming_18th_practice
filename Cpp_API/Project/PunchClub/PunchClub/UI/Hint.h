#pragma once
#include "UI.h"
class Hint: public UI
{
private:
	Image * _bg = nullptr;
	string _bg_fileName;
	Image * _corner_under = nullptr;
	Image * _corner_upper = nullptr;
	MyText _title;
	MyText _descr;
	bool _fPositionOK = false;
	bool _fCorner_upper = false;
protected:
	HRESULT init_imgs();
	void delete_imgs();
	void draw_imgs();
	void draw_texts();
	void update_imgPos();
	void update_textPos();
	void resize_bg();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Hint();
	~Hint();
public:
	void set_center(POINT center);
	void set_texts(string title, string descr);
};

