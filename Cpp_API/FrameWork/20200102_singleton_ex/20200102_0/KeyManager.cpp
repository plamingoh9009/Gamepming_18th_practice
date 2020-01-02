#include "stdafx.h"
#include "KeyManager.h"


HRESULT KeyManager::init()
{
	// 키가 전부 눌려있지 않은 상태로 초기화한다.
	for (int i = 0; i < KEYMAX; i++)
	{
		_keyUp.set(i, false);
		_keyDown.set(i, false);
	}
	return S_OK;
}

void KeyManager::release()
{
}

bool KeyManager::isOnceKeyDown(int key)
{
	// GetAsyncKeyState: 현재 키의 상태를 알아오는 함수
	// 키가 눌렸을때, 떨어졌을 때 호출된다.
	// 0x8000: 이전에는 누른적이 없고 호출시점에서 누른 상태
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (!_keyDown[key])
		{
			_keyDown.set(key, true);
			return true;
		}
	}
	else
	{
		_keyDown.set(key, false);
	}
	return false;
}

bool KeyManager::isOnceKeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		_keyUp.set(key, true);
	}
	else
	{
		if (_keyUp[key])
		{
			_keyUp.set(key, false);
			return true;
		}
	}
	return false;
}

bool KeyManager::isStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000) return true;
	return false;
}

bool KeyManager::isToggleKey(int key)
{
	// GetKeyState: 현재 키의 토글상태
	// 0x0001: 이전에 누른 적이 있고 호출시점에서 누른 상태
	if (GetKeyState(key) & 0x0001) return true;
	return false;
}

KeyManager::KeyManager()
{
}


KeyManager::~KeyManager()
{
}
