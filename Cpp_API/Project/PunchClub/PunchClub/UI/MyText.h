#pragma once
#include "Base/GameNode.h"
#include "uiEnum.h"
class MyText: public GameNode
{
private:
	MYTEXT::TYPE _type;
	string _text = "";
	string _font;
	int _size;
	POINT _pos;
	COLORREF _color;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
public:
	MyText(); 
	MyText(MYTEXT::TYPE type, string text, COLORREF color = NULL);
	~MyText();
public:
	void set_pos(POINT pos) { _pos = pos; }
	POINT get_pos() { return _pos; }
	void set_size(int size) { _size = size; }
	void set_font(string font) { _font = font; }
};

