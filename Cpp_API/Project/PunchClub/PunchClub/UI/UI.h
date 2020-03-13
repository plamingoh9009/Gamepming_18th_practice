#pragma once
#include "MyText.h"
#include "Object/Object.h"
class UI: public GameNode
{
protected:
	Object * _obj;	// 플레이어와 값을 공유할 오브젝트 클래스다.
	// 맵 씬에서 공유하는 아이콘 정보다.
	static MAPICON::TYPE _mapIcon_on;
	
	static POINT _playerIcon_center;	// UI 에서 공유하는 플레이어 아이콘의 좌표다.
	static bool _fplayerIcon_move;		// UI 에서 공유하는 플레이어 렌더를 업데이트 할지 말지 결정한다.
	static MAPICON::TYPE _playerIcon_location;	// UI 에서 공유하는 플레이어 아이콘 위치다.
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	UI();
	~UI();
};

