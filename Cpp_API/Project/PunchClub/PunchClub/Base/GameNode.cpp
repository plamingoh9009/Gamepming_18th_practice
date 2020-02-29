#include "stdafx.h"
#include "Base/GameNode.h"

Image* GameNode::_backBuffer = NULL;
Image * GameNode::set_backBuffer()
{
	_backBuffer = new Image;
	_backBuffer->init(WINSIZEX, WINSIZEY);

	return _backBuffer;
}
HRESULT GameNode::init()
{
	_hdc = GetDC(m_hWnd);
	_fManagerInit = false;
	return S_OK;
}
HRESULT GameNode::init(bool managerInit)
{
	_hdc = GetDC(m_hWnd);
	_fManagerInit = managerInit;

	if (managerInit)
	{
		set_backBuffer();
		//SetTimer(m_hWnd, 1, 10, NULL);
		// 여기서 매니저 초기화
		TIMEMANAGER->init();
		SCENEMANAGER->init();
		KEYMANAGER->init();
	}

	return S_OK;
}
void GameNode::release()
{
	if (_fManagerInit)
	{
		//타이머 해제
		//KillTimer(m_hWnd, 1);
		// 여기서 매니저 해제. 1) release_singleton(), 2) 클래스 release()
		TIMEMANAGER->release_singleton();
		SCENEMANAGER->release_singleton();
		KEYMANAGER->release_singleton();

		TIMEMANAGER->release();
		SCENEMANAGER->release();
		KEYMANAGER->release();
	}
	ReleaseDC(m_hWnd, _hdc);
}
void GameNode::update() {}
void GameNode::render(HDC hdc) {}
void GameNode::render() {}
LRESULT GameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_MOUSEMOVE:
		m_ptMouse.x = LOWORD(lParam);
		m_ptMouse.y = HIWORD(lParam);
		break;
	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
GameNode::GameNode() {}
GameNode::~GameNode() {}