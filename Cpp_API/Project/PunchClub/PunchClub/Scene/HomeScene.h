#pragma once
#include "Scene.h"
#include "UI/InGameUI.h"
class HomeScene: public Scene
{
private:
	Image * _bg;
	// 가구, 가전용 변수
	// 요리하는 곳
	Image * _kitchenTable;
	RECT _kitchenTable_rc;
	POINT _kitchenTable_center;
	// 냉장고
	Image * _refrigerator;
	RECT _refrigerator_rc;
	POINT _refrigerator_center;
	// 스탠드
	Image * _stand;
	RECT _stand_rc;
	POINT _stand_center;
	// 소파
	Image * _sofa;
	RECT _sofa_rc;
	POINT _sofa_pos;
	// 수조
	Image * _fishTank;
	RECT _fishTank_rc;
	POINT _fishTank_pos;
	POINT _fishTank_center;
	Image * _fishTank_head;
	RECT _fishTank_head_rc;
	// TV
	Image * _tv;
	RECT _tv_rc;
	POINT _tv_pos;
	POINT _tv_center;
	// 천장 선풍기
	Image * _fan;
	RECT _fan_rc;
	POINT _fan_center;
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

protected:
	void init_furniture();
	void draw_furniture();
	void delete_furniture();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	HomeScene();
	~HomeScene();
};

