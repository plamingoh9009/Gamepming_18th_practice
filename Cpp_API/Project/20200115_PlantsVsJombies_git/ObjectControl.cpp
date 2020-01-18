#include "stdafx.h"
#include "ObjectControl.h"

// ================================================
// **				���� ��Ʈ��					 **
// ================================================
void ObjectControl::make_zombie()
{
	Zombie * zombie = new Zombie;
	zombie->init();
	_zombies.push_back(zombie);
}
void ObjectControl::delete_zombies()
{
	_itZombies = _zombies.begin();
	for (;_itZombies != _zombies.end();)
	{
		(*_itZombies)->release();
		_zombies.erase(_itZombies++);
	}
	_zombies.clear();
}
void ObjectControl::update_zombies()
{
	_itZombies = _zombies.begin();
	for (;_itZombies != _zombies.end();_itZombies++)
	{
		(*_itZombies)->update();
	}
}
void ObjectControl::draw_zombies()
{
	_itZombies = _zombies.begin();
	for (;_itZombies != _zombies.end();_itZombies++)
	{
		(*_itZombies)->render();
	}
}

void ObjectControl::set_mapSpaces(vector<RECT> mapSpaces)
{
	_mapSpaces = mapSpaces;
}
void ObjectControl::set_itMapSpaces(vector<RECT>::iterator itMapSpaces)
{
	_itMapSpaces = itMapSpaces;
}
void ObjectControl::set_cardRects(map<string, RECT> rects)
{
	_cardRects = rects;
}
void ObjectControl::set_itCardRects(map<string, RECT>::iterator itRects)
{
	_itCardRects = itRects;
}

void ObjectControl::show_mouseRect()
{
	Rectangle(getMemDC(), _mouseRect.left, _mouseRect.top,
		_mouseRect.right, _mouseRect.bottom);
}
void ObjectControl::make_mouseRect()
{
	_mouseRect = RectMakeCenter(m_ptMouse.x, m_ptMouse.y, 5, 5);
}
void ObjectControl::show_plantRects()
{
	_itPlants = _plants.begin();
	for (;_itPlants != _plants.end();_itPlants++)
	{
		(*_itPlants)->show_plantRect();
	}
}

// ================================================
// **				�Ĺ� ��Ʈ��					 **
// ================================================
void ObjectControl::update_plants()
{
	_itPlants = _plants.begin();
	for (;_itPlants != _plants.end();_itPlants++)
	{
		(*_itPlants)->update();
	}
}
void ObjectControl::draw_plants()
{
	_itPlants = _plants.begin();
	for (;_itPlants != _plants.end();_itPlants++)
	{
		(*_itPlants)->render();
	}
}
void ObjectControl::delete_plants()
{
	_itPlants = _plants.begin();
	for (;_itPlants != _plants.end();)
	{
		(*_itPlants)->release();
		_plants.erase(_itPlants++);
	}
	_plants.clear();
}
void ObjectControl::make_plant()
{
	// �Ĺ� ��ü�� ����
	Plant * plant = new Plant;
	plant->init();
	plant->set_plant(_cardType, m_ptMouse.x, m_ptMouse.y);
	plant->set_fMouseFollow(true);
	// �Ĺ� ���Ϳ� ����
	_plants.push_back(plant);
	// �Ĺ� �����͸� ����.
	// �̷��� ��ü�� ���� ����.
	plant = nullptr;
}
void ObjectControl::check_clickCard()
{
	RECT temp;
	make_mouseRect();
	_itCardRects = _cardRects.begin();
	for (;_itCardRects != _cardRects.end();_itCardRects++)
	{
		if (IntersectRect(&temp, &_mouseRect, &_itCardRects->second))
		{
			_fClickCard = true;
			_cardType = _itCardRects->first;
		}//if: �� ���콺�� ī�带 ������
	}//for: �Ĺ� ���͸� ������.
}
void ObjectControl::check_mapSpace()
{
	make_mouseRect();
	RECT temp;
	_itMapSpaces = _mapSpaces.begin();
	for (;_itMapSpaces != _mapSpaces.end();_itMapSpaces++)
	{
		if (IntersectRect(&temp, &_mouseRect, &(*_itMapSpaces)))
		{
			_fMapSpace = true;
			_plantPoint = (*_itMapSpaces);
		}//if: ���� ������ ��ģ�ٸ� ���� ��ġ�� ����ش�.
	}//for: �������͸� ������.
}
void ObjectControl::check_spaceEmpty()
{
	// ������ �ʱ�ȭ�Ѵ�.
	_fPlantInSpace = false;
	// �Ĺ� ���͸� ��ġ�ؼ� _plantPoint�� ���Ѵ�.
	_itPlants = _plants.begin();
	for (;_itPlants != _plants.end();_itPlants++)
	{
		if ((*_itPlants)->is_plantInRect(_plantPoint) == true)
		{
			_fPlantInSpace = true;
		}//if: ���� �ڸ��� �Ĺ��� �ִٸ�
	}
}
void ObjectControl::plant_plantToMap()
{
	_itPlants = _plants.begin();
	for (;_itPlants != _plants.end();_itPlants++)
	{
		if ((*_itPlants)->get_fMouseFollow() == true)
		{
			//���� �ɴ´�.
			(*_itPlants)->set_fMouseFollow(false);
			// ��ġ�� ����ش�.
			(*_itPlants)->move_plant(_plantPoint.left, _plantPoint.top);
			(*_itPlants)->set_plantPoint(_plantPoint);
		}
	}
}

