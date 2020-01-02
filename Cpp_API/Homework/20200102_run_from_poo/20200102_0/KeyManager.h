#pragma once
#include "singletonBase.h"
#include <bitset>
using namespace std;
#define KEYMAX 256
class KeyManager: public SingletonBase<KeyManager>
{
private:
	bitset<KEYMAX> _keyUp;
	bitset<KEYMAX> _keyDown;
public:
	HRESULT init();
	void release();
	bool isOnceKeyDown(int key);
	bool isOnceKeyUp(int key);
	// ������ �ִ���
	bool isStayKeyDown(int key);
	// ���Ű����
	bool isToggleKey(int key);
public:
	KeyManager();
	~KeyManager();
};

