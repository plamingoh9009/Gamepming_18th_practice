#pragma once
#include "gameNode.h"
#include "SeedCard.h"			
class SeedBank: public gameNode
{
private:
	typedef vector<string> vPlantName_t;
	typedef map<string, SeedCard *> mSeedCards_t;
private:
	image * _img;
	RECT _rect;
	// 시드뱅크의 유효공간 렉트
	RECT _space[6];
	// 식물 이름 벡터
	vPlantName_t _plantName;
	vPlantName_t::iterator _itPlantName;
	// 시드카드 맵
	mSeedCards_t _seedCards;
	mSeedCards_t::iterator _itSeedCards;

public:
	map<string, SeedCard *> get_seedCards();
	map<string, SeedCard *>::iterator get_itSeedCards();

	void delete_plantImage();
	void init_plantName();
	void delete_plantName();

	void draw_seedCards();
	void init_seedCards();
	void delete_seedCards();

	void show_space();
	void init_space();
public:
	SeedBank();
	~SeedBank();
	HRESULT init();
	void release();
	void update();
	void render();
};
