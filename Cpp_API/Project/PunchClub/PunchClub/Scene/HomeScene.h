#pragma once
#include "Scene.h"
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
	Image * _friger;
	RECT _friger_rc;
	POINT _friger_center;
	Image * _friger_select;
	// ���ĵ�
	Image * _stand;
	RECT _stand_rc;
	POINT _stand_center;
	// ����
	Image * _sofa;
	RECT _sofa_rc;
	POINT _sofa_pos;
	Image * _sofa_select;
	// ����
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
	// bool ����
	bool _fFriger = false;
	bool _fSofa = false;
	bool _fTv = false;
protected:
	void update_objectSelected();
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

