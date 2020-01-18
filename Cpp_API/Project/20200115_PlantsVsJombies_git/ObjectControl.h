#pragma once
#include "Plant.h"
#include "Zombie.h"
class ObjectControl: public gameNode
{
private:
	typedef vector<Zombie *> vZombies_t;
	typedef vector<Plant *> vPlants_t;
	typedef map<string, RECT> mCardRects_t;
	typedef vector<RECT> vMapSpaces_t;
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
	mCardRects_t _cardRects;
	mCardRects_t::iterator _itCardRects;
	// UI���� �Ѱܹ��� ���� ���� RECT ����
	vMapSpaces_t _mapSpaces;
	vMapSpaces_t::iterator _itMapSpaces;
public:
	// ���� ��Ʈ��
	void make_zombie();
	void delete_zombies();
	void update_zombies();
	void draw_zombies();
	// UI ���� �������� ����
	void set_mapSpaces(vector<RECT>);
	void set_itMapSpaces(vector<RECT>::iterator);
	void set_cardRects(map<string, RECT>);
	void set_itCardRects(map<string, RECT>::iterator);
	// ����� ��� �Լ�
	void show_mouseRect();
	void make_mouseRect();
	void show_plantRects();
	// �Ĺ� ��Ʈ��
	void update_plants();
	void draw_plants();
	void delete_plants();
	void make_plant();
	// �Ĺ��� ������ ���� �Լ�
	void check_clickCard();
	void check_mapSpace();
	void check_spaceEmpty();
	void plant_plantToMap();
public:
	ObjectControl();
	~ObjectControl();
	HRESULT init();
	void release();
	void update();
	void render();
};

