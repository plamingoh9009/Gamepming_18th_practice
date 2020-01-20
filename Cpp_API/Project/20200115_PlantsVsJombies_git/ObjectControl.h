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
	// ���� ��ü ����
	vZombies_t _zombies;
	vZombies_t::iterator _itZombies;
	// �Ĺ� ��ü ����
	vPlants_t _plants;
	vPlants_t::iterator _itPlants;
	// ���콺�� ��ġ ��Ʈ
	RECT _mouseRect;
	
	// �Ĺ��� ���� �� �ʿ��� ����
	bool _fClickCard;
	bool _fMakingPlant;
	bool _fMapSpace;
	string _cardType;
	RECT _plantPoint;
	bool _fPlantInSpace;
	// UI���� �Ѱܹ��� ī�� RECT ��
	mRects_t _cardRects;
	mRects_t::iterator _itCardRects;
	// UI���� �Ѱܹ��� ���� ���� RECT ����
	vRects_t _mapSpaces;
	vRects_t::iterator _itMapSpaces;
	// UI���� ���� ���� RECT ����
	vRects_t _mapLines;
	vRects_t::iterator _itMapLines;
protected:
	// ���� ��Ʈ��
	void make_zombie();
	void delete_zombiesAll();
	void delete_deadZombies();
	void update_zombies();
	void draw_zombies();
	// �Ĺ� ��Ʈ��
	void update_plants();
	void draw_plants();
	void delete_plantsAll();
	void delete_deadPlants();
	void make_plant();
	// �Ĺ��� ���� ���� �� ���� �Լ�
	bool is_zombiesAtSameLine(RECT plantPoint);
	RECT find_zombieDamagePoint(RECT plantPoint);
	void attack_plantToZombie(RECT plantPoint, int lostHp);
	// ���� �Ĺ� ���� �� ���� �Լ�
	bool is_plantInAttackRange(RECT zombieRange);
	void attack_zombieToPlant(RECT zombiRange, int lostHp);
	// �Ĺ��� ������ ���� �Լ�
	void check_clickCard();
	void check_mapSpace();
	void check_spaceEmpty();
	void plant_plantToMap();
	// ����� ��� �Լ�
	void show_mouseRect();
	void make_mouseRect();
	void show_plantRects();
	void show_bulletHitPoints();
	void show_zombieRects();
	void show_zombieRectsForFight();
public:
	// UI�� �Ѱ��� ����
	string get_cardType() { return _cardType; }
	bool get_fClickCard() { return _fClickCard; }
	// UI ���� �������� ����
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

