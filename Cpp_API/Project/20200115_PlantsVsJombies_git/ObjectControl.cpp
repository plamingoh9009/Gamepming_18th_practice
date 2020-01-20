#include "stdafx.h"
#include "ObjectControl.h"

// ================================================
// **				좀비 컨트롤					 **
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
// **				식물과 충돌체크				 **
// ================================================
		fPlantInAttackRange = is_plantInAttackRange(
			(*_itZombies)->get_zombieAttackRange());
// ================================================
// **				좀비가 식물 공격				 **
// ================================================
		if (fPlantInAttackRange == true)
		{
			(*_itZombies)->set_fPlantInRange(true);
			attack_zombieToPlant(
				(*_itZombies)->get_zombieAttackRange(),
				(*_itZombies)->get_lostPlantHp());
		}//if: 식물이 사정거리 안에 있다면
		else
		{
			// fPlantInRange를 초기화한다.
			(*_itZombies)->set_fPlantInRange(false);
		}//else: 식물이 사정거리 밖에 있다면
		if ((*_itZombies)->is_zombieAttack() == true)
		{
			// 좀비가 쌓은 데미지를 초기화한다.
			(*_itZombies)->init_lostPlantHp();
		}//if: 좀비가 공격을 했다면
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
// **			UI 정보 Setter 함수				 **
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
// **			디버그 모드 함수					 **
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
// **				식물 컨트롤					 **
// ================================================
void ObjectControl::update_plants()
{
	bool fResult;
	RECT temp;
	_itPlants = _plants.begin();
	for (;_itPlants != _plants.end();_itPlants++)
	{
		(*_itPlants)->update();
		// 라인에 좀비가 있는지 확인.
		fResult = is_zombiesAtSameLine((*_itPlants)->get_plantPoint());
		(*_itPlants)->set_fZombieAtSameLine(fResult);

		// 총알과 좀비 충돌검사는 Plant 객체가 한다.
		if ((*_itPlants)->get_fZombieAtSameLine() == true)
		{
			temp = find_zombieDamagePoint(
				(*_itPlants)->get_plantPoint());
			(*_itPlants)->set_zombieDamagePoint(temp);
		}//if: 라인에 좀비가 있다면

		// ================================================
		// **		총알과 좀비 충돌이후 처리				 **
		// ================================================
		if ((*_itPlants)->is_hitZombie() == true)
		{
			attack_plantToZombie((*_itPlants)->get_plantPoint(),
				(*_itPlants)->get_lostZombieHp());
			(*_itPlants)->init_lostZombieHp();
		}//if: 식물이 좀비를 때렸다면
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
	// 식물 객체를 생성
	Plant * plant = new Plant;
	plant->init();
	plant->init_plant(_cardType, m_ptMouse.x, m_ptMouse.y);
	plant->set_fMouseFollow(true);
	// 식물 벡터에 삽입
	_plants.push_back(plant);
	// 식물 포인터를 지움.
	// 이러면 객체는 남아 있음.
	plant = nullptr;
}
// ================================================
// **				식물이 좀비 때릴때				 **
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
	// 식물과 같은 라인에 있던 좀비 hp를 깎는다.
	_itZombies = _zombies.begin();
	for (;_itZombies != _zombies.end();_itZombies++)
	{
		if (plantPoint.top == (*_itZombies)->get_zombieDamagePoint().top)
		{
			// 때리고 루프를 탈출한다.
			(*_itZombies)->hit_zombie(lostHp);
			break;
		}//if: 식물과 같은 라인에 있는 좀비면
	}
}
// ================================================
// **				좀비가 식물 때릴때				 **
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
	}//else: 식물벡터가 존재할 때
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
		}//if: 좀비 공격거리 안에 있는 식물이라면
	}//for: 식물 서치
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
		}//if: 내 마우스가 카드를 누르면
	}//for: 식물 맵을 돌린다.
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
		}//if: 맵의 공간과 겹친다면 심을 위치를 잡아준다.
	}//for: 공간벡터를 돌린다.
}
void ObjectControl::check_spaceEmpty()
{
	// 변수를 초기화한다.
	_fPlantInSpace = false;
	// 식물 벡터를 서치해서 _plantPoint와 비교한다.
	_itPlants = _plants.begin();
	for (;_itPlants != _plants.end();_itPlants++)
	{
		if ((*_itPlants)->is_plantInRect(_plantPoint) == true)
		{
			_fPlantInSpace = true;
		}//if: 심을 자리에 식물이 있다면
	}
}
void ObjectControl::plant_plantToMap()
{
	_itPlants = _plants.begin();
	for (;_itPlants != _plants.end();_itPlants++)
	{
		if ((*_itPlants)->get_fMouseFollow() == true)
		{
			//땅에 심는다.
			(*_itPlants)->set_fMouseFollow(false);
			// 위치를 잡아준다.
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
	// 식물 해제
	delete_plantsAll();
	IMAGEMANAGER->deleteImage("SunFlower");
	IMAGEMANAGER->deleteImage("Wallnut");
	IMAGEMANAGER->deleteImage("PeaShooter");
	IMAGEMANAGER->deleteImage("PeaShooter_Attack");
	// 좀비 해제
	delete_zombiesAll();
	IMAGEMANAGER->deleteImage("Zombie");
}
void ObjectControl::update()
{
	// 식물 벡터를 업데이트 한다.
	update_plants();
	// 좀비 벡터를 업데이트 한다.
	update_zombies();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
// ================================================
// **			식물을 생성하는 부분				 **
// ================================================
		check_clickCard();
		if (_fClickCard == true && _fMakingPlant == false)
		{
			make_plant();
			_fClickCard = false;
			// 객체를 생성했다면 다른 객체를 또 생성하지는 못한다.
			_fMakingPlant = true;
		}//if: 카드를 눌렀고, 식물을 만드는 중이 아니라면 객체를 생성한다.

// ================================================
// **				식물을 심는 부분				 **
// ================================================
		if (_fMakingPlant == true)
		{
			check_mapSpace();
			check_spaceEmpty();
		}//if: 식물을 만드는 중이라면

		if (_fMapSpace == true && _fMakingPlant == true)
		{
			if (_fPlantInSpace == false)
			{
				// 식물을 땅에 심는다.
				plant_plantToMap();
				// 심고나면 식물을 만드는 중이 아니다.
				_fMakingPlant = false;
				// 심고나면 식물이 공간에 존재한다.
				_fPlantInSpace = true;
			}//if: 공간에 식물이 없다면
		}//if: 심을 땅이 있고, 식물을 심는 중이라면
	}//if: 클릭하는 순간.
	if (KEYMANAGER->isOnceKeyDown(0x30))
	{
// ================================================
// **			좀비를 생성하는 부분				 **
// ================================================
		make_zombie();
	}//if: 0번을 누르면 새 좀비를 만든다.
	// 죽은 식물을 지운다.
	delete_deadPlants();
	// 죽은 좀비를 지운다.
	delete_deadZombies();
	// 마우스 렉트를 만든다.
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
	}//if: 2번을 누르면
	if (KEYMANAGER->isToggleKey(0x33))
	{
		//show_zombieRects();
		show_zombieRectsForFight();
	}
}
