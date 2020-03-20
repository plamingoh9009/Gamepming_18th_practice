#pragma once
#include "MyText.h"
#include "Object/Object.h"
class UI: public GameNode
{
protected:
	Object * _obj;	// �÷��̾�� ���� ������ ������Ʈ Ŭ������.
	
	static POINT _playerIcon_center;	// UI ���� �����ϴ� �÷��̾� �������� ��ǥ��.
	static bool _fplayerIcon_move;		// UI ���� �����ϴ� �÷��̾� ������ ������Ʈ ���� ���� �����Ѵ�.
	static MAPICON::TYPE _playerIcon_location;	// UI ���� �����ϴ� �÷��̾� ������ ��ġ��.
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	UI();
	~UI();
};

