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
	}//if: �Ÿ��� 0�� �Ǿ��� ��
	else if (distance > mapW)
	{
		_indexMap = (int)(distance / mapW);
	}//if: �Ÿ��� ���� ���� �ǰ�, �� �ε����� 0���� Ŭ ��
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

	// Ÿ��Ʋ �ʱ�ȭ
	_title = new Title;
	_title->init();

	// �� �ʱ�ȭ
	_map = new Map;
	_map->init();
	_indexMap = 1;

	// �÷��̾� �ʱ�ȭ
	_player = new Player;
	_player->init(LOAD_STAGE1);

	// �� �ʱ�ȭ
	_fireRing = new FireRing;
	_fireRing->init();

	return S_OK;
}

void GameLoad::release()
{
	// Ÿ��Ʋ ����
	_title->release();
	SAFE_DELETE(_title);

	// �� ����
	_fireRing->release();
	SAFE_DELETE(_fireRing);

	// �� ����
	_map->release();
	SAFE_DELETE(_map);

	// �÷��̾� ����
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

		// �� ������Ʈ
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
