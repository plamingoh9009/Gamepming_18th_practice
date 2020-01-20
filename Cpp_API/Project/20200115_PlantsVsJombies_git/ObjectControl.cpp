#include "stdafx.h"
#include "ObjectControl.h"

// ================================================
// **				���� ��Ʈ��					 **
// ================================================
void ObjectControl::make_zombie()
{
	Zombie * zombie = new Zombie;
	zombie->init();
	zombie->init_zombiePosition(_mapLines);
	_zombies.push_back(zombie);
}
void ObjectControl::delete_zombiesAll()
{
	_itZombies = _zombies.begin();
	for (;_itZombies != _zombies.end();)
	{
		(*_itZombies)->release();
		_zombies.erase(_itZombies++);
	}
	_zombies.clear();
}
void ObjectControl::delete_deadZombies()
{
	_itZombies = _zombies.begin();
	for (;_itZombies != _zombies.end();)
	{
		if ((*_itZombies)->is_deadZombie() == true)
		{
			(*_itZombies)->release();
			_itZombies = _zombies.erase(_itZombies);
		}
		else
		{
			_itZombies++;
		}
	}
}
void ObjectControl::update_zombies()
{
	bool fPlantInAttackRange = false;
	_itZombies = _zombies.begin();
	for (;_itZombies != _zombies.end();_itZombies++)
	{
		(*_itZombies)->update();
// ================================================
// **				�Ĺ��� �浹üũ				 **
// ================================================
		fPlantInAttackRange = is_plantInAttackRange(
			(*_itZombies)->get_zombieAttackRange());
// ================================================
// **				���� �Ĺ� ����				 **
// ================================================
		if (fPlantInAttackRange == true)
		{
			(*_itZombies)->set_fPlantInRange(true);
			attack_zombieToPlant(
				(*_itZombies)->get_zombieAttackRange(),
				(*_itZombies)->get_lostPlantHp());
		}//if: �Ĺ��� �����Ÿ� �ȿ� �ִٸ�
		else
		{
			// fPlantInRange�� �ʱ�ȭ�Ѵ�.
			(*_itZombies)->set_fPlantInRange(false);
		}//else: �Ĺ��� �����Ÿ� �ۿ� �ִٸ�
		if ((*_itZombies)->is_zombieAttack() == true)
		{
			// ���� ���� �������� �ʱ�ȭ�Ѵ�.
			(*_itZombies)->init_lostPlantHp();
		}//if: ���� ������ �ߴٸ�
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
// ================================================
// **			UI ���� Setter �Լ�				 **
// ================================================
void ObjectControl::set_mapSpaces(vector<RECT> mapSpaces)
{
	_mapSpaces = mapSpaces;
}
void ObjectControl::set_itMapSpaces(vector<RECT>::iterator itMapSpaces)
{
	_itMapSpaces = itMapSpaces;
}
void ObjectControl::set_mapLines(vector<RECT> mapLines)
{
	_mapLines = mapLines;
}
void ObjectControl::set_itMapLines(vector<RECT>::iterator itMapLines)
{
	_itMapLines = itMapLines;
}
void ObjectControl::set_cardRects(map<string, RECT> rects)
{
	_cardRects = rects;
}
void ObjectControl::set_itCardRects(map<string, RECT>::iterator itRects)
{
	_itCardRects = itRects;
}
// ================================================
// **			����� ��� �Լ�					 **
// ================================================
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
void ObjectControl::show_bulletHitPoints()
{
	_itPlants = _plants.begin();
	for (;_itPlants != _plants.end();_itPlants++)
	{
		(*_itPlants)->show_bulletHitPoints();
	}
}
void ObjectControl::show_zombieRects()
{
	_itZombies = _zombies.begin();
	for (;_itZombies != _zombies.end(); _itZombies++)
	{
		(*_itZombies)->show_zombieRect();
	}
}
void ObjectControl::show_zombieRectsForFight()
{
	_itZombies = _zombies.begin();
	for (;_itZombies != _zombies.end(); _itZombies++)
	{
		(*_itZombies)->show_zombieHitPoint();
		(*_itZombies)->show_zombieAttackRange();
	}
}
// ================================================
// **				�Ĺ� ��Ʈ��					 **
// ================================================
void ObjectControl::update_plants()
{
	bool fResult;
	RECT temp;
	_itPlants = _plants.begin();
	for (;_itPlants != _plants.end();_itPlants++)
	{
		(*_itPlants)->update();
		// ���ο� ���� �ִ��� Ȯ��.
		fResult = is_zombiesAtSameLine((*_itPlants)->get_plantPoint());
		(*_itPlants)->set_fZombieAtSameLine(fResult);

		// �Ѿ˰� ���� �浹�˻�� Plant ��ü�� �Ѵ�.
		if ((*_itPlants)->get_fZombieAtSameLine() == true)
		{
			temp = find_zombieDamagePoint(
				(*_itPlants)->get_plantPoint());
			(*_itPlants)->set_zombieDamagePoint(temp);
		}//if: ���ο� ���� �ִٸ�

		// ================================================
		// **		�Ѿ˰� ���� �浹���� ó��				 **
		// ================================================
		if ((*_itPlants)->is_hitZombie() == true)
		{
			attack_plantToZombie((*_itPlants)->get_plantPoint(),
				(*_itPlants)->get_lostZombieHp());
			(*_itPlants)->init_lostZombieHp();
		}//if: �Ĺ��� ���� ���ȴٸ�
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
void ObjectControl::delete_plantsAll()
{
	_itPlants = _plants.begin();
	for (;_itPlants != _plants.end();)
	{
		(*_itPlants)->release();
		_plants.erase(_itPlants++);
	}
	_plants.clear();
}
void ObjectControl::delete_deadPlants()
{
	_itPlants = _plants.begin();
	for (;_itPlants != _plants.end();)
	{
		if ((*_itPlants)->is_deadPlant() == true)
		{
			(*_itPlants)->release();
			_itPlants = _plants.erase(_itPlants);
		}
		else
		{
			_itPlants++;
		}
	}
}
void ObjectControl::make_plant()
{
	// �Ĺ� ��ü�� ����
	Plant * plant = new Plant;
	plant->init();
	plant->init_plant(_cardType, m_ptMouse.x, m_ptMouse.y);
	plant->set_fMouseFollow(true);
	// �Ĺ� ���Ϳ� ����
	_plants.push_back(plant);
	// �Ĺ� �����͸� ����.
	// �̷��� ��ü�� ���� ����.
	plant = nullptr;
}
// ================================================
// **				�Ĺ��� ���� ������				 **
// ================================================
bool ObjectControl::is_zombiesAtSameLine(RECT plantPoint)
{
	_itZombies = _zombies.begin();
	for (;_itZombies != _zombies.end();_itZombies++)
	{
		if (plantPoint.top == (*_itZombies)->get_zombieDamagePoint().top)
		{
			return true;
		}
	}
	return false;
}
RECT ObjectControl::find_zombieDamagePoint(RECT plantPoint)
{
	_itZombies = _zombies.begin();
	for (;_itZombies != _zombies.end();_itZombies++)
	{
		if (plantPoint.top == (*_itZombies)->get_zombieDamagePoint().top)
		{
			return (*_itZombies)->get_zombieDamagePoint();
		}
	}
	return RECT();
}
void ObjectControl::attack_plantToZombie(RECT plantPoint, int lostHp)
{
	// �Ĺ��� ���� ���ο� �ִ� ���� hp�� ��´�.
	_itZombies = _zombies.begin();
	for (;_itZombies != _zombies.end();_itZombies++)
	{
		if (plantPoint.top == (*_itZombies)->get_zombieDamagePoint().top)
		{
			// ������ ������ Ż���Ѵ�.
			(*_itZombies)->hit_zombie(lostHp);
			break;
		}//if: �Ĺ��� ���� ���ο� �ִ� �����
	}
}
// ================================================
// **				���� �Ĺ� ������				 **
// ================================================
bool ObjectControl::is_plantInAttackRange(RECT zombieRange)
{
	_itPlants = _plants.begin();
	if (_plants.empty() == true) { return false; }
	else
	{
		for (;_itPlants != _plants.end();_itPlants++)
		{
			if (IntersectRect(&RECT(), &zombieRange,
				&(*_itPlants)->get_plantPoint()))
			{
				return true;
			}
		}
	}//else: �Ĺ����Ͱ� ������ ��
	return false;
}
void ObjectControl::attack_zombieToPlant(RECT zombiRange, int lostHp)
{
	RECT plantPoint;
	_itPlants = _plants.begin();
	for (;_itPlants != _plants.end();_itPlants++)
	{
		plantPoint = (*_itPlants)->get_plantPoint();
		if (IntersectRect(&RECT(), &zombiRange, &plantPoint))
		{
			(*_itPlants)->hit_plant(lostHp);
			break;
		}//if: ���� ���ݰŸ� �ȿ� �ִ� �Ĺ��̶��
	}//for: �Ĺ� ��ġ
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
	}//for: �Ĺ� ���� ������.
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
	// �Ĺ� ����
	delete_plantsAll();
	IMAGEMANAGER->deleteImage("SunFlower");
	IMAGEMANAGER->deleteImage("Wallnut");
	IMAGEMANAGER->deleteImage("PeaShooter");
	IMAGEMANAGER->deleteImage("PeaShooter_Attack");
	// ���� ����
	delete_zombiesAll();
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
	// ���� �Ĺ��� �����.
	delete_deadPlants();
	// ���� ���� �����.
	delete_deadZombies();
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
		show_bulletHitPoints();
		show_mouseRect();
	}//if: 2���� ������
	if (KEYMANAGER->isToggleKey(0x33))
	{
		//show_zombieRects();
		show_zombieRectsForFight();
	}
}
