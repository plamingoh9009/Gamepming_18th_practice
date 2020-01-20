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
	// �õ��ũ�� ��ȿ���� ��Ʈ
	RECT _space[6];
	// �Ĺ� �̸� ����
	vPlantName_t _plantName;
	vPlantName_t::iterator _itPlantName;
	// �õ�ī�� ��
	mSeedCards_t _seedCards;
	mSeedCards_t::iterator _itSeedCards;
	// ī�带 on, off �Ҷ� ���� ����
	bool _fClickCard;
	string _cardType;
protected:
	void delete_plantImage();
	// �Ĺ��̸� ���� �Լ�
	void init_plantName();
	void delete_plantName();
	// �õ�ī�� �� �Լ�
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
