#include "stdafx.h"
#include "GameLoad.h"

void GameLoad::set_indexMap()
{
	int distance = _player->get_distance_moved();
	int posInitX = _player->get_posInitX();
	int mapW = _map->get_sizeMap().x;

	if (distance < 0 - posInitX)
	{
		_indexMap = 0;
	}//if: 거리가 0이 되었을 때
	else if (distance > mapW)
	{
		_indexMap = (int)(distance / mapW);
	}//if: 거리가 맵의 끝이 되고, 맵 인덱스가 0보다 클 때
}

GameLoad::GameLoad()
{
}
GameLoad::~GameLoad()
{
}

HRESULT GameLoad::init()
{
	_loadIndex = LOAD_TITLE;

	// 타이틀 초기화
	_title = new Title;
	_title->init();

	// 맵 초기화
	_map = new Map;
	_map->init();
	_indexMap = 1;

	// 플레이어 초기화
	_player = new Player;
	_player->init(LOAD_STAGE1);

	// 링 초기화
	_fireRing = new FireRing;
	_fireRing->init();

	return S_OK;
}

void GameLoad::release()
{
	// 타이틀 해제
	_title->release();
	SAFE_DELETE(_title);

	// 링 해제
	_fireRing->release();
	SAFE_DELETE(_fireRing);

	// 맵 해제
	_map->release();
	SAFE_DELETE(_map);

	// 플레이어 해제
	_player->release();
	SAFE_DELETE(_player);
}

void GameLoad::update()
{
	switch (_loadIndex)
	{
	case LOAD_TITLE:
		_title->update();

		if (_title->get_fOffTitle() == true)
		{
			_loadIndex = LOAD_STAGE1;
		}
		break;
	case LOAD_STAGE1:
		_player->update(_indexMap);
		set_indexMap();

		// 링 업데이트
		_fireRing->update();

	default:
		_map->update();
		break;
	}
}

void GameLoad::render()
{
	switch (_loadIndex)
	{
	case LOAD_TITLE:
		_title->render();
		break;
	case LOAD_STAGE1:
		_map->render(_player->get_distance_moved());
		_fireRing->render(ID_BACK);
		_player->render();
		_fireRing->render(ID_FRONT);
	default:
		break;
	}
}
