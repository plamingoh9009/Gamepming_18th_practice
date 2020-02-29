#pragma once
#include "Base/Image.h"

class GameNode
{
private:
	static Image * _backBuffer;		//�����
	HDC _hdc;
	bool _fManagerInit;
protected:
	// ���ӿ��� ����� �̹��� ���
	string _imgPath = "Images/";
	// ����� ��带 ���� ����
	static bool _fDebug;
protected:
	void update_checkDebugMode();
	// append: "Images/[append]"
	void set_imgPath(string append = "");
public:
	virtual HRESULT init();
	virtual HRESULT init(bool managerInit);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	virtual void render();
	// ���� ���ν���
	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
public:
	GameNode();
	~GameNode();
public:
	static Image* set_backBuffer();
	//����� ������
	Image* get_backBuffer() { return _backBuffer; }
	//�߰�(�޸� DC)
	HDC get_memDC() { return _backBuffer->get_memDC(); }
	//�߰� HDC���
	HDC get_hdc() { return _hdc; }
};

