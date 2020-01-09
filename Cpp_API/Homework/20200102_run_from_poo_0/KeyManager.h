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
	// 누르고 있는지
	bool isStayKeyDown(int key);
	// 토글키인지
	bool isToggleKey(int key);
public:
	KeyManager();
	~KeyManager();
};

