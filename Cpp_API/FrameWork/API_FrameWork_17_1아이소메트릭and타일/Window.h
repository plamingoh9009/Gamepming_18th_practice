#pragma once
#include "singletonBase.h"

#define SUBWINSIZEX 240
#define SUBWINSIZEY 600

enum CTRL
{
	CTRL_DRAW,
	CTRL_ERASER,
	CTRL_INIT,
	CTRL_SAVE,
	CTRL_LOAD,
	CTRL_NUM1,
	CTRL_NUM2,
	CTRL_NUM3,
	CTRL_END
};


class IsoMap;
class Window :public singletonBase<Window>
{
private:

	HWND hWnd;
	static POINT ptMouse;

	image* m_backBuffer;
	gameNode* currentScene;


	HWND _btnDraw;
	HWND _btnEraser;
	HWND _btnInit;

	HWND _btnSave;
	HWND _btnLoad;

	HWND  _btnN1;
	HWND  _btnN2;
	HWND  _btnN3;

	static CTRL _currentCTRL;
	POINT clickFrame;
	int clickIndex;

	bool isActive;

	IsoMap * map;
public:
	Window();
	~Window();

	void init();
	void release();
	void update();
	void render();

	void SetScene(gameNode* scene);

	static LRESULT CALLBACK WndLogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


	HWND GetHwnd() { return hWnd; }

	static POINT GetMousePos() { return ptMouse; }


	static CTRL GetCTRL() { return _currentCTRL; }
	void SetCTRL(CTRL ctrl) { _currentCTRL = ctrl; }

	void SetIsActive(bool isActive) { this->isActive = isActive; }
	bool GetIsActive() { return isActive; }

	void SetFramePoint(POINT frame) { clickFrame = frame; }
	POINT GetFramePoint() { return clickFrame; }

	void SetFrameIndex(int index) { clickIndex = index; }
	int GetFrameIndex() { return clickIndex; }


	void SetIsoMap(IsoMap* map) { this->map = map; }
	IsoMap* GetIsoMap() { return map; }


	void CreateSubWindow();


};

