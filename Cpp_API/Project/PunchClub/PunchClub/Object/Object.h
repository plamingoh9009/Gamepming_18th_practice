#pragma once
#include "Base/GameNode.h"
class Object: public GameNode
{
protected:
	static bool _fObjMove;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);
public:
	Object();
	~Object();
public:
	bool get_fObjMove() { return _fObjMove; }
	void set_fObjMove(bool fResult) { _fObjMove = fResult; }
};

