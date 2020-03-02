#pragma once
#include "Scene.h"
#include "UI/InGameUI.h"
class HomeScene: public Scene
{
private:
	Image * _bg;
	// ����, ������ ����
	// �丮�ϴ� ��
	Image * _kitchenTable;
	RECT _kitchenTable_rc;
	POINT _kitchenTable_center;
	// �����
	Image * _refrigerator;
	RECT _refrigerator_rc;
	POINT _refrigerator_center;
	// ���ĵ�
	Image * _stand;
	RECT _stand_rc;
	POINT _stand_center;
	// ����
	Image * _sofa;
	RECT _sofa_rc;
	POINT _sofa_pos;
	// ����
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
	// õ�� ��ǳ��
	Image * _fan;
	RECT _fan_rc;
	POINT _fan_center;
	// ��Ź
	Image * _table;
	RECT _table_rc;
	POINT _table_center;
	// å��
	Image * _bookshelf;
	RECT _bookshelf_rc;
	POINT _bookshelf_center;
	POINT _bookshelf_pos;
	// �ð�
	Image * _clock;
	RECT _clock_rc;
	POINT _clock_center;
	POINT _clock_pos;
	// ��ȭ��
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

