#pragma once
#include "Plant.h"
#include "Zombie.h"
class ObjectControl: public gameNode
{
private:
	typedef vector<Zombie *> vZombies_t;
	typedef vector<Plant *> vPlants_t;
	typedef vector<RECT> vRects_t;
	typedef map<string, RECT> mRects_t;
private:
	// 좀비 객체 벡터
	vZombies_t _zombies;
	vZombies_t::iterator _itZombies;
	// 식물 객체 벡터
	vPlants_t _plants;
	vPlants_t::iterator _itPlants;
	// 마우스의 위치 렉트
	RECT _mouseRect;
	
	// 식물을 심을 때 필요한 정보
	bool _fClickCard;
	bool _fMakingPlant;
	bool _fMapSpace;
	string _cardType;
	RECT _plantPoint;
	bool _fPlantInSpace;
	// UI에서 넘겨받은 카드 RECT 맵
	mRects_t _cardRects;
	mRects_t::iterator _itCardRects;
	// UI에서 넘겨받은 맵의 공간 RECT 벡터
	vRects_t _mapSpaces;
	vRects_t::iterator _itMapSpaces;
	// UI에서 받은 라인 RECT 벡터
	vRects_t _mapLines;
	vRects_t::iterator _itMapLines;
protected:
	// 좀비 컨트롤
	void make_zombie();
	void delete_zombiesAll();
	void delete_deadZombies();
	void update_zombies();
	void draw_zombies();
	// 식물 컨트롤
	void update_plants();
	void draw_plants();
	void delete_plantsAll();
	void delete_deadPlants();
	void make_plant();
	// 식물이 좀비 때릴 때 쓰는 함수
	bool is_zombiesAtSameLine(RECT plantPoint);
	RECT find_zombieDamagePoint(RECT plantPoint);
	void attack_plantToZombie(RECT plantPoint, int lostHp);
	// 좀비가 식물 때릴 때 쓰는 함수
	bool is_plantInAttackRange(RECT zombieRange);
	void attack_zombieToPlant(RECT zombiRange, int lostHp);
	// 식물을 심을때 쓰는 함수
	void check_clickCard();
	void check_mapSpace();
	void check_spaceEmpty();
	void plant_plantToMap();
	// 디버그 모드 함수
	void show_mouseRect();
	void make_mouseRect();
	void show_plantRects();
	void show_bulletHitPoints();
	void show_zombieRects();
	void show_zombieRectsForFight();
public:
	// UI에 넘겨줄 정보
	string get_cardType() { return _cardType; }
	bool get_fClickCard() { return _fClickCard; }
	// UI 에서 가져오는 정보
	void set_mapSpaces(vector<RECT>);
	void set_itMapSpaces(vector<RECT>::iterator);
	void set_mapLines(vector<RECT>);
	void set_itMapLines(vector<RECT>::iterator);
	void set_cardRects(map<string, RECT>);
	void set_itCardRects(map<string, RECT>::iterator);
public:
	ObjectControl();
	~ObjectControl();
	HRESULT init();
	void release();
	void update();
	void render();
};

