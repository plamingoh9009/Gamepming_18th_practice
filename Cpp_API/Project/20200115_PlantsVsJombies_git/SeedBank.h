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
	// 카드를 on, off 할때 쓰는 정보
	bool _fClickCard;
	string _cardType;
protected:
	void delete_plantImage();
	// 식물이름 벡터 함수
	void init_plantName();
	void delete_plantName();
	// 시드카드 맵 함수
	void draw_seedCards();
	void init_seedCards();
	void delete_seedCards();
public:
	map<string, SeedCard *> get_seedCards();
	map<string, SeedCard *>::iterator get_itSeedCards();
	void set_fClickCard(bool fResult) { _fClickCard = fResult; }
	void set_cardType(string cardType) { _cardType = cardType; }
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