ObjectControl::ObjectControl()
{
}
ObjectControl::~ObjectControl()
{
}
HRESULT ObjectControl::init()
{
	_fClickCard = false;
	_fMakingPlant = false;
	_fMapSpace = false;
	_fPlantInSpace = false;
	_cardType = "";
	return S_OK;
}
void ObjectControl::release()
{
	delete_plants();
	IMAGEMANAGER->deleteImage("SunFlower");
	IMAGEMANAGER->deleteImage("Wallnut");
	IMAGEMANAGER->deleteImage("PeaShooter");
	// ���� ����
	delete_zombies();
	IMAGEMANAGER->deleteImage("Zombie");
}
void ObjectControl::update()
{
	// �Ĺ� ���͸� ������Ʈ �Ѵ�.
	update_plants();
	// ���� ���͸� ������Ʈ �Ѵ�.
	update_zombies();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		// ================================================
		// **			�Ĺ��� �����ϴ� �κ�				 **
		// ================================================
		check_clickCard();
		if (_fClickCard == true && _fMakingPlant == false)
		{
			make_plant();
			_fClickCard = false;
			// ��ü�� �����ߴٸ� �ٸ� ��ü�� �� ���������� ���Ѵ�.
			_fMakingPlant = true;
		}//if: ī�带 ������, �Ĺ��� ����� ���� �ƴ϶�� ��ü�� �����Ѵ�.

		// ================================================
		// **				�Ĺ��� �ɴ� �κ�				 **
		// ================================================
		if (_fMakingPlant == true)
		{
			check_mapSpace();
			check_spaceEmpty();
		}//if: �Ĺ��� ����� ���̶��

		if (_fMapSpace == true && _fMakingPlant == true)
		{
			if (_fPlantInSpace == false)
			{
				// �Ĺ��� ���� �ɴ´�.
				plant_plantToMap();
				// �ɰ��� �Ĺ��� ����� ���� �ƴϴ�.
				_fMakingPlant = false;
				// �ɰ��� �Ĺ��� ������ �����Ѵ�.
				_fPlantInSpace = true;
			}//if: ������ �Ĺ��� ���ٸ�
		}//if: ���� ���� �ְ�, �Ĺ��� �ɴ� ���̶��
	}//if: Ŭ���ϴ� ����.

	if (KEYMANAGER->isOnceKeyDown(0x30))
	{
		// ================================================
		// **			���� �����ϴ� �κ�				 **
		// ================================================
		make_zombie();
	}//if: 0���� ������ �� ���� �����.
	// ���콺 ��Ʈ�� �����.
	make_mouseRect();
}
void ObjectControl::render()
{
	draw_plants();
	draw_zombies();
	if (KEYMANAGER->isToggleKey(0x32))
	{
		show_plantRects();
		show_mouseRect();
	}
}
