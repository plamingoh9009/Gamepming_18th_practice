#pragma once
#include "Scene.h"
class HomeScene: public Scene
{
private:
	Image * _bg;
	Image * _ceil;
	// 가구, 가전용 변수
	// 요리하는 곳
	Image * _kitchenTable;
	// 냉장고
	Image * _friger;
	RECT _friger_rc;
	POINT _friger_center;
	Image * _friger_select;
	// 스탠드
	Image * _stand;
	RECT _stand_rc;
	POINT _stand_center;
	// 소파
	Image * _sofa;
	RECT _sofa_rc;
	POINT _sofa_pos;
	POINT _sofa_center;
	Image * _sofa_select;
	Image * _sofa_sleep;	// 잠자는 이미지
	RECT _sofa_sleep_rc;
	// 수조
	Image * _aquarium;
	RECT _aquarium_rc;
	POINT _aquarium_pos;
	POINT _aquarium_center;
	Image * _aquarium_fg;
	RECT _aquarium_fg_rc;
	// TV
	Image * _tv;
	RECT _tv_rc;
	POINT _tv_pos;
	POINT _tv_center;
	Image * _tv_select;
	Image * _tv_watch;
	RECT _tv_watch_rc;
	// 천장 선풍기
	Image * _fan;
	// 식탁
	Image * _table;
	RECT _table_rc;
	POINT _table_center;
	// 책장
	Image * _bookshelf;
	RECT _bookshelf_rc;
	POINT _bookshelf_center;
	POINT _bookshelf_pos;
	// 시계
	Image * _clock;
	RECT _clock_rc;
	POINT _clock_center;
	POINT _clock_pos;
	// 전화기
	Image * _phone;
	RECT _phone_rc;
	POINT _phone_center;
	// bool 변수
	bool _fFriger = false;
	bool _fSofa = false;
	bool _fSleep = false;
	bool _fTv = false;
	bool _fWatch = false;
protected:
	void update_objectSelected();
	void done_action();
protected:
	void init_furniture();
	void draw_furniture();
	void delete_furniture();
	void draw_rects();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	HomeScene();
	~HomeScene();
};

