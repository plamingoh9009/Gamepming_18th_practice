#pragma once
#include"image.h"
//����� �̹����� ����ƽ����..
static image * _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);

//�������� ����� �༮
enum CTRL
{
	CTRL_SAVE,
	CTRL_LOAD,
	CTRL_TERRAINDRAW,
	CTRL_OBJDRAW,
	CTRL_ERASER,
	CTRL_MAP1,
	CTRL_MAP2,
	CTRL_END
};

class gameNode
{
private:

	
	//void setBackBuffer();		//����� ����

	HDC _hdc;
	bool _managerInit;

public:
	gameNode();
	~gameNode();

	virtual HRESULT init();
	virtual HRESULT init(bool managerInit);
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);

	//������
	int _ctrSelect;
	void setCtrSelect(int num) { _ctrSelect = num; }

	virtual void setMap();
	virtual void save();
	virtual void load();




	//����� ��������
	image* getBackBuffer() { return _backBuffer; }

	HDC getHDC() { return _hdc; }
	
	HDC getMemDC() { return _backBuffer->getMemDC(); }

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

};

