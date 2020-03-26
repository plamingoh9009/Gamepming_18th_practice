#pragma once
#include "UI.h"
class Bead: public UI
{
private:
	BEAD::TYPE _type;
	Image * _img;
	POINT _dest;
	POINT _nextPos;
	// 구슬이 움직이기 위한 변수
	bool _fReverse;
	bool _fNextPos = false;
	bool _fDelete = false;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Bead();
	Bead(BEAD::TYPE type, bool isReverse = false);
	~Bead();
protected:
	HRESULT init_bead();
	void setup_bead_position();
	void move_toNext();
	void move_toDestination();
};

