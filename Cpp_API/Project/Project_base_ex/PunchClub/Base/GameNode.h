#pragma once
#include "Base/Image.h"
class GameNode
{
private:
	static Image * _backBuffer;		//백버퍼

	HDC _hdc;
	bool _fManagerInit;
public:
	virtual HRESULT init();
	virtual HRESULT init(bool managerInit);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	virtual void render();
	// 메인 프로시저
	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
public:
	GameNode();
	~GameNode();
public:
	static Image* set_backBuffer();
	//백버퍼 얻어오기
	Image* get_backBuffer() { return _backBuffer; }
	//추가(메모리 DC)
	HDC get_memDC() { return _backBuffer->get_memDC(); }
	//추가 HDC얻기
	HDC get_hdc() { return _hdc; }
};

